#!/usr/bin/env python
#
# @file    GenericAttributeFunctions.py
# @brief   class to create generic functions to get/set attributes/elements
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2015 by the California Institute of Technology
# (California, USA), the European Bioinformatics Institute (EMBL-EBI, UK)
# and the University of Heidelberg (Germany), with support from the National
# Institutes of Health (USA) under grant R01GM070923.  All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
# Neither the name of the California Institute of Technology (Caltech), nor
# of the European Bioinformatics Institute (EMBL-EBI), nor of the University
# of Heidelberg, nor the names of any contributors, may be used to endorse
# or promote products derived from this software without specific prior
# written permission.
# ------------------------------------------------------------------------ -->

from util import strFunctions, query, global_variables


class GenericAttributeFunctions():
    """Class for all functions for set/get/isset/unset"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object, writing_test=False):
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
        if class_object['name'].startswith('SBML'):
            self.class_name = class_object['name'][4:]
        else:
            self.class_name = class_object['name']
        self.base_class = class_object['baseClass']
        if not writing_test:
            self.language = language
            self.cap_language = language.upper()
            self.package = class_object['package']
            if is_list_of:
                self.child_name = class_object['lo_child']
            else:
                self.child_name = ''
            if is_cpp_api:
                self.object_name = self.class_name
                self.object_child_name = self.child_name
            else:
                if is_list_of:
                    self.object_name = 'ListOf_t'
                else:
                    self.object_name = self.class_name + '_t'
                self.object_child_name = self.child_name + '_t'

            self.attributes = class_object['class_attributes']
            self.classroot = None
            if 'root' in class_object:
                self.classroot = class_object['root']
            self.elements = query.get_child_elements(class_object['child_elements'], class_object['child_lo_elements'],
                                                     self.classroot)
            self.single_elements = query.get_child_elements(class_object['child_elements'], [], self.classroot)
            self.lo_elements = query.get_child_elements([], class_object['child_lo_elements'], self.classroot)

            if 'num_versions' in class_object and class_object['num_versions'] > 1:
                self.has_multiple_versions = True
            else:
                self.has_multiple_versions = False

            self.document = False
            if 'document' in class_object:
                self.document = class_object['document']

            # useful variables
            if not self.is_cpp_api and self.is_list_of:
                self.struct_name = self.object_child_name
            else:
                self.struct_name = self.object_name
            if self.is_cpp_api is False:
                self.true = '@c 1'
                self.false = '@c 0'
            else:
                self.true = '@c true'
                self.false = '@c false'
            self.plural = strFunctions.plural(self.child_name)
            self.indef_name = strFunctions.get_indefinite(self.object_child_name)
            self.abbrev_parent = strFunctions.abbrev_name(self.object_name)
            self.abbrev_child = strFunctions.abbrev_name(self.child_name)
            self.is_header = True
            if 'is_header' in class_object:
                self.is_header = class_object['is_header']
            self.is_plugin = False
            if 'is_plugin' in class_object:
                self.is_plugin = class_object['is_plugin']

        self.open_br = '{'
        self.close_br = '}'

        self.success = global_variables.ret_success
        self.failed = global_variables.ret_failed
        self.invalid_att = global_variables.ret_invalid_att
        self.invalid_obj = global_variables.ret_invalid_obj
        self.tests = []
    ########################################################################
    # Functions for writing get functions

    # function to write get functions
    def write_get(self, attributes, att_type):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Gets the value of the "attributeName" attribute of this {0}.' \
            .format(self.class_name)
        params.append('@param attributeName, the name of the attribute to retrieve.')
        params.append('@param value, the address of the value to record.')

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @{0}constant{1}{2}, '
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.success, self.close_br))
        return_lines.append('@li @{0}constant{1}{2},'
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.failed, self.close_br))

        # create the function declaration
        function = 'getAttribute'
        return_type = 'int'


        arg1 = '{0}& value'.format(att_type)
        end_get = '()'
        if att_type == 'const char*':
            arg1 = '{0} value'.format(att_type)
            end_get = '().c_str()'
        arguments = ['const std::string& attributeName', arg1]

        # create the function implementation
        first_line = ['int return_value = {0}::getAttribute(attributeName, value)'.format(self.base_class)]
        first_if = ['return_value == {0}'.format(global_variables.ret_success), 'return return_value']
        last_line = ['return return_value']
        first = True
        block = []
        for attrib in attributes:
            if not first:
                block.append('else if')
            else:
                first = False
            block.append('attributeName == \"{0}\"'.format(attrib['name']))
            if attrib['attType'] == 'enum':
                lines = ['value = get{0}AsString{1}'.format(attrib['capAttName'],end_get),
                         'return_value = {0}'.format(global_variables.ret_success)]
            else:
                lines = ['value = get{0}{1}'.format(attrib['capAttName'],end_get),
                         'return_value = {0}'.format(global_variables.ret_success)]
            block.append(self.create_code_block('line', lines))
            if len(block) > 2:
                if_block = self.create_code_block('else_if', block)
            else:
                if_block = self.create_code_block('if', block)
        code = []
        if len(attributes) == 0:
            code = [self.create_code_block('line', first_line),
                    self.create_code_block('line', last_line)]
        else:
            code = [self.create_code_block('line', first_line),
                    self.create_code_block('if', first_if),
                    if_block,
                    self.create_code_block('line', last_line)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing is set functions

    # function to write is set functions
    def write_is_set(self, attributes):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Predicate returning {0} if ' \
                     'this {1}\'s attribute \"attributeName\" is set.' \
            .format(self.true, self.class_name)
        params.append('@param attributeName, the name of the attribute to query.')

        return_lines.append('@return {0} if this {1}\'s attribute \"attributeName\" has been '
                            'set, otherwise {2} is returned.'
                            .format(self.true, self.class_name, self.false))

        # create the function declaration
        function = 'isSetAttribute'
        return_type = 'bool'

        arguments = ['const std::string& attributeName']

        # create the function implementation
        first_line = ['bool value = {0}::isSetAttribute(attributeName)'.format(self.base_class)]
        last_line = ['return value']
        first = True
        block = []
        for attrib in attributes:
            if not first:
                block.append('else if')
            else:
                first = False
            block.append('attributeName == \"{0}\"'.format(attrib['name']))
            block.append('value = isSet{0}()'.format(attrib['capAttName']))
            if len(block) > 2:
                if_block = self.create_code_block('else_if', block)
            else:
                if_block = self.create_code_block('if', block)
        code = []
        if len(attributes) == 0:
            code = [self.create_code_block('line', first_line),
                    self.create_code_block('line', last_line)]
        else:
            code = [self.create_code_block('line', first_line),
                    if_block,
                    self.create_code_block('line', last_line)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing set functions

    # function to write set functions
    def write_set(self, attributes, att_type):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Sets the value of the "attributeName" attribute of this {0}.' \
            .format(self.class_name)
        params.append('@param attributeName, the name of the attribute to set.')
        params.append('@param value, the value of the attribute to set.')

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @{0}constant{1}{2}, '
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.success, self.close_br))
        return_lines.append('@li @{0}constant{1}{2},'
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.failed, self.close_br))

        # create the function declaration
        function = 'setAttribute'
        return_type = 'int'

        arguments = ['const std::string& attributeName', '{0} value'.format(att_type)]

        # create the function implementation
        first_line = ['int return_value = {0}::setAttribute(attributeName, value)'.format(self.base_class)]
        last_line = ['return return_value']
        first = True
        block = []
        for attrib in attributes:
            if not first:
                block.append('else if')
            else:
                first = False
            block.append('attributeName == \"{0}\"'.format(attrib['name']))
            block.append('return_value = set{0}(value)'.format(attrib['capAttName']))
            if len(block) > 2:
                if_block = self.create_code_block('else_if', block)
            else:
                if_block = self.create_code_block('if', block)
        if len(attributes) == 0:
            code = [self.create_code_block('line', first_line),
                    self.create_code_block('line', last_line)]
        else:
            code = [self.create_code_block('line', first_line),
                    if_block,
                    self.create_code_block('line', last_line)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing unset functions

    # function to write unset functions
    def write_unset(self, attributes):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = ' Unsets the value of the "attributeName" attribute of this {0}.'.format(self.class_name)
        params.append('@param attributeName, the name of the attribute to query.')

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @{0}constant{1}{2}, '
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.success, self.close_br))
        return_lines.append('@li @{0}constant{1}{2},'
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.failed, self.close_br))


        # create the function declaration
        function = 'unsetAttribute'
        return_type = 'int'

        arguments = ['const std::string& attributeName']

        # create the function implementation
        first_line = ['int value = {0}::unsetAttribute(attributeName)'.format(self.base_class)]
        last_line = ['return value']
        first = True
        block = []
        for attrib in attributes:
            if not first:
                block.append('else if')
            else:
                first = False
            block.append('attributeName == \"{0}\"'.format(attrib['name']))
            if attrib['attType'] == 'vector':
                block.append('value = clear{0}()'.format(attrib['capAttName']))
            else:
                block.append('value = unset{0}()'.format(attrib['capAttName']))
            if len(block) > 2:
                if_block = self.create_code_block('else_if', block)
            else:
                if_block = self.create_code_block('if', block)
        code = []
        if len(attributes) == 0:
            code = [self.create_code_block('line', first_line),
                    self.create_code_block('line', last_line)]
        else:
            code = [self.create_code_block('line', first_line),
                    if_block,
                    self.create_code_block('line', last_line)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for manipulating object functions

    # function to write create functions
    def write_create_object(self):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        if len(self.elements) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Creates and returns an new "elementName" object in this {0}.' \
            .format(self.class_name)
        params.append('@param elementName, the name of the element to create.')

        return_lines.append('@return pointer to the element created.')

        # create the function declaration
        function = 'createChildObject'
#        if self.is_plugin:
        return_type = '{0}*'.format(global_variables.baseClass)

        arguments = ['const std::string& elementName']

        code = []
        # create the function implementation
        if self.is_plugin:
            first_line = ['{0}* obj = NULL'.format(global_variables.baseClass)]
        else:
            first_line = ['{0}* obj = NULL'.format(self.base_class)]

        last_line = ['return obj']
        first = True
        block = []
        if_block = []

        for elem in self.elements:
            if elem['concrete']:
                for conc in elem['concrete']:
                    if not first:
                        block.append('else if')
                    else:
                        first = False
                    concname = conc['name']
                    if conc['name'].lower() != conc['element'].lower():
                        concname = strFunctions.lower_first(strFunctions.remove_prefix(conc['element']))
                    block.append('elementName == \"{0}\"'.format(concname))
                    block.append('return create{0}()'.format(strFunctions.upper_first(concname)))
                    if len(block) > 2:
                        if_block = self.create_code_block('else_if', block)
                    else:
                        if_block = self.create_code_block('if', block)
            else:
                if not first:
                    block.append('else if')
                else:
                    first = False
                block.append('elementName == \"{0}\"'.format(elem['name']))
                [elem_name, unused] = strFunctions.remove_hyphens(elem['name'])
                block.append('return create{0}()'.format(strFunctions.upper_first(elem_name)))
                if len(block) > 2:
                    if_block = self.create_code_block('else_if', block)
                else:
                    if_block = self.create_code_block('if', block)
        code = [self.create_code_block('line', first_line),
                if_block,
                self.create_code_block('line', last_line)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    def has_elements_with_same_xml_name(self):
        for element in self.elements:
            if 'concrete' in element and element['concrete']:
                names_used = []
                for conc in element['concrete']:
                    conc_class = query.get_class(conc['element'], conc['root'])
                    if conc_class:
                        if 'elementName' in conc_class and conc_class['elementName'] != '':
                            if conc_class['elementName'] in names_used:
                                return True
                            else:
                                names_used.append(conc_class['elementName'])
        return False

    # function to write add functions
    def write_add_object(self):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        if len(self.elements) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Adds a new "elementName" object to this {0}.' \
            .format(self.class_name)
        params.append('@param elementName, the name of the element to create.')
        params.append('@param element, pointer to the element to be added.')

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @{0}constant{1}{2}, '
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.success, self.close_br))
        return_lines.append('@li @{0}constant{1}{2},'
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.failed, self.close_br))


        # create the function declaration
        function = 'addChildObject'
        return_type = 'int'

        arguments = ['const std::string& elementName', 'const {0}* element'.format(global_variables.baseClass)]

        code = []
        if not self.has_elements_with_same_xml_name():
            # create the function implementation
            last_line = ['return LIBSBML_OPERATION_FAILED']
            first = True
            block = []
            if_block = []

            for elem in self.elements:
                if elem['concrete']:
                    for conc in elem['concrete']:
                        if not first:
                            block.append('else if')
                        else:
                            first = False
                        elemName = elem['name']
                        if not elem['element'] or elem['element'] == elemName:
                            elemElem = elemName
                        else:
                            elemElem = elem['element']
                        block.append('elementName == \"{0}\" && element->getTypeCode() == {1}'.format(conc['name'], conc['typecode']))
                        if elem not in self.single_elements:
                            block.append('return add{0}((const {1}*)(element))'.format(strFunctions.upper_first(elemName), elemElem))
                        else:
                            block.append('return set{0}((const {1}*)(element))'.format(strFunctions.upper_first(elemName), elemElem))
                else:
                    if not first:
                        block.append('else if')
                    else:
                        first = False
                    elemName = elem['name']
                    if not elem['element'] or elem['element'] == elemName:
                        elemElem = elemName
                    else:
                        elemElem = elem['element']
                    [elem_name, unused] = strFunctions.remove_hyphens(elemName)
                    block.append('elementName == \"{0}\" && element->getTypeCode() == {1}'.format(elemName, elem['typecode']))
                    if elem not in self.single_elements:
                        block.append('return add{0}((const {1}*)(element))'.format(strFunctions.upper_first(elem_name), elemElem))
                    else:
                        block.append('return set{0}((const {1}*)(element))'.format(strFunctions.upper_first(elem_name), elemElem))

                if len(block) > 2:
                    if_block = self.create_code_block('else_if', block)
                else:
                    if_block = self.create_code_block('if', block)
            code = [if_block,
                    self.create_code_block('line', last_line)]
        else:
            code = [self.create_code_block('comment', ['TO DO']),
                    self.create_code_block('line', ['return -1'])]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write remove functions
    def write_remove_object(self):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        if len(self.elements) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Removes and returns the new "elementName" object with the given id in this {0}.' \
            .format(self.class_name)
        params.append('@param elementName, the name of the element to remove.')
        params.append('@param id, the id of the element to remove.')

        return_lines.append('@return pointer to the element removed.')

        # create the function declaration
        function = 'removeChildObject'
        return_type = '{0}*'.format(global_variables.baseClass)

        arguments = ['const std::string& elementName', 'const std::string& id']

        code = []
        if not self.has_elements_with_same_xml_name():
            # create the function implementation
            last_line = ['return NULL']
            first = True
            block = []
            if_block = []

            for elem in self.elements:
                if elem['concrete']:
                    for conc in elem['concrete']:
                        if not first:
                            block.append('else if')
                        else:
                            first = False
                        elemName = elem['name']
                        if not elem['element'] or elem['element'] == elemName:
                            elemElem = elemName
                        else:
                            elemElem = elem['element']
                        block.append('elementName == \"{0}\"'.format(conc['name']))
                        single = True
                        if elem not in self.single_elements:
                            thisClass = query.get_class(elemElem, self.classroot)
                            single = False
                            hasid = False
                            for att in thisClass['attribs']:
                                if att['name'] == 'id':
                                    hasid = True
                            if hasid:
                                block.append('return remove{0}(id)'.format(strFunctions.upper_first(elemName)))
                            else:
                                nested_if = self.create_code_block('if', ['get{0}(i)->getId() == id'.format(strFunctions.upper_first(elemName)),
                                                                          'return remove{0}(i)'.format(strFunctions.upper_first(elemName))])
                                nested_for = self.create_code_block('for', ['unsigned int i = 0; i < getNum{0}(); i++'
                                                                            ''.format(strFunctions.plural(strFunctions.upper_first(elemName))), nested_if])
                                block.append(nested_for)
                        else:
                            [elem_name, unused] = strFunctions.remove_hyphens(elemName)
                            block.append('{0} * obj = get{1}()'.format(elemElem, strFunctions.upper_first(elem_name)))
                            block.append('if (unset{0}() == LIBSBML_OPERATION_SUCCESS) return obj'.format(strFunctions.upper_first(elem_name)))
                else:
                    if not first:
                        block.append('else if')
                    else:
                        first = False
                    elemName = elem['name']
                    if not elem['element'] or elem['element'] == elemName:
                        elemElem = elemName
                    else:
                        elemElem = elem['element']
                    block.append('elementName == \"{0}\"'.format(elem['name']))
                    single = True
                    if elem not in self.single_elements:
                        thisClass = query.get_class(elemElem, self.classroot)
                        single = False
                        hasid = False
                        for att in thisClass['attribs']:
                            if att['name'] == 'id':
                                hasid = True
                        if hasid:
                            block.append('return remove{0}(id)'.format(strFunctions.upper_first(elemName)))
                        else:
                            nested_if = self.create_code_block('if', ['get{0}(i)->getId() == id'.format(strFunctions.upper_first(elemName)),
                                                                      'return remove{0}(i)'.format(strFunctions.upper_first(elemName))])
                            nested_for = self.create_code_block('for', ['unsigned int i = 0; i < getNum{0}(); i++'
                                                                        ''.format(strFunctions.plural(strFunctions.upper_first(elemName))), nested_if])
                            block.append(nested_for)
                    else:
                        [elem_name, unused] = strFunctions.remove_hyphens(elemName)
                        block.append('{0} * obj = get{1}()'.format(elemElem, strFunctions.upper_first(elem_name)))
                        block.append('if (unset{0}() == LIBSBML_OPERATION_SUCCESS) return obj'.format(strFunctions.upper_first(elem_name)))
                if single:
                    if len(block) > 3:
                        if_block = self.create_code_block('else_if', block)
                    else:
                        if_block = self.create_code_block('if', block)
                else:
                    if len(block) > 2:
                        if_block = self.create_code_block('else_if', block)
                    else:
                        if_block = self.create_code_block('if', block)
            code = [if_block,
                    self.create_code_block('line', last_line)]
        else:
            code = [self.create_code_block('comment', ['TO DO']),
                    self.create_code_block('line', ['return NULL'])]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write get num objects functions
    def write_get_num_objects(self):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        if len(self.elements) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Returns the number of \"elementName" in this {0}.' \
            .format(self.class_name)
        params.append('@param elementName, the name of the element to get number of.')

        return_lines.append('@return unsigned int number of elements.')

        # create the function declaration
        function = 'getNumObjects'
        return_type = 'unsigned int'


        arguments = ['const std::string& elementName']

        code = []
        if not self.has_elements_with_same_xml_name():
            # create the function implementation
            first_line = ['unsigned int n = 0']
            last_line = ['return n']
            first = True
            block = []
            if_block = []

            for elem in self.elements:
                if not first:
                    block.append('else if')
                else:
                    first = False
                block.append('elementName == \"{0}\"'.format(elem['name']))
                if elem in self.lo_elements:
                    name = strFunctions.plural(strFunctions.upper_first(elem['name']))
                    block.append('return getNum{0}()'.format(name))
                else:
                    [elem_name, unused] = strFunctions.remove_hyphens(elem['name'])
                    nested_if = ['isSet{0}()'.format(strFunctions.upper_first(elem_name)),
                                 'return 1']
                    nested_if_block = self.create_code_block('if', nested_if)
                    block.append(nested_if_block)
                if len(block) > 2:
                    if_block = self.create_code_block('else_if', block)
                else:
                    if_block = self.create_code_block('if', block)
            code = [self.create_code_block('line', first_line),
                    if_block,
                    self.create_code_block('line', last_line)]
        else:
            code = [self.create_code_block('comment', ['TO DO']),
                    self.create_code_block('line', ['return 0'])]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write getobjects functions
    def write_get_object(self):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return

        if len(self.elements) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Returns the nth object of \"objectName" in this {0}.' \
            .format(self.class_name)
        params.append('@param elementName, the name of the element to get number of.')
        params.append('@param index, unsigned int the index of the object to retrieve.')

        return_lines.append('@return pointer to the object.')

        # create the function declaration
        function = 'getObject'
        return_type = '{0}*'.format(global_variables.baseClass)

        arguments = ['const std::string& elementName', 'unsigned int index']

        code = []
        if not self.has_elements_with_same_xml_name():
            # create the function implementation
            first_line = ['{0}* obj = NULL'.format(global_variables.baseClass)]
            last_line = ['return obj']
            first = True
            block = []
            if_block = []

            for elem in self.elements:
                if not first:
                    block.append('else if')
                else:
                    first = False
                block.append('elementName == \"{0}\"'.format(elem['name']))
                [elem_name, unused] = strFunctions.remove_hyphens(elem['name'])
                if elem in self.single_elements:
                    block.append('return get{0}()'.format(strFunctions.upper_first(elem_name)))
                else:
                    block.append('return get{0}(index)'.format(strFunctions.upper_first(elem_name)))

                if len(block) > 2:
                    if_block = self.create_code_block('else_if', block)
                else:
                    if_block = self.create_code_block('if', block)
            code = [self.create_code_block('line', first_line),
                    if_block,
                    self.create_code_block('line', last_line)]
        else:
            code = [self.create_code_block('comment', ['TO DO']),
                    self.create_code_block('line', ['return NULL'])]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing test functions

    # function to write set functions
    def write_test(self, attributes, att_type):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return
        elif attributes is None or len(attributes) == 0:
            return

        # use the first attribute of this type
        attrib = attributes[0]
        name = attrib['name']

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = ''

        # create the function declaration
        function = ''
        return_type = ''

        test_function = 'test_Attributes_{0}_{1}'.format(self.class_name, name)
        arguments = [test_function]
        self.tests.append(test_function)

        initial = ''
        if att_type == 'bool':
            initial = 'true'
            default = 'value == {0}'.format(initial)
        elif att_type == 'int' or att_type == 'unsigned int':
            initial = '2'
            default = 'value == SBML_INT_MAX'
        elif att_type == 'double':
            initial = '3.6'
            default = 'util_isNaN(value)'
        elif att_type == 'std::string':
            initial = '\"string\"'
            default = 'value.empty()'
        if att_type == 'double':
            equals = 'util_isEqual(value, initialValue)'
            equals1 = 'util_isEqual(obj->get{0}(), initialValue)'.format(attrib['capAttName'])
            equals2 = 'util_isEqual(otherValue, initialValue)'
        else:
            equals = 'value == initialValue'
            equals1 = 'obj->get{0}() == initialValue'.format(attrib['capAttName'])
            equals2 = 'otherValue == initialValue'

        # create the function implementation
        implementation = ['{0} *obj = new {0}(3,1)'.format(self.class_name),
                          '{0} initialValue = {1}'.format(att_type, initial),
                          '{0} value'.format(att_type),
                          '{0} otherValue'.format(att_type),
                          'int result']
        impl2 = ['result = obj->setAttribute(\"{0}\", initialValue)'.format(name),
                 'fail_unless(result == {0})'.format(self.success),
                 'fail_unless({0})'.format(equals1),
                 'fail_unless(obj->isSet{0}() == true)'.format(attrib['capAttName']),
                 'fail_unless(obj->isSetAttribute(\"{0}\") == true)'.format(name)]
        impl3 = ['result = obj->getAttribute(\"{0}\", value)'.format(name),
                 'fail_unless(result == {0})'.format(self.success),
                 'fail_unless({0})'.format(equals)]
        impl4 = ['otherValue = static_cast<SBase*>(obj)->getAttribute<{0}>(\"{1}\")'.format(att_type, name),
                 'fail_unless({0})'.format(equals2)]
        impl5 = ['result = obj->unsetAttribute(\"{0}\")'.format(name),
                 'fail_unless(result == {0})'.format(self.success),
                 'fail_unless(obj->isSet{0}() == false)'.format(attrib['capAttName']),
                 'fail_unless(obj->isSetAttribute(\"{0}\") == false)'.format(name)]
        impl6 = ['result = obj->getAttribute(\"{0}\", value)'.format(name),
                 'fail_unless(result == {0})'.format(self.success),
                 'fail_unless({0})'.format(default)]
        code = [self.create_code_block('line', implementation),
                self.create_code_block('line', impl2),
                self.create_code_block('line', impl3),
                self.create_code_block('line', impl4),
                self.create_code_block('line', impl5),
                self.create_code_block('line', impl6)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.class_name,
                     'implementation': code})

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code

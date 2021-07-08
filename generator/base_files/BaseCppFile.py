#!/usr/bin/env python
#
# @file    BaseCppFile.py
# @brief   base class for cpp files to be generated
# @author  Frank Bergmann
# @author  Sarah Keating
# @author  Matthew S. Gillman
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2018 by the California Institute of Technology
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


from . import BaseFile
from util import strFunctions as SF, query, global_variables as gv


class BaseCppFile(BaseFile.BaseFile):
    """Common base class for all C++ files"""

    def __init__(self, name, extension, attributes):
        """
        BaseCppFile constructor. Initialise object and open file
        handle for writing.

        :param name: name of file, without extension
        :param extension: file extension (no dot), e.g. 'h', 'cpp', 'cxx'
        :param attributes: list of attribute dictionaries, can be None
        """
        BaseFile.BaseFile.__init__(self, name, extension)

        # members that might get overridden if creating another library
        self.baseClass = gv.baseClass

        # expand the information for the attributes
        if attributes:
            self.attributes = self.expand_attributes(attributes)
            self.sort_name_mismatches()
            self.child_elements = self.get_children()
            self.child_lo_elements = self.get_lo_children()
        else:
            self.attributes = []  # List of dictionaries
            self.child_elements = []
            self.child_lo_elements = []

        self.num_children = \
            len(self.child_lo_elements) + len(self.child_elements)

        self.concretes = []

        # default values
        self.is_cpp_api = True

        self.class_object = {}

        # Declare variables that will be populated by the class object.
        if not self.name:
            self.name = ''

        self.is_list_of, self.class_name, self.package, \
            self.typecode, self.list_of_name, self.list_of_child,\
            self.sid_refs, self.unit_sid_refs = ('',) * 8

        # Globally-defined "standard" base, e.g. gv.std_base = 'SBase'.
        self.has_std_base = True
        self.std_base = gv.std_base

        self.add_decls, self.add_impl = None, None

        self.overwrites_children, self.has_math, self.has_children,\
            self.has_only_math, self.has_parent_list_of, self.is_plugin,\
            self.is_doc_plugin, self.has_non_std_children = (False,) * 8

        self.num_non_std_children = 0
        self.class_attributes = []

    ########################################################################

    def expand_class(self, class_object):
        """
        Expand the information we hold about a C++ class.

        :param class_object: dictionary of existing information about the
             C++ class, obtained by parsing the XML file.
        :return: nothing
        """
        self.class_object = class_object
        self.is_list_of = class_object['is_list_of']
        self.has_parent_list_of = class_object['hasListOf']
        self.name = class_object['name']
        self.class_name = class_object['name']
        self.package = class_object['package']
        self.typecode = class_object['typecode']

        if class_object['is_list_of']:
            self.list_of_name = class_object['list_of_name']
            self.list_of_child = class_object['lo_child']
        else:
            self.list_of_name = ''
            self.list_of_child = ''

        # Check case of things where we assume upper/lower:
        if self.package[0].islower():
            self.package = SF.upper_first(class_object['package'])

        # Are we a plugin?
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
        if 'is_doc_plugin' in class_object:
            self.is_doc_plugin = class_object['is_doc_plugin']

        # Information about the base class
        self.baseClass = class_object['baseClass']
        if self.language != 'sbml':
            if not self.is_list_of:
                base = '{0}Base'.format(gv.prefix)
            else:
                base = '{0}ListOf'.format(gv.prefix)
            if base != self.baseClass:
                self.has_std_base = False

        elif not self.is_list_of and not self.is_plugin \
                and self.baseClass != 'SBase':
            self.has_std_base = False
        elif self.is_list_of and not self.is_plugin \
                and self.baseClass != 'ListOf':
            self.has_std_base = False
        elif self.is_plugin and not self.is_doc_plugin \
                and self.baseClass != 'SBasePlugin':
            self.has_std_base = False
        elif self.is_doc_plugin:
            self.has_std_base = True
            self.std_base = '{0}DocumentPlugin'.format(self.cap_language)
        self.class_object['has_std_base'] = self.has_std_base
        self.class_object['std_base'] = self.std_base

        # References
        self.sid_refs = class_object['sid_refs']
        self.unit_sid_refs = class_object['unit_sid_refs']
        if 'addDecls' in class_object:
            self.add_decls = class_object['addDecls']
        if 'addDefs' in class_object:
            self.add_impl = class_object['addDefs']
        if 'childrenOverwriteElementName' in class_object:
            self.overwrites_children = \
                class_object['childrenOverwriteElementName']
        if not self.overwrites_children and ('root' in class_object and
                                             len(class_object['root']) > 0):
            self.overwrites_children = \
                query.overwrites_name(class_object['root'],
                                      class_object['name'])
        self.class_object['overwrites_children'] = self.overwrites_children

        # child elements
        self.has_math = class_object['hasMath']
        self.has_children = query.has_child_elements(class_object['attribs'])
        if self.has_math and \
                not query.has_children_not_math(class_object['attribs']):
            self.has_only_math = True

        # Mark child elements as ML nodes:
        for i in range(0, len(self.child_elements)):
            element = self.child_elements[i]
            if element['element'].endswith('Node') \
                    and not element['element'].endswith('CSGNode'):
                self.child_elements[i]['is_ml'] = True
                self.has_non_std_children = True
                self.num_non_std_children += 1
            else:
                self.child_elements[i]['is_ml'] = False

        if 'concrete' in class_object:
            self.concretes = query.get_concretes(class_object['root'],
                                                 class_object['concrete'])

        self.class_attributes = query.separate_attributes(self.attributes)

        # Document class for other libraries:
        self.document = False
        if 'document' in class_object:
            self.document = class_object['document']

        # Add info back to the class_object so we can pass it on:
        self.class_object. \
            update({'package': self.package,
                    'class_attributes': self.class_attributes,
                    'child_lo_elements': self.child_lo_elements,
                    'child_elements': self.child_elements,
                    'concretes': self.concretes,
                    'has_array': query.has_array(self.class_attributes),
                    'has_vector': query.has_vector(self.class_attributes),
                    'has_math': self.has_math,
                    'has_children': self.has_children,
                    'has_only_math': self.has_only_math,
                    'has_parent_list_of': self.has_parent_list_of,
                    'num_children': self.num_children,
                    'has_non_std_children': self.has_non_std_children,
                    'num_non_std_children': self.num_non_std_children,
                    'is_header': self.is_header,
                    'document': self.document, })

    ########################################################################

    def expand_attributes(self, attributes):
        """
        Function to expand the attribute information.

        :param attributes: a list of dictionaries, each storing data about
               an <attribute> node, obtained by parsing the XML file.
        :return: the updated list of dictionaries.

        The attributes passed as argument come from parseXML. This
        function adds further information and makes sure all fields
        have a value rather than having some dictionaries that don't
        have a particular entry.
        """
        for i in range(0, len(attributes)):

            # Get the ith dictionary in the list:
            mydict = attributes[i]

            # Update dictionary's 'name' entry:
            [attrib_name, had_hyphen] = SF.remove_hyphens(mydict['name'])
            capname = SF.upper_first(attrib_name)
            if had_hyphen:
                orig_name = mydict['name']
                mydict['name'] = SF.lower_first(orig_name)
            else:
                mydict['name'] = SF.lower_first(capname)

            # We may want the name to reflect an element:
            if 'element' in mydict and mydict['element'] != '':
                if 'xml_name' in mydict and mydict['xml_name'] != '':
                    possible_name = SF.singular(mydict['xml_name'])

                    # Need to catch the case where the xml_name is lower case
                    # but comes from a camel case element:
                    # TODO see notes on similar code in functions
                    # update_dict_with_element_att_type() and
                    # update_dict_with_lo_element_att_type()
                    if SF.is_camel_case(mydict['element']):
                        if possible_name == \
                                SF.remove_prefix(mydict['element']).lower():
                            capname = \
                                SF.upper_first(SF.remove_prefix(mydict['element']))  # noqa: E501
                    elif possible_name != attrib_name:
                        capname = SF.upper_first(mydict['xml_name'])

            mydict.update({'capAttName': capname, 'memberName': 'm' + capname,
                           'pluralName': SF.plural(attrib_name),
                           'isEnum': False, 'isArray': False,
                           'isVector': False, 'children_overwrite': False})

            att_type = mydict['type']

            self.update_attribute_dictionary(att_type, mydict, attrib_name)

        return attributes

    def update_attribute_dictionary(self, att_type, mydict, attrib_name):
        """
        Update the dictionary which stores an attribute's values.

        :param att_type: e.g. 'SId', 'SIdRef', 'string', 'double', 'int'.
        :param mydict: the dictionary we are updating.
        :param attrib_name: possibly-tweaked 'name' field of <attribute> node,
               e.g. 'math'
        :return: nothing
        """
        # Now update the dictionary, with the set of values according
        # to att_type:
        if att_type in ['SId', 'SIdRef', 'IDREF', 'ID', 'UnitSId',
                        'UnitSIdRef', 'string']:
            mydict.update({'attType': 'string', 'attTypeCode': 'std::string&',
                           'CType': 'const char *', 'isNumber': False,
                           'default': '""'})

        elif att_type == 'double':
            mydict.update({'attType': 'double', 'attTypeCode': 'double',
                           'CType': 'double', 'isNumber': True,
                           'default': 'util_NaN()'})

        elif att_type == 'int':
            mydict.update({'attType': 'integer', 'attTypeCode': 'int',
                           'CType': 'int', 'isNumber': True,
                           'default':
                               '{0}_INT_MAX'.format(self.cap_language)})

        elif att_type == 'uint':
            mydict.update({'attType': 'unsigned integer',
                           'attTypeCode': 'unsigned int',
                           'CType': 'unsigned int', 'isNumber': True,
                           'default':
                               '{0}_INT_MAX'.format(self.cap_language)})

        elif att_type in ['bool', 'boolean']:
            mydict.update({'attType': 'boolean', 'attTypeCode': 'bool',
                           'CType': 'int', 'isNumber': False,
                           'default': 'false'})

        elif att_type == 'enum':
            mydict.update({'isEnum': True, 'attType': 'enum',
                           'isNumber': False,
                           'default': query.get_default_enum_value(mydict)})
            mydict['attTypeCode'] = mydict['element'] + '_t'
            mydict['CType'] = mydict['element'] + '_t'

        elif att_type == 'element':
            self.update_dict_with_element_att_type(mydict, attrib_name)

        elif att_type in ['lo_element', 'inline_lo_element']:
            self.update_dict_with_lo_element_att_type(mydict, attrib_name)

        elif att_type == 'array':
            self.update_dict_with_array_att_type(mydict)

        elif att_type == 'vector':
            self.update_dict_with_vector_att_type(mydict)

        else:
            gv.code_returned = gv.return_codes['unknown type used']
            mydict['attType'] = 'FIXME_{0}'.format(att_type)
            mydict['attTypeCode'] = 'FIXME_{0}'.format(att_type)
            mydict['CType'] = 'FIXME_{0}'.format(att_type)
            mydict['isNumber'] = False
            mydict['default'] = 'FIXME_{0}'.format(att_type)

    def update_dict_with_element_att_type(self, mydict, attrib_name):
        """
        Update the entries in an attribute's dictionary, when the
        att_type is 'element'.

        :param mydict: the dictionary to update
        :param attrib_name: possibly-tweaked 'name' field of <attribute> node,
               e.g. 'math'
        :returns: nothing
        """
        el_name = mydict['element']
        at_name = attrib_name
        mydict['attType'] = 'element'
        if attrib_name == 'math':
            if gv.is_package:
                mydict['attTypeCode'] = 'ASTNode*'
                mydict['CType'] = 'ASTNode_t*'
            else:
                mydict['attTypeCode'] = \
                    'LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*'
                mydict['CType'] = 'LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*'
        else:
            mydict['attTypeCode'] = mydict['element'] + '*'
            mydict['CType'] = mydict['element'] + '_t*'

        if mydict['attTypeCode'] == 'XMLNode*' and not gv.is_package:
            mydict['attTypeCode'] = 'LIBSBML_CPP_NAMESPACE_QUALIFIER {0}*'.\
                format(mydict['element'])
            mydict['CType'] = 'LIBSBML_CPP_NAMESPACE_QUALIFIER {0}_t*'.\
                format(mydict['element'])
            # mydict['capAttName'] = SF.remove_prefix(mydict['element'])
        mydict['isNumber'] = False
        mydict['default'] = 'NULL'

        if 'xml_name' in mydict and mydict['xml_name'] != '':
            possible_name = mydict['xml_name']
            # Need to catch the case where the xml_name is lower case
            # but comes from a camel case element:
            # TODO more explanation please
            # TODO see note below about similar code
            if SF.is_camel_case(mydict['element']) and \
                    possible_name == \
                    SF.remove_prefix(mydict['element']).lower():
                possible_name = SF.lower_first(mydict['capAttName'])
            [mydict['used_child_name'], _] = SF.remove_hyphens(possible_name)
        if SF.compare_no_case(SF.remove_prefix(el_name), at_name):
            mydict['children_overwrite'] = False
        else:
            mydict['children_overwrite'] = True

    def update_dict_with_lo_element_att_type(self, mydict, attrib_name):
        """
        Update the dictionary (representing an <attribute> node) when the
        att_type is 'lo_element' or 'inline_lo_element'.

        :param mydict: the dictionary we are updating
        :param attrib_name: possibly-tweaked 'name' field of <attribute> node,
               e.g. 'math'
        :return: nothing
        """
        childclass = query.get_class(mydict['element'], mydict['root'])
        if childclass and 'lo_class_name' in childclass and \
                childclass['lo_class_name'] != '':
            name = childclass['lo_class_name']
        else:
            name = SF.list_of_name(mydict['element'])
        plural = SF.plural_no_prefix(mydict['element'])
        mydict.update({'attType': 'lo_element', 'attTypeCode': name,
                       'CType': 'ListOf_t', 'memberName': 'm' + plural,
                       'capAttName': SF.remove_prefix(mydict['element']),
                       'isNumber': False, 'default': 'NULL'})

        if 'xml_name' in mydict and mydict['xml_name'] != '':
            possible_name = mydict['xml_name']
            if mydict['xml_name'] != mydict['pluralName']:
                possible_name = SF.singular(mydict['xml_name'])

            # Need to catch case where the xml_name is lower case but
            # comes from a camel case element:
            # TODO v. similar to code in update_dict_with_element_att_type(),
            # although line starting mydict['used_child_name'] is different.
            # Is that correct? Could/should we take out the common code and
            # put it into a new function?
            if SF.is_camel_case(mydict['element']) and \
                    possible_name == \
                    SF.remove_prefix(mydict['element']).lower():
                possible_name = SF.lower_first(mydict['capAttName'])
            mydict['used_child_name'] = possible_name
        if attrib_name == SF.lower_first(SF.remove_prefix(self.name)):
            mydict['recursive_child'] = True
            mydict['attTypeCode'] = '{0} *'.format(name)
            mydict['listOfClassName'] = name

    def update_dict_with_array_att_type(self, mydict):
        """
        Update the dictionary (representing an <attribute> node) when the
        att_type is 'array'.

        :param mydict: the dictionary we are updating
        :return: nothing
        """
        mydict['isArray'] = True
        if mydict['element'] in ['Integer', 'integer']:
            mydict['element'] = 'int'
        else:
            mydict['element'] = SF.lower_first(mydict['element'])
        # mydict['attType'] = 'array'
        mydict['attTypeCode'] = mydict['element'] + '*'
        mydict['CType'] = mydict['attTypeCode']
        mydict.update({'attType': 'array', 'isNumber': False,
                       'default': 'NULL'})

    def update_dict_with_vector_att_type(self, mydict):
        """
        Update the dictionary (representing an <attribute> node) when the
        att_type is 'vector'.

        :param mydict: the dictionary we are updating
        :return: nothing
        """
        mydict['isVector'] = True
        if mydict['element'] in ['Integer', 'integer']:
            mydict['element'] = 'int'
        else:
            mydict['element'] = SF.lower_first(mydict['element'])
        mydict['attTypeCode'] = 'std::vector<{0}>'.format(mydict['element'])
        mydict['CType'] = mydict['attTypeCode']
        mydict.update({'attType': 'vector', 'isNumber': False,
                       'default': 'NULL'})

    def sort_name_mismatches(self):
        """
        We deal with duplicate xml_names, but TODO need a bit
         more description here.
        """
        need_to_adjust = False
        xml_names = []  # Stores unique 'xml_names'
        names_to_sort = []  # Stores duplicated 'xml_name' values.

        for attribute in self.attributes:
            if 'xml_name' in attribute and attribute['xml_name'] != '':
                xml_name = attribute['xml_name']
                if xml_name in xml_names:
                    names_to_sort.append(xml_name)
                    need_to_adjust = True
                else:
                    xml_names.append(xml_name)

        if not need_to_adjust:  # no duplicates
            return

        # We need to sort at least one name.
        # TODO more explanatory text needed here.
        for name in names_to_sort:
            for attribute in self.attributes:
                if 'xml_name' in attribute and attribute['xml_name'] == name:
                    att_type = attribute['attType']
                    if att_type in ['element', 'lo_element',
                                    'inline_lo_element']:
                        continue
                    else:
                        attribute['capAttName'] = \
                            SF.upper_first(attribute['name'])
                        attribute['memberName'] = \
                            'm{0}'.format(attribute['capAttName'])

    def create_lo_other_child_element_class(self, name, parent):
        """
        TODO I'm not sure about this one, sorry.

        :param name:
        :param parent:
        :return:
        """
        capname = SF.upper_first(name)
        element = dict({'isArray': False,
                        'name': SF.lower_first(capname),
                        'attTypeCode': capname + '*',
                        'CType': capname + '_t *',
                        'capAttName': capname,
                        'attType': 'element',
                        'memberName': 'm' + capname,
                        'isNumber': False,
                        'type': 'element',
                        'default': 'NULL',
                        'element': capname,
                        'is_ml': False,
                        'children_overwrite': False,
                        'abstract': False})
        child_class = dict({'name': parent,
                            'package': self.package,
                            'class_attributes': [],
                            'child_elements': [element]})
        return child_class

    def get_children(self):
        """
        Iterate over the object's list of "attribute" dictionaries.

        :return: list of dictionaries with 'element' att_type
                 and unique names (in the list)
        """
        elements = []
        listed_elements = []
        for i in range(0, len(self.attributes)):
            mydict = self.attributes[i]
            att_type = mydict['attType']
            name = mydict['name']
            if att_type == 'element' and name not in listed_elements:
                elements.append(mydict)
                listed_elements.append(name)
        return elements

    def get_lo_children(self):
        """
        Iterate over the object's "attribute" dictionaries.
        TODO Sarah, please expand a bit here.

        :return: list of dictionaries with unique names and
            of type 'inline_lo_element'
        """
        elements = []
        listed_elements = []
        for i in range(0, len(self.attributes)):
            attribute = self.attributes[i]
            att_type = attribute['attType']
            name = attribute['name']
            if 'xml_name' in attribute and len(attribute['xml_name']) > 0\
                    and attribute['xml_name'] != name:
                name = attribute['xml_name']
            if att_type == 'lo_element' and name not in listed_elements:
                # check for concrete instances
                if attribute['type'] == 'inline_lo_element':
                    capname = SF.upper_first(name)
                    attrib_class = query.get_class(capname, attribute['root'])
                    if attrib_class and 'concrete' in attrib_class:
                        attribute['concrete'] = attrib_class['concrete']
                elements.append(attribute)
                listed_elements.append(name)
        return elements

    ########################################################################

    # Functions to overwrite base class settings
    def set_base_class(self, base):
        """
        Overwrite the class's base

        :param base: the class to which we wish to set it.
        """
        self.baseClass = base

    def set_std_base_class(self, base):
        """
        Overwrite the object's "standard" base.
        TODO Sarah please expand on this (and in member declaration
        for std_base above)

        :param base: the class to which we wish to set it.
        """
        self.std_base = base

    ########################################################################

    #   FUNCTIONS FOR WRITING STANDARD OPENING CLOSING ELEMENTS

    def write_cppns_begin(self):
        """
        Declare the beginning of a cpp namespace.
        """
        self.skip_line(2)
        self.write_line('{0}_CPP_NAMESPACE_BEGIN'
                        .format(self.library_name.upper()))
        self.skip_line(2)

    def write_cppns_end(self):
        """
        Mark the end of a cpp namespace.
        """
        self.skip_line(2)
        self.write_line('{0}_CPP_NAMESPACE_END'
                        .format(self.library_name.upper()))
        self.skip_line(2)

    def write_cppns_use(self):
        """
        Declare "CPP_NAMESPACE_USE"
        """
        self.skip_line(2)
        self.write_line('{0}_CPP_NAMESPACE_USE'
                        .format(self.library_name.upper()))
        self.skip_line(2)

    def write_cdecl_begin(self):
        """
        Declare BEGIN_C_DECLS for portable C code.

        See:
        https://www.gnu.org/software/libtool/manual/html_node/C-header-files.html
        It's for making sure the C headers can be used with different
        compilers, when using mixed C and C++ code.
        """
        self.skip_line(2)
        self.write_line('BEGIN_C_DECLS')
        self.skip_line(2)

    def write_cdecl_end(self):
        """
        Put at end of C code, for working with different compilers.
        """
        self.skip_line(2)
        self.write_line('END_C_DECLS')
        self.skip_line(2)

    def write_swig_begin(self):
        """
        Used to start a block of code which you want SWIG to ignore
        during the -includeall pass.
        """
        self.skip_line(2)
        self.write_line('#ifndef SWIG')
        self.skip_line(2)

    def write_swig_end(self):
        """
        Used to end a block of code which you want SWIG to ignore
        during the -includeall pass.
        """
        self.skip_line(2)
        self.write_line('#endif  /*  !SWIG  */')
        self.skip_line(2)

    def write_cpp_begin(self):
        """
        Used to mark the beginning of a C++-specific block
        (the #ifdef should only be true if you're using a C++ compiler)
        See https://isocpp.org/wiki/faq/mixing-c-and-cpp
        """
        self.skip_line(2)
        self.write_line('#ifdef __cplusplus')
        self.skip_line(2)

    def write_cpp_end(self):
        """
        Used to mark the end of a C++-specific block.
        """
        self.skip_line(2)
        self.write_line('#endif  /*  __cplusplus  */')
        self.skip_line(2)

########################################################################

# FUNCTIONS FOR WRITING STANDARD FUNCTION DECLARATIONS

    def write_function_header(self,
                              function_name, arguments, return_type,
                              is_const=False, is_virtual=False,
                              is_abstract=False):
        """
        Used to write a C++ function header.

        :param function_name: the name of the function.
        :param arguments: the function's arguments.
        :param return_type: the return type of the function
        :param is_const: `True` if it's a "const function", i.e. "A member
               function that inspects (rather than mutates) its object."
               (see:
               https://isocpp.org/wiki/faq/const-correctness#const-member-fns)
        :param is_virtual: `True` if C++ function is virtual
                 (i.e. it allows overloading).
        :param is_abstract: `True` if this is a pure virtual
                  function (subclasses must implement).
        :return: nothing
        """
        is_cpp = self.is_cpp_api
        num_arguments = len(arguments)
        if not is_cpp:
            self.write_extern_decl()
            self.write_line(return_type)
            line = function_name + '('
        else:
            # return_type may be ""
            line = "virtual " if is_virtual else ""
            line += return_type + ' ' if return_type != "" else ""
            line += function_name + '('

        if num_arguments == 0:
            self.write_zero_or_one_function_argument(line, is_cpp, is_const,
                                                     None, is_abstract,
                                                     add_semicolon=True)
        elif num_arguments == 1:
            self.write_zero_or_one_function_argument(line, is_cpp, is_const,
                                                     arguments[0],
                                                     is_abstract,
                                                     add_semicolon=True)
        else:
            self.write_multiple_function_arguments(line, arguments,
                                                   num_arguments, is_const,
                                                   is_cpp, True)

    def write_class_function_header(self, function_name, arguments,
                                    return_type, is_const=False,
                                    constructor_args=None):
        """
        TODO Sarah, what is the difference between this and the function
        immediately above? When is each used?

        :param function_name:
        :param arguments:
        :param return_type:
        :param is_const:
        :param constructor_args:
        :return: nothing
        """
        is_cpp = self.is_cpp_api
        num_arguments = len(arguments)
        if not is_cpp:
            self.write_extern_decl()
        self.write_line(return_type)
        line = function_name + '('
        if num_arguments == 0:
            self.write_zero_or_one_function_argument(line, is_cpp, is_const),
        elif num_arguments == 1:
            self.write_zero_or_one_function_argument(line, is_cpp,
                                                     is_const, arguments[0]),
        else:
            self.write_multiple_function_arguments(line, arguments,
                                                   num_arguments, is_const,
                                                   is_cpp)
        if constructor_args is not None:
            self.up_indent()
            for i in range(0, len(constructor_args)):
                self.write_line(constructor_args[i])
            self.down_indent()

    def write_zero_or_one_function_argument(self, line, is_cpp, is_const,
                                            argument=None, is_abstract=False,
                                            add_semicolon=False):
        """
        Use when a function has either 0 or 1 argument.

        :param line: the start of the function declaration
        :param is_cpp: `True` if it's a C++ function
        :param is_const: `True` if it's a "const function"
        :param argument: the sole function argument, if present, else `None`
        :param is_abstract: `True` if it's a pure virtual function.
        :returns: nothing
        """
        if argument is None:
            argument = ""
        line += argument + ')'
        if is_cpp and is_const:
            line += ' const'
        elif is_abstract:
            line += ' = 0'
        else:
            line += ''
        if add_semicolon:
            line += ';'
        self.write_line(line)

    def write_multiple_function_arguments(self, line, arguments,
                                          num_arguments, is_const, is_cpp,
                                          add_semicolon=False):
        """
        Write multiple (> 1) function arguments to the header file.

        :param line: the function name and opening bracket
        :param arguments: the function's arguments
        :param num_arguments: the number of arguments
        :param is_const: `True` if this is a "const function"
        :param is_cpp: `True` if this is a C++ header.
        :param add_semicolon: True to add a ';' at the end of certain lines.
        :returns: nothing
        """
        saved_line = line
        line += arguments[0] + ', '
        # create the full line
        for n in range(1, num_arguments - 1):
            line += arguments[n] + ', '
        line += arguments[num_arguments - 1] + ')'
        line += " const" if (is_cpp and is_const) else ""  # no semis
        if add_semicolon:
            line += ';'

        # look at length and adjust
        if len(line) >= self.line_length:
            # do something else
            line = saved_line
            att_start = len(line)
            line += arguments[0]
            line += ','
            if len(line) > self.line_length:
                self.write_line(saved_line)
                line = '' + arguments[0] + ','
                self.write_line(line, att_start)
            else:
                self.write_line(line)
            for i in range(1, num_arguments - 1):
                # TODO should we also check here
                #  if len(line) > self.line_length ??
                line = arguments[i] + ','
                self.write_line(line, att_start)
            line = arguments[num_arguments - 1] + ')'
            line += ' const' if is_cpp and is_const else ''  # no semis
            if add_semicolon:
                line += ';'
            self.write_line(line, att_start)
        else:
            self.write_line(line)

########################################################################

# FUNCTIONS FOR WRITING STANDARD DOC COMMENTS

    def write_comment_header(self, title_line, params, return_line,
                             object_name, additional=None):
        """
        TODO looks like this writes a comment for a function in the
        header file.
        But I'm not sure of the details, or what all the params are for.

        :param title_line:
        :param params:
        :param return_line:
        :param object_name:
        :param additional:
        :return: nothing
        """
        if additional is None:
            additional = []
        self.open_comment()
        self.write_comment_line(title_line)
        for i in range(0, len(params)):
            self.write_blank_comment_line()
            self.write_comment_line(params[i])
        if len(return_line) > 0:
            self.write_blank_comment_line()
        for i in range(0, len(return_line)):
            self.write_comment_line((return_line[i]))
        if len(additional) > 0:
            self.write_blank_comment_line()
        for i in range(0, len(additional)):
            if additional[i] == ' ':
                self.write_blank_comment_line()
            else:
                self.write_comment_line(additional[i])
        if object_name.endswith('_t'):
            self.write_blank_comment_line()
            self.write_comment_line('@memberof {0}'.format(object_name))
        self.close_comment()

    def write_brief_header(self, title_line):
        """
        Write a short comment in the file.

        :param title_line: the text to put in the comment.
        :return: nothing
        """
        self.open_single_comment(self)
        self.write_comment_line(title_line)
        self.close_comment()

#########################################################################

    def write_function_declaration(self, code, exclude=False):
        """
        Write a function definition with comment.

        :param code: dictionary of information about the function
              to be written.
        :param exclude: `True` if you want to exclude this function
            from Doxygen.
        :return: nothing
        """
        if code is not None:
            if exclude:
                self.write_doxygen_start()
            self.write_comment_header(code['title_line'], code['params'],
                                      code['return_lines'],
                                      code['object_name'],
                                      code['additional'])
            if 'pure_abstract' in code and code['pure_abstract']:
                self.write_function_header(code['function'],
                                           code['arguments'],
                                           code['return_type'],
                                           code['constant'], code['virtual'],
                                           True)
            else:
                if self.is_cpp_api:
                    arguments = code['arguments']
                else:
                    if 'args_no_defaults' in code:
                        arguments = code['args_no_defaults']
                    else:
                        arguments = code['arguments']
                self.write_function_header(code['function'], arguments,
                                           code['return_type'],
                                           code['constant'], code['virtual'])
            if exclude:
                self.write_doxygen_end()
                self.skip_line()
            else:
                self.skip_line(2)

    def write_function_implementation(self, code, exclude=False, test=False):
        """
        Function for writing a C/C++ function implementation

        :param code: dictionary storing information about the function.
        :param exclude: (conditionally) exclude the function from processing
            by Doxygen
        :param test: `True` if we are running a test (????)
        :return: nothing
        """
        if code is not None:
            if exclude:
                self.write_doxygen_start()
            if not test:
                self.write_brief_header(code['title_line'])
                function_name = code['function']
            else:
                function_name = 'START_TEST '
            if self.is_cpp_api and not test:
                if not code['object_name']:
                    function_name = code['function']
                else:
                    function_name = code['object_name'] + '::' \
                                  + code['function']
            if 'args_no_defaults' in code:
                arguments = code['args_no_defaults']
            else:
                arguments = code['arguments']
            constructor_args = None
            if self.is_cpp_api:
                if 'constructor_args' in code:
                    constructor_args = code['constructor_args']
            self.write_class_function_header(function_name, arguments,
                                             code['return_type'],
                                             code['constant'],
                                             constructor_args)

            if 'implementation' in code and code['implementation'] is not None:
                self.write_implementation(code['implementation'])
            if exclude:
                self.write_doxygen_end()
                self.skip_line()
            elif test:
                self.write_line_verbatim('END_TEST')
                self.skip_line(2)
            else:
                self.skip_line(2)

    def write_inline_function_implementation(self, code, exclude=False):
        """
        Function for writing a function implementation
        TODO Presumably a C++ inline function...
        ...So, shouldn't the key word 'inline' appear here somewhere?

        :param code: dictionary of information about the function.
        :param exclude: (conditionally) exclude the function from processing
            by Doxygen
        :return: nothing
        """
        if code is not None:
            if exclude:
                self.write_doxygen_start()
            if len(code['title_line']) > 0:
                self.write_brief_header(code['title_line'])
            function_name = code['function']
            if self.is_cpp_api:
                function_name = code['function']
            if 'args_no_defaults' in code:
                arguments = code['args_no_defaults']
            else:
                arguments = code['arguments']
            constructor_args = None
            if self.is_cpp_api:
                if 'constructor_args' in code:
                    constructor_args = code['constructor_args']
            self.write_class_function_header(function_name, arguments,
                                             code['return_type'],
                                             code['constant'],
                                             constructor_args)

            if 'implementation' in code and code['implementation'] is not None:
                self.write_implementation(code['implementation'])
            if exclude:
                self.write_doxygen_end()
                self.skip_line()
            else:
                self.skip_line(2)

    def write_function_verbatim(self, code):
        """
        Function for writing a function implementation

        :param code: dictionary of information about what to write.
        :return: nothing
        """
        if code is not None:
            self.write_brief_header(code['title_line'])
            self.write_line(code['function'])

            if 'implementation' in code and code['implementation'] is not None:
                self.write_line('{')
                self.up_indent()
                for i in range(0, len(code['implementation'])):
                    self.write_line(code['implementation'][i])
                self.down_indent()
                self.write_line('};')
                self.skip_line(2)

    def write_type_code_enum_header(self, package):
        """
        Function to write the header about the typecode enumeration

        :param package: name of the package ??
        :return: nothing
        """
        up_package = SF.upper_first(package)
        self.open_comment()
        self.write_comment_line('@enum {0}{1}'
                                'TypeCode_t'.format(self.cap_language,
                                                    up_package))
        self.write_comment_line('@brief {0}{1}TypeCode_t Enumeration '
                                'of possible types in the lib{0} '
                                '&ldquo;{2}&rdquo; package '
                                'implementation.'.format(self.cap_language,
                                                         up_package,
                                                         package))
        self.write_blank_comment_line()
        self.write_comment_line('@copydetails doc_what_are_typecodes')
        self.write_blank_comment_line()
        self.write_comment_line('@copydetails doc_additional_typecode_details')
        self.close_comment()

    def write_enum(self, name, enum_no, enum_val, enum_str, length):
        """
        Function to write to the header about the typecode enumeration

        :param name: the name of the enum
        :param enum_no: ???
        :param enum_val: list of values in the enum
        :param enum_str: list of names in the enum
        :param length: ???
        :return: nothing
        """
        number = len(enum_val)
        if len(enum_str) != number:
            return  # and flag up an error?
        parts = enum_val[0].split('_')
        writing_typecodes = False
        if len(parts) > 1 and parts[1].lower() == self.package:
            writing_typecodes = True
        if not writing_typecodes:
            self.write_enum_header(name, parts[0].lower(), parts[1].lower())
        self.write_line('typedef enum')
        self.write_line('{')
        self.file_out.write('  {0:{width}}'.format(enum_val[0], width=length))
        if enum_no != 0:
            self.file_out.write('= {0:{width}}'.format(enum_no, width=5))
            enum_no += 1
        if writing_typecodes:
            self.file_out.write('  /*!<{0} */\n'.format(enum_str[0]))
        else:
            self.file_out.write('  /*!< The {1} {2} is @c \"{0}\". */\n'.
                                format(enum_str[0], parts[0].lower(),
                                       parts[1].lower()))

        for i in range(1, number):
            parts = enum_val[i].split('_')
            self.file_out.write(', {0:{width}}'.
                                format(enum_val[i], width=length))
            if enum_no != 0:
                self.file_out.write('= {0:{width}}'.format(enum_no, width=5))
                enum_no += 1
            if writing_typecodes:
                self.file_out.write('  /*!<{0} */\n'.format(enum_str[i]))
            else:
                if parts[-1] == 'INVALID':
                    self.file_out.write('  /*!< Invalid {0} value. */\n'.
                                        format(name[0:len(name) - 2]))
                else:
                    self.file_out.\
                        write('  /*!< The {1} {2} is @c \"{0}\". */\n'.
                              format(enum_str[i], parts[0].lower(),
                                     parts[1].lower()))
        self.write_line('{0} {1};'.format('}', name))

    def write_enum_header(self, name, classname, typename):
        """
        Write comments/Doxygen commands about an enum

        :param name: the name of the enum
        :param classname: the name of the C++ class which this enum belongs to
        :param typename: the name of the type we wish to set or get ???
        :return: nothing
        """
        classname = SF.upper_first(classname)
        up_typename = SF.upper_first(typename)
        self.open_comment()
        self.write_comment_line('@enum {0}'.format(name))
        if gv.library_name != 'Libsbml':
            self.write_comment_line('@brief Enumeration of values permitted'
                                    ' as the value of \"{0}\".'.format(name))
        else:
            self.write_comment_line('@brief Enumeration of values permitted'
                                    ' as the value of the \"{0}\" attribute '
                                    'on {1} objects.'.
                                    format(typename, classname))
            self.write_blank_comment_line()
            self.write_comment_line('@if conly')
            self.write_comment_line('@see {0}_get{1}()'.
                                    format(classname, up_typename))
            self.write_comment_line('@see {0}_set{1}()'.
                                    format(classname, up_typename))
            self.write_comment_line('@elseif java')
            self.write_comment_line('@see {0}::get{1}()'.
                                    format(classname, up_typename))
            self.write_comment_line('@see {0}::set{1}(long)'.
                                    format(classname, up_typename))
            self.write_comment_line('@else')
            self.write_comment_line('@see {0}::get{1}()'.
                                    format(classname, up_typename))
            self.write_comment_line('@see {0}::set{1}()'.
                                    format(classname, up_typename))
            self.write_comment_line('@endif')
        self.close_comment()

    def write_enum_strings(self, name, enum_str):
        """
        Function to write the header about the typecode enumeration
        TODO Presumably the word 'enum' is written out at some point?

        :param name: the name of the enum
        :param enum_str: list of strings of enum members ?
        :return: nothing
        """
        number = len(enum_str)
        self.write_line('static')
        self.write_line('const char* {0}[] ='.format(name))
        self.write_line('{')
        # Here we directly write out the line so that deviser does not try and
        # chop it up into lines of a given length:
        self.file_out.write('  \"{0}\"\n'.format(enum_str[0]))
        for i in range(1, number):
            self.file_out.write(', \"{0}\"\n'.format(enum_str[i]))
        self.write_line('};')

    ########################################################################

    # FUNCTIONS FOR WRITING STANDARD FUNCTION Implementation

    def write_implementation(self, implementation):
        """
        Write some code enclosed within braces ('{' and '}')

        :param implementation: list of code fragments, each stored in
            a dictionary
        :returns: nothing
        """
        self.write_line('{')
        self.write_nested_implementation(implementation)
        self.write_line('}')

    def write_implementation_block(self, code_type, code):
        """
        Write a block of C/C++ code.

        :param code_type: the type of the thing to write
        :param code: the actual code to write
        :returns: nothing
        """
        if code_type == 'line':
            self.write_lines(code)
        elif code_type == 'comment':
            self.write_comments(code)
        elif code_type == 'if':
            self.write_block('if', code, True)
        elif code_type == 'if_else':
            self.write_if_else_block(code)
        elif code_type == 'else_if':
            self.write_else_if_block(code)
        elif code_type == 'for':
            self.write_block('for', code, True)
        elif code_type == 'while':
            self.write_block('while', code, True)
        elif code_type == 'try':
            self.write_try_block(code)

    def write_nested_implementation(self, implementation):
        """
        Iterate over a set of C++ code fragments, in order to
        write each one to the implementation file.

        :param implementation: the list of code fragments (represented
               by dictionaries)
        :returns: nothing
        """
        num = len(implementation)
        self.up_indent()
        for i in range(0, num):
            this_impl = implementation[i]
            if len(this_impl) == 0:
                self.down_indent()
                return
            else:
                if 'code_type' in this_impl:
                    self.write_implementation_block(this_impl['code_type'],
                                                    this_impl['code'])
                    if i < num - 1:
                        self.skip_line()
                else:
                    self.write_line('{0};'.format(this_impl))
        self.down_indent()

    def write_lines(self, code):
        """
        Write a number of code lines

        :param code: the list of code lines to write.
        :returns: nothing
        """
        for i in range(0, len(code)):
            self.write_line('{0};'.format(code[i]))

    def write_comments(self, code):
        """
        Write a number of comment lines

        :param code: the list of comment text items to write.
        :returns: nothing
        """
        for i in range(0, len(code)):
            self.write_line('// {0}'.format(code[i]))

    def write_if_else_block(self, code):
        """
        Write a C/C++ if/else if/else block

        :param code: list of conditions to write
        :returns: nothing
        """
        if_code = [code[0]]
        i = 1
        num = len(code)
        while i < num and code[i] != 'else':
            if_code.append(code[i])
            i += 1
        self.write_block('if', if_code, True)
        self.write_block('else', code[i + 1: num], False)

    def write_else_if_block(self, code):
        """
        Write a C/C++ "else if" block

        :param code: list of code fragments to write
        :returns: nothing
        """
        code_len = len(code)
        if_code = [code[0]]
        i = 1  # index of code fragment in the list
        while i < code_len and code[i] != 'else if':
            if_code.append(code[i])
            i += 1
        self.write_block('if', if_code, True)
        i += 1
        else_if_code = [code[i]]
        i += 1
        while i < code_len:
            while i < code_len and \
                    (code[i] != 'else if' and code[i] != "else"):
                else_if_code.append(code[i])
                i += 1
            self.write_block('else if', else_if_code, True)
            if i < code_len:
                flag_else = (code[i] == 'else')
                if not flag_else:
                    if i < code_len:
                        i += 1
                        else_if_code = [code[i]]
                        i += 1
                else:
                    self.write_block('else', code[i + 1: code_len], False)
                    break

    def write_try_block(self, code):
        """
        Write a C++ try/catch block.

        :param code: the code to put in the block
        :returns: nothing
        """
        try_code = [code[0]]
        i = 1
        while i < len(code) and code[i] != 'catch':
            try_code.append(code[i])
            i += 1
        self.write_block('try', try_code, False)
        self.write_block('catch', code[i + 1: len(code)], True)

    def write_block(self, block_start, code, condition):
        """
        Generic function for writing a block of code.

        :param block_start: the first part of the block
        :param code: the list of code fragments to write
        :param condition: `True` if a condition applies, in which case
                the first entry in `code` is the condition.
        :returns: nothing
        """
        if condition:
            self.write_line('{0} ({1})'.format(block_start, code[0]))
            self.write_line('{')
            self.write_nested_implementation(code[1:len(code)])
            self.write_line('}')
        else:
            self.write_line('{0}'.format(block_start))
            self.write_line('{')
            self.write_nested_implementation(code)
            self.write_line('}')

    ######################################################################

    # HELPER FUNCTIONS

    @staticmethod
    def open_single_comment(self):
        """
        Open a C-style comment.

        TODO: self.num_tabs is defined in the parent class. So,
        the definition of a tab (here, two space chars)
        should probably be be defined globally, and perhaps have a
        setter method also (only if needed).

        :returns: nothing
        """
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}\n'.format(tabs, '/*'))

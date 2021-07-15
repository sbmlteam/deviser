#!/usr/bin/env python
#
# @file    CppExampleFile.py
# @brief   class for generating example code file for the given package
# @author  Frank Bergmann
# @author  Sarah Keating
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

from ..base_files import BaseCppFile

from ..util import query, strFunctions, global_variables


class CppExampleFile(BaseCppFile.BaseCppFile):
    """Class for all Cpp Example files"""

    def __init__(self, pkg_object):
        self.name = '{0}_example1'.format(pkg_object['name'])
        self.brief_description = \
            'Implementation  of the example code for the {0} package' \
            '.'.format(pkg_object['name'])
        BaseCppFile.BaseCppFile.__init__(self, self.name, 'cpp',
                                         None)
        self.package = strFunctions.lower_first(pkg_object['name'])
        self.package_up = strFunctions.upper_first(pkg_object['name'])
        self.reqd = 'true'
        if not pkg_object['required']:
            self.reqd = 'false'

        self.object_tree = query.create_object_tree(pkg_object)

    ########################################################################
    # Write parts of the file
    def write_includes(self):
        self.skip_line()
        self.write_line_verbatim('#include <iostream>')
        self.skip_line()
        self.write_line_verbatim('#include \"sbml/SBMLTypes.h\"')
        self.write_line_verbatim('#include \"sbml/packages/{0}/common/'
                                 '{1}Extension'
                                 'Types.h\"'.format(self.package,
                                                    self.package_up))

    def write_function(self):
        implementation = ['argc != 2',
                          'std::cout << \"Usage: '
                          '{0}_example1\\n\"'.format(self.package),
                          'return 1']
        code = [self.create_code_block('if', implementation)]
        code.append(self.create_code_block('line',
                                           ['SBMLNamespaces sbmlns(3, 1, '
                                            '\"{0}\", 1)'
                                            ''.format(self.package)]))
        code.append(self.create_code_block('line',
                                           ['SBMLDocument *document = new '
                                            'SBMLDocument(&sbmlns)']))
        code.append(self.create_code_block('line',
                                           ['document->setPackageRequired'
                                            '(\"{0}\", {1})'
                                            ''.format(self.package,
                                                      self.reqd)]))
        for i in range(0, len(self.object_tree)):
            self.write_code_for_plugin(i, code)

        code.append(self.create_code_block('line',
                                           ['writeSBML(document, \"{0}_'
                                            'example1'
                                            '.xml\")'.format(self.package),
                                            'delete document']))
        code.append(self.create_code_block('line',
                                           ['return 0']))


        return dict({'title_line': self.name,
                     'params': ['int argc', 'char** argv'],
                     'return_lines': [],
                     'additional': [],
                     'function': 'main',
                     'return_type': 'int',
                     'arguments': ['int argc', 'char** argv'],
                     'constant': False,
                     'virtual': False,
                     'object_name': None,
                     'implementation': code})

    def write_code_for_plugin(self, i, code):
        parent = self.object_tree[i]['base']
        parent_name = strFunctions.lower_first(parent)
        abbrev = strFunctions.abbrev_name(parent)
        plugin_class = '{0}{1}Plugin'.format(self.package_up, parent)
        plugin_name = '{0}plugin'.format(abbrev)

        code.append(self.create_code_block('line',
                                           ['{0}* {1} = document->create{0}()'
                                            ''.format(parent, parent_name)]))

        code.append(self.create_code_block('line',
                                           ['{0}* {1} =  static_cast<{0}*>'
                                            '({2}->getPlugin(\"{3}\"))'
                                            ''.format(plugin_class, plugin_name,
                                                      parent_name,
                                                      self.package)]))
        for j in range(0, len(self.object_tree[i]['children'])):
            self.write_code_for_children(plugin_name,
                                         self.object_tree[i]['children'][j],
                                         code)

    def write_code_for_children(self, parent, child, code):
        abbrev = strFunctions.abbrev_name(child['name'])
        childname = strFunctions.upper_first(child['name'])
        if child['name'] == 'math':
            code.append(self.create_code_block('line',
                                               ['ASTNode* math = SBML_parse'
                                                'L3Formula(\"TBC\")',
                                                '{0}->setMath(math)'
                                                ''.format(parent)]))
        else:
            code.append(self.create_code_block('line',
                                               ['{0}* {1} = {2}->create{0}()'
                                                ''.format(childname, abbrev,
                                                          parent)]))
        if 'attribs' in child:
            self.write_code_for_reqd_attributes(abbrev, child, code)
        for i in range(0, len(child['children'])):
            self.write_code_for_children(abbrev, child['children'][i], code)

    def write_code_for_reqd_attributes(self, abbrev, child, code):
        implementation = []
        for i in range(0, len(child['attribs'])):
            attrib = child['attribs'][i]
            att_type = attrib['type']
            if att_type == 'element' or att_type == 'lo_element':
                continue
            name = strFunctions.upper_first(attrib['name'])
            if query.is_number(att_type):
                value = 'FIXME'
            elif attrib['type'] == 'bool':
                value = 'false'
            else:
                value = '\"FIXME\"'
            implementation.append('{0}->set{1}({2})'.format(abbrev, name, value))
        if implementation:
            code.append(self.create_code_block('line',
                                               implementation))


    def add_disclaimer(self):
        self.open_comment()
        self.write_comment_line('****************************************************')
        self.write_blank_comment_line()
        self.write_comment_line('CODE HERE IS EXPERIMENTAL AND MAY REQUIRE ADJUSTMENT')
        self.write_blank_comment_line()
        self.write_comment_line('****************************************************')
        self.close_comment()


    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code

    ########################################################################

    # Write file

    def write_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_includes()
        self.write_cppns_use()
        self.add_disclaimer()
        code = self.write_function()
        self.write_function_implementation(code)


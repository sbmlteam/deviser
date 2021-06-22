#!/usr/bin/env python
#
# @file    BaseTexFile.py
# @brief   base class for all tex files to be generated
# @author  Frank Bergmann
# @author  Sarah Keating
# @author Matthew S. Gillman
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
from ..util import strFunctions


class BaseTexFile(BaseFile.BaseFile):
    """Common base class for all LaTeX files"""

    def __init__(self, name, extension, object_desc):
        """
        Constructor

        :param name: name of file (before dot and extension)
        :param extension: file extension (without dot, e.g. "tex").
        :param object_desc:
        """
        BaseFile.BaseFile.__init__(self, name, extension)

        # change the comment delimiter and line length
        self.comment = '%'
        self.line_length = 72

        self.package = object_desc['name']
        self.fullname = object_desc['fullname']
        self.sbml_classes = object_desc['baseElements']
        self.offset = object_desc['offset']
        self.plugins = object_desc['plugins']
        self.enums = object_desc['enums']
        self.level = object_desc['base_level']
        self.version = object_desc['base_version']
        self.pkg_version = object_desc['pkg_version']
        if object_desc['required']:
            self.reqd_status = 'true'
        else:
            self.reqd_status = 'false'

        self.prim_class = []

        self.start_b = '{'
        self.end_b = '}'

        # expand the information for the classes
        self.fulltexname = strFunctions.texify(self.fullname)
        self.upper_package = strFunctions.upper_first(self.package)
        self.sort_class_names(self.sbml_classes)
        self.sort_attribute_names(self.sbml_classes)
        self.sort_enum_names(self.enums)

        self.full_pkg_command = '\\{0}Package'.format(self.fulltexname)
        self.brief_pkg_command = '\\{0}'.format(self.upper_package)

    ########################################################################

    def sort_class_names(self, classes):
        """
        Function to create texnames for classes.

        :param classes: list of objects (dictionaries) representing classes.
        """
        if classes is not None:
            for i in range(0, len(classes)):
                name = classes[i]['name']
                texname = strFunctions.texify(name)
                classes[i]['texname'] = texname
                # hack for render
                if name == 'Ellipse' or name == 'Rectangle':
                    texname = 'Render' + name
                    classes[i]['texname'] = texname
                if name == 'RelAbsVector':
                    self.prim_class.append(classes[i])

    @staticmethod
    def sort_attribute_names(classes):
        """
        Function to create texnames for attributes.

        :param classes:
        """
        if classes is not None:
            for i in range(0, len(classes)):
                attribs = classes[i]['attribs']
                BaseTexFile.update_attrib_dicts(attribs)
                # for j in range(0, len(attribs)):
                #     if attribs[j]['type'] in ['lo_element', 'element',
                #                               'inline_lo_element']:
                #         name = attribs[j]['element']
                #     else:
                #         name = attribs[j]['name']
                #     texname = strFunctions.texify(name)
                #     attribs[j]['texname'] = texname
            for i in range(0, len(classes)):
                if 'lo_attribs' in classes[i]:
                    lo_attribs = classes[i]['lo_attribs']
                    BaseTexFile.update_attrib_dicts(lo_attribs)
                    # for j in range(0, len(lo_attribs)):
                    #     if lo_attribs[j]['type'] in ['lo_element', 'element',
                    #                                  'inline_lo_element']:
                    #         name = lo_attribs[j]['element']
                    #     else:
                    #         name = lo_attribs[j]['name']
                    #     texname = strFunctions.texify(name)
                    #     lo_attribs[j]['texname'] = texname

    @staticmethod
    def update_attrib_dicts(my_list):
        """
        Update a list of attribute dictionaries.

        :param my_list: the list which we update.
        """
        for j in range(0, len(my_list)):
            if my_list[j]['type'] in ['lo_element', 'element',
                                      'inline_lo_element']:
                name = my_list[j]['element']
            else:
                name = my_list[j]['name']
            texname = strFunctions.texify(name)
            my_list[j]['texname'] = texname

    @staticmethod
    def sort_enum_names(enums):
        """
        Function to create texnames for enums

        :param enums:
        """
        if enums is not None:
            for i in range(0, len(enums)):
                name = enums[i]['name']
                texname = strFunctions.texify(name)
                enums[i]['texname'] = texname

    def write_to_do(self, text):
        """
        Function to write a to do into text
        i.e. \todo{text goes here}

        :param text: the text describing the TODO.
        """
        self.write_text_line('\\TODO{0}{1}{2}'.format(self.start_b, text,
                                                      self.end_b))
        self.skip_line()

    def write_text_line(self, line):
        """
        Need to overwrite the write_text_line function to not add indents

        :param line: the line of text to write
        """
        self.write_text_no_indent(line)

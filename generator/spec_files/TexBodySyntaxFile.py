#!/usr/bin/env python
#
# @file    TexBodySyntaxFile.py
# @brief   class for generating the LaTeX body file
#            describing the various classes used
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

import os
import re

from base_files import BaseTexFile
from util import strFunctions, global_variables


class TexBodySyntaxFile(BaseTexFile.BaseTexFile):
    """Class for the validation appendix in LaTeX"""

    def __init__(self, object_desc):

        # derived members for description
        self.brief_description = 'Syntax section for specification'

        # global member to keep track of classes written
        self.classes_written = []

        BaseTexFile.BaseTexFile.__init__(self, 'body', 'tex',
                                         object_desc)
        self.sort_attribute_names(self.plugins)
        # self.full_pkg_command = '\\{}Package'.format(self.fulltexname)
        # self.brief_pkg_command = '\\{}'.format(self.upper_package)

    ########################################################################
    # Write rules for an extended class

    def write_body_for_extended_class(self, plugin):
        extended_object = plugin['sbase']
        ex_objects = []
        for i in range(0, len(plugin['extension'])):
            name = plugin['extension'][i]['name']
            indef = strFunctions.get_indefinite(name)
            ex_objects.append('{0} \\{1} object'.format(indef, name))
        for i in range(0, len(plugin['lo_extension'])):
            name = plugin['lo_extension'][i]['listOfClassName']
            ex_objects.append('a \\{0} object'.format(name))
        if len(plugin['attribs']) > 0:
            ex_objects.append('the following attributes.')
        # section heading
        self.write_comment_line('---------------------------------------------'
                                '------------')
        self.write_line('\subsection{0}The extended \class{0}{1}{2} class{2}'
                        .format(self.start_b, plugin['sbase'], self.end_b))
        self.write_line('\\label{0}{1}{2}'
                        .format(self.start_b,
                                strFunctions.make_class(plugin['sbase']),
                                self.end_b))
        self.skip_line()
        self.write_figure('extended', plugin['sbase'])
        self.skip_line()
        self.write_to_do('explain where {0} comes from'.format(extended_object))

        self.write_line('The {0} extends the \\class{1}{2}{3} object '
                        'with the addition of '
                        .format(self.full_pkg_command, self.start_b,
                                extended_object, self.end_b))
        num_additions = len(ex_objects)
        if num_additions > 1:
            self.write_line('{0}'.format(ex_objects[0]))
            for i in range(1, num_additions-1):
                self.write_line(', {0}'.format(ex_objects[i]))
            self.write_line(' and {0}.'.format(ex_objects[num_additions-1]))
        elif num_additions == 1:
            self.write_line('{0}.'.format(ex_objects[0]))
        self.skip_line()

        for i in range(0, len(plugin['attribs'])):
            self.write_attibute_paragraph(plugin['attribs'][i],
                                          extended_object)

        # write body for child elements
        for i in range(0, len(plugin['extension'])):
            child = self.get_class(plugin['extension'][i]['name'])
            self.write_body_for_class(child)

        for i in range(0, len(plugin['lo_extension'])):
            child = self.get_class(plugin['lo_extension'][i]['name'])
            self.write_body_for_lo_class(child)

    ########################################################################
    # Write body for a list of class

    def write_body_for_lo_class(self, sbml_class, nested=False):
        lo_name = 'default'
        if sbml_class['hasListOf']:
            if 'lo_elementName' in sbml_class \
                    and sbml_class['lo_elementName'] != '':
                lo_name = strFunctions.upper_first(
                    sbml_class['lo_elementName'])
            else:
                lo_name = strFunctions.cap_list_of_name(sbml_class['name'])

        # do not write if already written
        if lo_name in self.classes_written:
            return
        self.classes_written.append(lo_name)

        if 'texname' in sbml_class:
            classname = sbml_class['texname']
        else:
            classname = sbml_class['name']

        self.write_comment_line('---------------------------------------------'
                                '------------')
        self.write_line('\subsection{0}The \class{0}{1}{2} class{2}'
                        .format(self.start_b, lo_name, self.end_b))
        self.write_line('\label{0}{1}-class{2}'
                        .format(self.start_b, lo_name.lower(), self.end_b))
        self.skip_line()
        self.write_to_do('explain {0}'.format(lo_name))

        if 'min_lo_children' not in sbml_class:
            number = 'one'
        elif sbml_class['min_lo_children'] == 1:
            number = 'one'
        else:
            number = strFunctions.replace_digits(str(
                sbml_class['min_lo_children'])).lower()

        self.write_line('The \\{0} object derives from the \\class{1}SBase{2}'
                        ' and inherits the core attributes and subobjects '
                        'from that class.  It contains '
                        '{4} or more objects of type \\{3}.'
                        .format(lo_name, self.start_b, self.end_b, classname,
                                number))
        self.skip_line()

        written = False
        for i in range(0, len(sbml_class['lo_attribs'])):
            if not written:
                self.write_line('In addition the  \\{0} object has the '
                                'following attributes.'
                                .format(lo_name))
                self.skip_line()
                written = True
            att = sbml_class['lo_attribs'][i]
            self.write_attibute_paragraph(att, lo_name)

        if not nested:
            self.write_body_for_class(self.get_class(sbml_class['name']))

    ########################################################################
    # Write body for a class

    def write_body_for_class(self, sbml_class):
        if sbml_class['hasListOf']:
            self.write_body_for_lo_class(sbml_class, True)
        if sbml_class['name'] in self.classes_written:
            return
        self.classes_written.append(sbml_class['name'])
        base_class = self.look_up_base_class(sbml_class['baseClass'])
        if 'texname' in sbml_class:
            classname = sbml_class['texname']
        else:
            classname = sbml_class['name']
        # section heading
        self.write_comment_line('---------------------------------------------'
                                '------------')
        self.write_line('\subsection{0}The \class{0}{1}{2} class{2}'
                        .format(self.start_b, sbml_class['name'], self.end_b))
        self.write_line('\label{0}{1}-class{2}'
                        .format(self.start_b, classname.lower(),
                                self.end_b))
        self.skip_line()
        self.write_figure('class', classname)
        self.skip_line()
        self.write_to_do('explain {0}'.format(sbml_class['name']))

        if len(sbml_class['attribs']) == 0:
            self.write_line('The \\{0} object derives from the '
                            '\\{1} class and thus inherits any '
                            'attributes and elements that are present on '
                            'this class.'.format(classname, base_class))
            return

        self.write_line('The \\{0} object derives from the '
                        '\\{1} class and thus inherits any '
                        'attributes and elements that are present on '
                        'this class.'
                        .format(classname, base_class))

        child_elements = []
        child_attribs = []
        for i in range(0, len(sbml_class['attribs'])):
            att = sbml_class['attribs'][i]
            att_type = att['type']
            if att_type == 'element' and att['element'] != 'RelAbsVector':
                child_elements.append(att)
            elif att_type == 'lo_element' or att_type == 'inline_lo_element':
                child_elements.append(att)
            else:
                child_attribs.append(att)

        for i in range(0, len(child_elements)):
            self.write_child_element(child_elements[i], classname)

        written = False
        for i in range(0, len(child_attribs)):
            if not written:
                self.write_line('In addition the  \\{0} object has the '
                                'following attributes.'
                                .format(classname))
                self.skip_line()
                written = True
            att = child_attribs[i]
            self.write_attibute_paragraph(att, classname)

    # Write rules for an attribute
    def write_attibute_paragraph(self, attrib, name):
        att_name = attrib['texname']
        if attrib['type'] == 'lo_element' \
                or attrib['type'] == 'inline_lo_element':
            return
        elif attrib['type'] == 'element' \
                and attrib['element'] != 'RelAbsVector':
            return
        else:
            self.write_line('\paragraph{0}The \\fixttspace\\token{0}{1}{2} '
                            'attribute{2}'.format(self.start_b, att_name,
                                                  self.end_b))
            self.skip_line()
            self.write_line('{0} \{1} has {2} attribute {3} {4}.'
                            .format(strFunctions.get_indefinite(name).
                                    capitalize(),
                                    name,
                                    'a required' if attrib['reqd'] is True
                                    else 'an optional',
                                    strFunctions.wrap_token(att_name),
                                    strFunctions.wrap_type(attrib['type'],
                                                           attrib['element'],
                                                           True)))
            if attrib['type'] == 'SIdRef':
                [string_name, a] = strFunctions.get_sid_refs(attrib['element'])
                self.write_line('This attribute must be the identifier of '
                                'an existing \{0} object.'.format(string_name))
            self.write_to_do('explain {0}'.format(att_name))
        self.skip_line()

    def write_child_element(self, attrib, name):
        if attrib['type'] == 'element':
            if self.derives_from_other_ns(attrib['element']):
                child_name = '\\class{' + attrib['element'] + '}'
            else:
                child_name = '\\' + attrib['element']
        elif attrib['type'] == 'lo_element':
            child_name = '\\' + strFunctions.cap_list_of_name(attrib['name'])
        elif attrib['type'] == 'inline_lo_element':
            child_name = '\\' + strFunctions.cap_list_of_name(attrib['name'])
        else:
            return

        # hack for render
        if child_name == '\\RelAbsVector':
            return

        self.write_line('{0} \{1} contains {2} {3} element.'
                        .format(strFunctions.get_indefinite(name).
                                capitalize(), name,
                                'at most one' if attrib['reqd'] is True
                                else 'exactly one', child_name))

    ########################################################################
    # write parts of file that can be copied from text

    def get_text(self, filename):
        file_in = open(os.path.dirname(__file__) + '/' + filename, 'r')
        intro = file_in.read()
        file_in.close()
        intro = re.sub('PACKAGENAME', self.full_pkg_command, intro)
        intro = re.sub('LEVELNUM', str(self.level), intro)
        intro = re.sub('VERSIONNUM', str(self.version), intro)
        intro = re.sub('REQUIRED', self.reqd_status, intro)
        return intro

    # Write namespace section
    def write_namespace_section(self):
        self.write_line('\\subsection{Namespace URI and other declarations '
                        'necessary for using this package}')
        self.write_line('\\label{xml-namespace}')
        self.skip_line()
        self.write_line(self.get_text('body_ns_section.txt'))
        self.skip_line()
        self.write_line('\\begin{center}')
        self.write_line('\\uri{0}http://www.sbml.org/sbml/level{1}/'
                        'version{2}/{3}/version{4}{5}'
                        .format(self.start_b, self.level, self.version,
                                self.package, self.pkg_version, self.end_b))
        self.write_line('\\end{center}')
        self.skip_line()
        self.write_line(self.get_text('body_ns_section2.txt'))
        self.skip_line()
        self.write_figure('complete')

    #########################################################################
    # Write data types section
    def write_primitive_data_types(self):
        self.write_line('\\subsection{Primitive data types}')
        self.write_line('\\label{primitive-types}')
        self.skip_line()
        self.write_line('Section~3.1 of the SBML Level~3 specification '
                        'defines a number of primitive data types and also '
                        'uses a number of XML Schema 1.0 data types '
                        '\\citep{0}biron:2000{1}.  We assume and use some of '
                        'them in the rest of this specification, specifically '
                        '\\primtype{0}boolean{1}, \\primtype{0}ID{1}, '
                        '\\primtype{0}SId{1}, \\primtype{0}SIdRef{1}, and '
                        '\\primtype{0}string{1}. The \\{2} Package defines '
                        'other primitive types; these are described below.'
                        .format(self.start_b, self.end_b, self.fulltexname))
        self.skip_line()
        self.write_to_do('check all necessary types from core are listed')
        for i in range(0, len(self.enums)):
            self.write_enum_type(self.enums[i])
        for i in range(0, len(self.prim_class)):
            self.write_prim_class(self.prim_class[i])

    # write sub section for a primitive class type
    def write_prim_class(self, prim_class):
        self.write_line('\\subsubsection{0}Type \\fixttspace'
                        '\\primtypeNC{0}{1}{2}{2}'
                        .format(self.start_b, prim_class['name'], self.end_b))
        self.skip_line()
        written = False
        for i in range(0, len(prim_class['attribs'])):
            if not written:
                self.write_line('The  \\{0} object has the '
                                'following attributes.'
                                .format(prim_class['name']))
                self.skip_line()
                written = True
            att = prim_class['attribs'][i]
            self.write_attibute_paragraph(att, prim_class['name'])
        self.write_to_do('Explain use of {0}'.format(prim_class['name']))

    # write sub section for an enum type
    def write_enum_type(self, enum):
        self.write_line('\\subsubsection{0}Type \\fixttspace'
                        '\\primtypeNC{0}{1}{2}{2}'
                        .format(self.start_b, enum['texname'], self.end_b))
        self.skip_line()
        self.write_figure('enum', enum['texname'])
        self.skip_line()
        self.write_line('The \\primtype{0}{1}{2} is an emueration of values '
                        'used '
                        'to ... '.format(self.start_b, enum['texname'],
                                         self.end_b))
        self.write_to_do('Explain use of {0}'.format(enum['texname']))
        self.write_line('The possible values are {0}.'
                        .format(self.list_values(enum)))
        self.skip_line()

    def list_values(self, enum):
        num_values = len(enum['values'])
        listed = '\\const{0}{1}{2}' \
                 ''.format(self.start_b,
                           enum['values'][0]['value'].replace("_", "\_"),
                           self.end_b)
        for i in range(1, num_values-1):
            replaced_value = enum['values'][i]['value'].replace("_", "\_")
            enum_value = ', \\const{0}{1}{2}' \
                         ''.format(self.start_b,
                                   replaced_value,
                                   self.end_b)
            listed += enum_value
        listed += ' and \\const{0}{1}{2}'\
            .format(self.start_b,
                    enum['values'][num_values-1]['value'].replace("_", "\_"),
                    self.end_b)
        return listed

    #######################################################################
    # Helper functions

    # function to return the texname of a base class
    def look_up_base_class(self, base):
        for item in self.sbml_classes:
            if item['name'] == base:
                if 'texname' in item:
                    return item['texname']
                else:
                    return item['name']
        return 'SBase'  # default

    # function to determine if the element belongs to this package
    def derives_from_other_ns(self, name):
        for item in self.sbml_classes:
            if item['name'] == name:
                return False
        return True

    # function to get the class by its name
    def get_class(self, name):
        for i in range(0, len(self.sbml_classes)):
            this_class = self.sbml_classes[i]
            if this_class['name'] == name:
                return this_class
            elif this_class['hasListOf'] is True:
                if strFunctions.cap_list_of_name(this_class['name']) == name:
                    return this_class
        return None

    # function to write a figure
    def write_figure(self, fig_type, name=''):
        imagewidth = 'scale=0.6'
        extension = '.pdf'
        if fig_type == 'complete':
            figname = '{0}_version_{1}_complete'.format(self.package,
                                                        self.pkg_version)
            caption = 'the \\{0}Package'.format(self.upper_package)
            imagewidth = 'width=0.9\\textwidth'

            current = global_variables.current_dir + '/figures/'
            current += figname
            current += '.pdf'
            if not os.path.exists(current) or os.path.getsize(current) == 0:
                extension = '.png'

        elif fig_type == 'enum':
            figname = '{0}_type_enum_{1}_uml'.format(self.package,
                                                     name.lower())
            caption = 'the \\{0} type for the \\{1}Package' \
                      ''.format(name, self.upper_package)
        elif fig_type == 'extended':
            figname = '{0}_extended_{1}_uml'.format(self.package,
                                                    name.lower())
            caption = 'the extended \\{0} class for the \\{1}Package' \
                      ''.format(name, self.upper_package)

        else:
            figname = '{0}_{1}_uml'.format(self.package,
                                           name.lower())
            caption = 'the \\{0} class for the \\{1}Package' \
                      ''.format(name, self.upper_package)

        if not global_variables.figures_present:
            self.write_comment_line('\\begin{figure}[ht!]')
            self.write_comment_line('  \\centering')
            self.write_comment_line('  \\includegraphics[{0}]'
                                    '{1}figures/{2}{3}{4}\\\\'
                                    ''.format(imagewidth, self.open_br, figname,
                                              extension, self.close_br))
            self.write_comment_line('  \\caption{0}A UML representation of '
                                    '{1}. '
                                    'See \\ref{0}conventions{2} for '
                                    'conventions related to this figure.  {2}'
                                    ''.format(self.open_br, caption,
                                              self.close_br))
            self.write_comment_line('  \\label{0}fig:{1}{2}'
                                    ''.format(self.open_br, figname,
                                              self.close_br))
            self.write_comment_line('\\end{figure}')
        else:
            self.write_line('\\begin{figure}[ht!]')
            self.write_line('  \\centering')
            self.write_line('  \\includegraphics[{0}]{1}figures/'
                            '{2}{3}{4}\\\\'.format(imagewidth, self.open_br,
                                                   figname,
                                                   extension, self.close_br))
            self.write_line('  \\caption{0}A UML representation of {1}. '
                            'See \\ref{0}conventions{2} for '
                            'conventions related to this figure.  {2}'
                            ''.format(self.open_br, caption, self.close_br))
            self.write_line('  \\label{0}fig:{1}{2}'.format(self.open_br,
                                                            figname,
                                                            self.close_br))
            self.write_line('\\end{figure}')
        self.skip_line()

    #######################################################################
    # Write file

    def write_file(self):
        BaseTexFile.BaseTexFile.write_file(self)

        self.write_line('\\section{Package syntax and semantics}')
        self.skip_line()
        self.write_line('In this section, we define the syntax and '
                        'semantics of the {0} for '
                        '\\sbmlthreecore. We expound on the various data '
                        'types and constructs defined in this package, '
                        'then in {1}, we provide complete '
                        'examples of using the constructs in example '
                        'SBML models.'.format(self.full_pkg_command,
                                              strFunctions.wrap_section(
                                                  'examples', False)))
        self.skip_line()

        self.write_namespace_section()
        self.write_primitive_data_types()
        for i in range(0, len(self.plugins)):
            self.write_body_for_extended_class(self.plugins[i])
        for i in range(0, len(self.sbml_classes)):
            # hack for render
            if self.sbml_classes[i]['name'] != 'RelAbsVector':
                self.write_body_for_class(self.sbml_classes[i])

    # override
    def add_file_header(self):
        self.write_comment_line('-*- TeX-master: "main"; fill-column: 72 -*-')

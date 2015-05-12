#!/usr/bin/python

import BaseTexFile
import BaseFile
import strFunctions
import re


class TexMacrosFile(BaseTexFile.BaseTexFile):
    """Class for the definition of class name macros in LaTeX"""

    def __init__(self, object_desc):

        # derived members for description
        self.brief_description = 'Macros definition for specification'

        BaseTexFile.BaseTexFile.__init__(self, 'macros', 'tex', object_desc)

        # self.full_pkg_command = '\\{}Package'.format(self.fulltexname)
        # self.brief_pkg_command = '\\{}'.format(self.upper_package)

    ########################################################################

    # Write the command for each class
    def write_macro_for_class(self, sbml_class):
        self.write_line('\\newcommand{0}\\{1}{2}{0}\\defRef{0}{4}{2}'
                        '{0}{3}{2}{2}'
                        .format(self.start_b, sbml_class['texname'],
                                self.end_b,
                                strFunctions.make_class(sbml_class['texname']),
                                sbml_class['name']))

    # Write commands for each ListOf class
    def write_macro_for_listof(self, sbml_class):
        if sbml_class['hasListOf']:
            if 'lo_elementName' in sbml_class \
                    and sbml_class['lo_elementName'] != '':
                lo_name = strFunctions.upper_first(
                    sbml_class['lo_elementName'])
            else:
                lo_name = strFunctions.cap_list_of_name(sbml_class['name'])
            self.write_line('\\newcommand{0}\\{1}{2}{0}\\defRef{0}{1}{2}'
                            '{0}{3}{2}{2}'
                            .format(self.start_b, lo_name, self.end_b,
                                    strFunctions.make_class(lo_name)))
            # hack for render
            if sbml_class['name'] == 'GradientBase':
                self.write_line('\\newcommand{0}\\{4}{2}{0}\\defRef{0}{1}{2}'
                                '{0}{3}{2}{2}'
                                .format(self.start_b, lo_name, self.end_b,
                                        strFunctions.make_class(lo_name),
                                        'ListOfGradientBases'))
            elif sbml_class['name'] == 'RenderPoint':
                self.write_line('\\newcommand{0}\\{4}{2}{0}\\defRef{0}{1}{2}'
                                '{0}{3}{2}{2}'
                                .format(self.start_b, lo_name, self.end_b,
                                        strFunctions.make_class(lo_name),
                                        'ListOfRenderPoints'))

    # Write commands for each primitive type
    def write_macro_for_enum(self, enum):
        # check for underscores
        cmd_name = re.sub('_t', 't', enum['name'])
        self.write_line('\\newcommand{0}\\{1}{2}{0}\\defRef{0}{3}{2}'
                        '{0}{4}{2}{2}'
                        .format(self.start_b, cmd_name,
                                self.end_b, enum['name'],
                                'primitive-types'))

    # Write commands for each plugin
    def write_macro_for_plugin(self, plugin):
        self.write_line('\\newcommand{0}\\{1}{2}{0}\\defRef{0}{4}{2}'
                        '{0}{3}{2}{2}'
                        .format(self.start_b, plugin['sbase'],
                                self.end_b,
                                strFunctions.make_class(plugin['sbase']),
                                plugin['sbase']))

    # Write general commands
    def write_general_commands(self):
        self.write_comment_line('\\newcommand{\\fixttspace}{\\hspace*{1pt}}')

        self.write_line('\\newcommand{0}\\const{1}[1]{0}\\texttt{0} #1{1}{1}'
                        .format(self.start_b, self.end_b))
        self.skip_line()
        self.write_line('\\newcommand{0}\\sbmlthreecore{1}{0}SBML Level~{2} '
                        'Version~{3} Core\\xspace{1}'.format(self.start_b,
                                                             self.end_b,
                                                             self.level,
                                                             self.version))
        self.write_line('\\newcommand{0}{1}{2}{0}\\textsf{0}{3}'
                        '{2} package\\xspace{2}'.format(self.start_b,
                                                        self.full_pkg_command,
                                                        self.end_b,
                                                        self.fullname))
        self.write_line('\\newcommand{0}{1}{2}{0}\\textsf{0}{1}{2}'
                        '\\xspace{2}'
                        .format(self.start_b,
                                self.brief_pkg_command,
                                self.end_b))
        self.skip_line()
        self.write_line('\\newcommand{0}\\TODO{1}[1]{0}\\colorbox{0}blue{1}'
                        '{0}\\textcolor{0}white{1}{0}TODO: #1{1}{1}{1}'
                        .format(self.start_b, self.end_b))
        self.skip_line()

    #########################################################################
    # Write file

    def write_file(self):
        BaseFile.BaseFile.write_file(self)
        self.write_general_commands()
        self.skip_line()
        self.write_comment_line('commands for classes')
        for i in range(0, len(self.sbml_classes)):
            # hack for render
            if self.sbml_classes[i]['name'] != "RelAbsVector":
                self.write_macro_for_class(self.sbml_classes[i])
        self.skip_line()
        self.write_comment_line('commands for listOfClasses')
        for i in range(0, len(self.sbml_classes)):
            self.write_macro_for_listof(self.sbml_classes[i])
        self.skip_line()
        self.write_comment_line('commands for types')
        for i in range(0, len(self.enums)):
            self.write_macro_for_enum(self.enums[i])
        for i in range(0, len(self.prim_class)):
            self.write_macro_for_enum(self.prim_class[i])
        self.skip_line()
        self.write_comment_line('commands for plugins')
        for i in range(0, len(self.plugins)):
            self.write_macro_for_plugin(self.plugins[i])

    # override
    def add_file_header(self):
        self.skip_line()

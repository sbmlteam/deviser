#!/usr/bin/python

import re
import os
import BaseTexFile
import BaseFile
import ValidationRulesForClass
import ValidationRulesForPlugin
import strFunctions


class TexValidationRulesFile(BaseTexFile.BaseTexFile):
    """Class for the validation appendix in LaTeX"""

    def __init__(self, object_desc):
        # derived members for description
        self.brief_description = 'Validation rules appendix for specification'

        # useful repeated text strings
        self.valid = '\\validRule{'
        self.consist = '\\consistencyRule{'

        BaseTexFile.BaseTexFile.__init__(self, 'apdx-validation', 'tex',
                                         object_desc)
        self.full_pkg_command = '\\{}Package'.format(self.fulltexname)
        self.brief_pkg_command = '\\{}'.format(self.upper_package)

        self.pkg_ref = 'SBML Level~{} Package specification for {}, ' \
                       'Version~{}'.format(self.level,
                                           self.fullname, self.pkg_version)

    ########################################################################

    # Write a rule
    def write_rule(self, rule, name='', texname=''):
        substitute_name = False
        if name != texname:
            substitute_name = True

        text = rule['text']
        ref = rule['reference']
        if substitute_name:
            text = re.sub(name, texname, text)
            ref = re.sub(name.lower(), texname.lower(), ref)

        if rule['severity'] == 'ERROR':
            severity = self.valid
        else:
            severity = self.consist

        self.write_line('{}{}-{}{}{}{} (Reference: {}){}'
                        .format(severity, self.package,
                                rule['number']-self.offset,
                                self.end_b, self.start_b, text,
                                ref, self.end_b))

    ####################################################################
    # Write general rules
    def write_general_rules(self):
        self.write_line('\subsubsection*{General rules about this package}')
        self.skip_line()
        text = 'To conform to the {0} specification for SBML Level~{1} ' \
               'Version~{2}, an SBML document must declare the use of the ' \
               'following XML Namespace: \\uri{3}http://www.sbml.org/sbml/' \
               'level{1}/version{2}/{4}/version{5}{6}.'\
            .format(self.full_pkg_command, self.level, self.version,
                    self.start_b, self.package, self.pkg_version, self.end_b)
        ref = '{} {}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('xml-namespace', False))
        rule = {'severity': 'ERROR', 'number': 10101+self.offset,
                'text': text, 'reference': ref}
        self.write_rule(rule)
        self.skip_line()
        text = 'Wherever they appear in an SBML document, elements and ' \
               'attributes from the {} package must be declared either ' \
               'implicitly or explicitly to be in the XML namespace ' \
               '\\uri{}http://www.sbml.org/sbml/level{}/version{}' \
               '/{}/version{}{}.'\
            .format(self.full_pkg_command, self.start_b, self.level,
                    self.version, self.package, self.pkg_version, self.end_b)
        # same ref
        rule = {'severity': 'ERROR', 'number': 10102+self.offset,
                'text': text, 'reference': ref}
        self.write_rule(rule)
        self.skip_line()

    # Write general rules
    def write_extended_sbml_rules(self):
        self.write_line('\subsubsection*{Rules for the '
                        'extended \\class{SBML} class}')
        self.skip_line()
        text = 'In all SBML documents using the \\{}Package, the ' \
               '\\class{}SBML{} object must have the {} attribute.'\
            .format(strFunctions.upper_first(self.package), self.start_b,
                    self.end_b,
                    strFunctions.wrap_token('required', self.package))
        ref = 'SBML Level~3 Version~1 Core, Section~4.1.2.'
        rule = {'severity': 'ERROR', 'number': 20101 + self.offset,
                'text': text, 'reference': ref}
        self.write_rule(rule)
        self.skip_line()
        text = 'The value of attribute {0} on the \\class{1}SBML{2} object ' \
               'must be of data type \\primtype{1}boolean{2}.' \
            .format(strFunctions.wrap_token('required', self.package),
                    self.start_b, self.end_b)
        ref = 'SBML Level~3 Version~1 Core, Section~4.1.2.'
        rule = {'severity': 'ERROR', 'number': 20102 + self.offset,
                'text': text, 'reference': ref}
        self.write_rule(rule)
        self.skip_line()
        text = 'The value of attribute {0} on the \\class{1}SBML{2} object ' \
               'must be set to \\val{1}{3}{2}.' \
            .format(strFunctions.wrap_token('required', self.package),
                    self.start_b, self.end_b, 'false')
        ref = '{} {}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('xml-namespace', False))
        rule = {'severity': 'ERROR', 'number': 20103 + self.offset,
                'text': text, 'reference': ref}
        self.write_rule(rule)
        self.skip_line()

    #  Write identifier rules
    def write_identifier_rules(self):
        self.write_line(
            '\subsubsection*{General rules about identifiers}')
        self.skip_line()
        text = '(Extends validation rule \\#10301 in the \\sbmlthreecore ' \
               'specification. TO DO list scope of ids)'
        ref = '{} {}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('primitive-types', False))
        rule = {'severity': 'ERROR', 'number': 10301 + self.offset,
                'text': text, 'reference': ref}
        self.write_rule(rule)
        self.skip_line()
        text = 'The value of a {0} must conform to the syntax of ' \
               'the \\class{1}SBML{2} data type \\primtype{1}SId{2}'\
            .format(strFunctions.wrap_token('id', self.package),
                    self.start_b, self.end_b)
        # same ref
        rule = {'severity': 'ERROR', 'number': 10302 + self.offset,
                'text': text, 'reference': ref}
        self.write_rule(rule)
        self.skip_line()

    # Write rules for a class
    def write_rules_for_plugin(self, name, rules):
        # section heading
        self.write_line('\subsubsection*{Rules for extended \class{'
                        + '{}'.format(name) + '} object}')
        self.skip_line()

        for i in range(0, len(rules)):
            self.write_rule(rules[i])
            self.skip_line()

    # Write rules for a class
    def write_rules_for_class(self, name, texname, rules):
        # section heading
        self.write_line('\subsubsection*{Rules for \class{'
                        + '{}'.format(name) + '} object}')
        self.skip_line()

        for i in range(0, len(rules)):
            self.write_rule(rules[i], name, texname)
            self.skip_line()

    ########################################################################

    # write parts of file that can be copied from text

    def get_text(self, filename):
        file_in = open(os.path.dirname(__file__) + '/' + filename, 'r')
        intro = file_in.read()
        file_in.close()
        intro = re.sub('SHORTNAME', self.brief_pkg_command, intro)
        intro = re.sub('PACKAGENAME', self.full_pkg_command, intro)
        intro = re.sub('LEVELNUM', str(self.level), intro)
        intro = re.sub('VERSIONNUM', str(self.version), intro)
        intro = re.sub('PKGNAME', self.package, intro)
        return intro

    def write_introduction(self):
        self.write_line('\section{Validation of SBML documents}')
        self.write_line('\label{apdx-validation}')
        self.skip_line()
        self.write_line('\subsection{Validation and consistency rules}')
        self.write_line('\label{validation-rules}')
        self.skip_line()
        self.write_line(self.get_text('valid_intro_para1.txt'))
        self.skip_line()
        self.write_line('\\begin{description}')
        self.skip_line()
        self.write_line(self.get_text('valid_intro_para2.txt'))
        self.skip_line()
        self.write_line(self.get_text('valid_intro_para3.txt'))
        self.skip_line()
        self.write_line(self.get_text('valid_intro_para4.txt'))
        self.skip_line()
        self.write_line('\\end{description}')
        self.skip_line()
        self.write_line(self.get_text('valid_intro_para5.txt'))
        self.skip_line()
        self.write_line(self.get_text('valid_intro_para6.txt'))
        self.skip_line()

    ########################################################################
    # Write file

    def write_file(self):
        BaseFile.BaseFile.write_file(self)
        self.skip_line()
        self.write_introduction()
        self.write_general_rules()
        self.write_identifier_rules()
        self.write_to_do('ANY LIST OF ELEMENTS THAT HAVE ATTRIBUTES')
        self.write_extended_sbml_rules()
        number = self.offset + 20200
        for i in range(0, len(self.plugins)):
            rules = ValidationRulesForPlugin.ValidationRulesForPlugin(
                self.plugins[i], self.fullname, number,
                self.package, self.pkg_ref)
            rules.determine_rules()
            self.write_rules_for_plugin(self.plugins[i]['sbase'], rules.rules)
            self.skip_line()
            number += 100
        for i in range(0, len(self.sbml_classes)):
            # hack for render
            if self.sbml_classes[i]['name'] == 'RelAbsVector':
                continue
            rules = ValidationRulesForClass\
                .ValidationRulesForClass(self.sbml_classes[i],
                                         self.fullname, number, self.package,
                                         self.pkg_ref)
            rules.determine_rules()
            self.write_rules_for_class(self.sbml_classes[i]['name'],
                                       self.sbml_classes[i]['texname'],
                                       rules.rules)
            self.skip_line()
            number += 100

    # override
    def add_file_header(self):
        self.write_comment_line('-*- TeX-master: "main"; fill-column: 72 -*-')

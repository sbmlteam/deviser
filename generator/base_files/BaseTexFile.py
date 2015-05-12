#!/usr/bin/python


import BaseFile
import strFunctions


class BaseTexFile(BaseFile.BaseFile):
    """Common base class for all LaTeX files"""

    def __init__(self, name, extension, object_desc):
        BaseFile.BaseFile.__init__(self, name, extension)

        # change the comment delimiter and line length
        self.comment = '%'
        self.line_length = 72

        self.package = object_desc['name']
        self.fullname = object_desc['fullname']
        self.sbml_classes = object_desc['sbmlElements']
        self.offset = object_desc['offset']
        self.plugins = object_desc['plugins']
        self.enums = object_desc['enums']
        self.level = object_desc['sbml_level']
        self.version = object_desc['sbml_version']
        self.pkg_version = object_desc['pkg_version']

        self.prim_class = []

        self.start_b = '{'
        self.end_b = '}'

        # expand the information for the classes
        self.fulltexname = strFunctions.texify(self.fullname)
        self.upper_package = strFunctions.upper_first(self.package)
        self.sort_class_names(self.sbml_classes)
        self.sort_attribute_names(self.sbml_classes)
        self.sort_enum_names(self.enums)

        self.full_pkg_command = '\\{}Package'.format(self.fulltexname)
        self.brief_pkg_command = '\\{}'.format(self.upper_package)

    ########################################################################

    # function to create texnames for classes
    def sort_class_names(self, classes):
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

    # function to create texnames for attributes
    @staticmethod
    def sort_attribute_names(classes):
        if classes is not None:
            for i in range(0, len(classes)):
                attribs = classes[i]['attribs']
                for j in range(0, len(attribs)):
                    name = attribs[j]['name']
                    texname = strFunctions.texify(name)
                    attribs[j]['texname'] = texname
            for i in range(0, len(classes)):
                if 'lo_attribs' in classes[i]:
                    lo_attribs = classes[i]['lo_attribs']
                    for j in range(0, len(lo_attribs)):
                        name = lo_attribs[j]['name']
                        texname = strFunctions.texify(name)
                        lo_attribs[j]['texname'] = texname

    # function to create texnames for enums
    @staticmethod
    def sort_enum_names(enums):
        if enums is not None:
            for i in range(0, len(enums)):
                name = enums[i]['name']
                texname = strFunctions.texify(name)
                enums[i]['texname'] = texname

    # function to write a to do into text
    def write_to_do(self, text):
        self.write_line('\\TODO{}{}{}'.format(self.start_b, text, self.end_b))
        self.skip_line()

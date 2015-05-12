#!/usr/bin/python

import BaseFile
import strFunctions


class BaseCppFile(BaseFile.BaseFile):
    """Common base class for all c++ files"""

    def __init__(self, name, extension, attributes):
        BaseFile.BaseFile.__init__(self, name, extension)

        # members that might get overridden if creating another library
        self.baseClass = 'SBase'

        # expand the information for the attributes
        self.attributes = self.expand_attributes(attributes)

    ########################################################################

    # Function to expand the attribute information
    @staticmethod
    def expand_attributes(attributes):
        for i in range(0, len(attributes)):
            capname = strFunctions.upper_first(attributes[i]['name'])
            attributes[i]['capAttName'] = capname
            attributes[i]['memberName'] = 'm' + capname
            attributes[i]['pluralName'] = \
                strFunctions.plural(attributes[i]['name'])
            attributes[i]['isEnum'] = False
            att_type = attributes[i]['type']
            if att_type == 'SId' or att_type == 'SIdRef':
                attributes[i]['attType'] = 'string'
                attributes[i]['attTypeCode'] = 'std::string&'
                attributes[i]['CType'] = 'const char *'
                attributes[i]['isNumber'] = False
            elif att_type == 'UnitSId' or att_type == 'UnitSIdRef':
                attributes[i]['attType'] = 'string'
                attributes[i]['attTypeCode'] = 'std::string&'
                attributes[i]['CType'] = 'const char *'
                attributes[i]['isNumber'] = False
            elif att_type == 'string':
                attributes[i]['attType'] = 'string'
                attributes[i]['attTypeCode'] = 'std::string&'
                attributes[i]['CType'] = 'const char *'
                attributes[i]['isNumber'] = False
            elif att_type == 'double':
                attributes[i]['attType'] = 'double'
                attributes[i]['attTypeCode'] = 'double'
                attributes[i]['CType'] = 'double'
                attributes[i]['isNumber'] = True
            elif att_type == 'int':
                attributes[i]['attType'] = 'integer'
                attributes[i]['attTypeCode'] = 'int'
                attributes[i]['CType'] = 'int'
                attributes[i]['isNumber'] = True
            elif att_type == 'uint':
                attributes[i]['attType'] = 'unsigned integer'
                attributes[i]['attTypeCode'] = 'unsigned int'
                attributes[i]['CType'] = 'unsigned int'
                attributes[i]['isNumber'] = True
            elif att_type == 'bool' or att_type == 'boolean':
                attributes[i]['attType'] = 'boolean'
                attributes[i]['attTypeCode'] = 'bool'
                attributes[i]['CType'] = 'int'
                attributes[i]['isNumber'] = False
            elif att_type == 'enum':
                attributes[i]['isEnum'] = True
                attributes[i]['attType'] = 'enum'
                attributes[i]['attTypeCode'] = attributes[i]['element'] + '_t'
                attributes[i]['CType'] = attributes[i]['element'] + '_t'
                attributes[i]['isNumber'] = False
            elif att_type == 'element':
                attributes[i]['attType'] = 'element'
                if attributes[i]['name'] == 'math':
                    attributes[i]['attTypeCode'] = 'ASTNode*'
                    attributes[i]['CType'] = 'ASTNode_t*'
                else:
                    attributes[i]['attTypeCode'] = attributes[i]['element']+'*'
                    attributes[i]['CType'] = attributes[i]['element']+'_t*'
                attributes[i]['isNumber'] = False
            elif att_type == 'lo_element':
                name = strFunctions.list_of_name(attributes[i]['element'])
                attributes[i]['attType'] = 'lo_element'
                attributes[i]['attTypeCode'] = name
                attributes[i]['CType'] = name + '_t'
                attributes[i]['memberName'] = 'm' + name
                attributes[i]['isNumber'] = False
            else:
                attributes[i]['attType'] = 'FIX ME'
                attributes[i]['attTypeCode'] = 'FIX ME'
                attributes[i]['CType'] = 'FIX ME'
                attributes[i]['isNumber'] = False
        return attributes

    ########################################################################

    #   FUNCTIONS FOR WRITING STANDARD OPENING CLOSING ELEMENTS

    # functions cpp ns
    def write_cppns_begin(self):
        self.skip_line(2)
        self.write_line('{0}_CPP_NAMESPACE_BEGIN'
                        .format(self.library_name.upper()))
        self.skip_line(2)

    def write_cppns_end(self):
        self.skip_line(2)
        self.write_line('{0}_CPP_NAMESPACE_END'
                        .format(self.library_name.upper()))
        self.skip_line(2)

    # functions c declaration
    def write_cdecl_begin(self):
        self.skip_line(2)
        self.write_line('BEGIN_C_DECLS')
        self.skip_line(2)

    def write_cdecl_end(self):
        self.skip_line(2)
        self.write_line('END_C_DECLS')
        self.skip_line(2)

    # functions swig directive
    def write_swig_begin(self):
        self.skip_line(2)
        self.write_line('#ifndef SWIG')
        self.skip_line(2)

    def write_swig_end(self):
        self.skip_line(2)
        self.write_line('#endif  /*  !SWIG  */')
        self.skip_line(2)

    # functions cplusplus directive
    def write_cpp_begin(self):
        self.skip_line(2)
        self.write_line('#ifdef __cplusplus')
        self.skip_line(2)

    def write_cpp_end(self):
        self.skip_line(2)
        self.write_line('#endif  /*  __cplusplus  */')
        self.skip_line(2)

########################################################################

# FUNCTIONS FOR WRITING STANDARD FUNCTION DECLARATIONS

    def write_function_header(self, is_cpp,
                              function_name, arguments, return_type,
                              is_const=False, is_virtual=False):
        num_arguments = len(arguments)
        if not is_cpp:
            self.write_extern_decl()
            self.write_line(return_type)
            line = function_name + '('
        else:
            if return_type != '':
                if is_virtual:
                    line = 'virtual ' + return_type + ' ' + function_name + '('
                else:
                    line = return_type + ' ' + function_name + '('
            else:
                line = function_name + '('

        if num_arguments == 0:
            if is_cpp and is_const:
                line += ') const;'
            else:
                line += ');'
            self.write_line(line)
        elif num_arguments == 1:
            if is_cpp and is_const:
                line = line + arguments[0] + ') const;'
            else:
                line = line + arguments[0] + ');'
            self.write_line(line)
        else:
            saved_line = line
            line = line + arguments[0] + ', '
            # create the full line
            for n in range(1, num_arguments-1):
                line = line + arguments[n] + ', '
            if is_cpp and is_const:
                line = line + arguments[num_arguments-1] + '); const'
            else:
                line = line + arguments[num_arguments-1] + ');'
            # look at length and adjust
            if len(line) >= self.line_length:
                # do something else
                line = saved_line
                att_start = len(line)
                line += arguments[0]
                line += ','
                self.write_line(line)
                for i in range(1, num_arguments - 1):
                    line = arguments[i] + ','
                    self.write_line(line, att_start)
                if is_cpp and is_const:
                    line = arguments[num_arguments - 1] + ') const;'
                else:
                    line = arguments[num_arguments - 1] + ');'
                self.write_line(line, att_start)
            else:
                self.write_line(line)

########################################################################

# FUNCTIONS FOR WRITING STANDARD DOC COMMENTS

    def write_comment_header(self, title_line, params, return_line,
                             object_name, additional=[]):
        self.open_comment()
        self.write_comment_line(title_line)
        for i in range(0, len(params)):
            self.write_blank_comment_line()
            self.write_comment_line(params[i])
        if len(params) > 0 or len(return_line) > 0:
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
            self.write_comment_line('@memberof {}'.format(object_name))
        self.close_comment()



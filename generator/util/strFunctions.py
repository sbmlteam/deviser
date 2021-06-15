#!/usr/bin/env python
#
# @file    strFunctions.py
# @brief   functions that adjust strings in some way
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
# copy of this software and associated documentation files (the "Software'),
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

"""Functions that adjust strings in some way"""

import re
from util import global_variables as gv


def upper_first(word):
    """
    Change first character of a word to upper-case.
    Deal with words starting "csg" or "csG" differently.

    :param word: word we want to change.
    :return: changed word.

    Note the SBML Level 3 Spatial Geometry package uses a set of classes
    named CSGFoo; where the capitalised version of the name will always
    have the 'CSG' in capitals. This case is considered within this function.

    .. code-block:: default

        upper_first('csgsomething') -> "CSGsomething"
        upper_first('cat') -> "Cat"
        upper_first('csgcat') -> "CSGcat"
        upper_first('cscat') -> "Cscat"
        upper_first('csgeometry') -> "CSGeometry"
        upper_first('csGeometry') -> "CSGeometry"
        upper_first('a') -> "A"
    """
    if len(word) == 0:
        return word
    # hack for spatial CSGFoo classes
    if word.startswith('csg') or word.startswith('csG'):
        if word == 'csgeometry' or word == 'csGeometry':
            returned_word = 'CSGeometry'
        else:
            returned_word = 'CSG' + word[3:len(word)]
    else:
        returned_word = word[0].upper() + word[1:len(word)]
    return returned_word


def lower_first(word):
    """
    Change first character of a word to lower-case.
    Deal with words starting "CSG" differently.

    :param word: word we want to change.
    :return: changed word.

    Note the SBML Level 3 Spatial Geometry package uses a set of classes
    named CSGFoo; where the capitalised version of the name will always
    have the 'CSG' in capitals. This case is considered within this function.
    """
    # hack for spatial CSGFoo classes
    returned_word = ''
    if word is None or word == '':
        return returned_word
    elif word.startswith('CSG'):
        if word == 'CSGeometry':
            returned_word = 'csGeometry'
        else:
            returned_word = 'csg' + word[3:len(word)]
    else:
        returned_word = word[0].lower() + word[1:len(word)]
    return returned_word


def abbrev_name(name):
    """
    Abbreviate a name. Return in lower case.

    :param name: the name to abbreviate
    :return: returns abbreviated form

    This takes any capitals in the name and returns these as a lowercase
    abbreviation of the name. This facilitates the use of names in functions
    such as getFoo(Model *m), where m is the abbreviation of Model.
    Note if the name argument contains no capitals then the first letter
    is returned as the abbreviation.

    .. code-block:: default

        abbrev_name('thisIsATest') -> "iat"
        abbrev_name('CAT') -> "cat"
        abbrev_name('cat') -> "c"

    """
    abbrev = ''
    for i in range(0, len(name)):
        if name[i].isupper():
            abbrev = abbrev + name[i]
    if abbrev == '' and len(name) > 0:  # name is all lower-case
        abbrev = name[0]  # just return the first letter in name
    return abbrev.lower()


def abbrev_lo_name(loname):
    """
    The function abbreviates the 'ListOf' part of a class name to 'LO'. If
    the argument does not start ListOf, it returns an empty string.

    :param loname: string to transform
    :return: transformed string

    .. code-block:: default

        abbrev_lo_name('ListOfFoo') -> "LOFoo"
        abbrev_lo_name('spaghetti') -> ""

    """
    if loname.startswith('ListOf'):
        return 'LO' + loname[6:]
    else:
        return ''


def list_of_name(name, add_prefix=True):
    """
    Given a name, get "list of" name.

    :param name: the name to get "list of" name for
    :param add_prefix: if True and we are not writing code for a package
        prepend the global prefix to returned string
    :return: the "list of" name string e.g. ListOfName

    .. code-block:: default

         list_of_name('FooParameter", False) -> "ListOfFooParameters"

         gv.prefix = 'SBML'
         gv.is_package = True
         list_of_name('FooParameter') -> "ListOfFooParameters"

         gv.prefix = 'SBML'
         gv.is_package = False
         list_of_name('FooParameter') -> "SBMLListOfFooParameters"

    """
    prefix = ''
    if add_prefix and not gv.is_package:
        prefix = gv.prefix  # e.g. "SBML"
    return prefix + 'ListOf' + plural_no_prefix(name)


def lower_list_of_name_no_prefix(name):
    """
    For a string, return "list of name", possibly without the prefix.

    :param name: string we want the "list of" name for
    :return: the "list of" name, possibly without prefix.

    .. code-block:: default

         lower_list_of_name_no_prefix('fox') -> "listOfFoxes"

    """
    return 'listOf' + plural_no_prefix(upper_first(name))


def cap_list_of_name(name, add_prefix=True):
    """
    Get the "list of" name for a string, with first letter in upper-case.

    :param name: the string we want the "list of" name for.
    :param add_prefix: if True, prepend returned name with global prefix
                      (e.g. "SBML') if not a package.
    """
    name = upper_first(name)
    return list_of_name(name, add_prefix)


def cap_list_of_name_no_prefix(name):
    """
    Get the "list of" name for a string, without the prefix if it is not
    a package, with the first letter in upper-case.

    :param name: the string which we want the "list of" name for.
    :return: the "list of" name.

    .. code-block:: default

         cap_list_of_name_no_prefix('fox') -> "ListOfFoxes"

         gv.is_package = False
         cap_list_of_name_no_prefix('SBMLFoo') ->"ListOfFoos"
    """
    name = upper_first(name)
    return list_of_name(name, False)


def plural_no_prefix(name):
    """
    Return the plural of a string, removing prefix if it's not a package.

    :param name: the string (in singular form)
    :return: the plural form, without prefix if not a package.
    """
    if gv.is_package:
        return plural(name)
    else:
        new_name = remove_prefix(name)
        return plural(new_name)


def plural(name):
    """
    Attempt to find the plural of a word

    :param name: the word, probably in singular form.
    :return: the plural of the word, or the word itself if no plural found.

    .. code-block:: default

        plural('cat') -> "cats"
        plural('dogs') -> "dogs"
        plural('child') -> "children"
        plural('disinformation') -> "disinformation"
        plural('fox') -> "foxes"
        plural('party') -> "parties"
        plural('cloud') -> "clouds"
        plural('something') -> "somethings"

    """
    if name.endswith('s'):
        returned_word = name
    elif name.endswith('nformation'):
        returned_word = name
    elif name.endswith('hild'):
        returned_word = name + 'ren'
    elif name.endswith('x'):
        returned_word = name[0:len(name)] + 'es'
    elif name.endswith('y'):
        returned_word = name[0:len(name)-1] + 'ies'
    else:
        returned_word = name + 's'
    return returned_word


def singular(name):
    """
    Attempt to find the singular of a word

    :param name: the word, probably in plural form.
    :return: the singular of the word, or the word itself
             if no singular found.

    .. code-block:: default

         singular('cats') -> "cat"
         singular('dogs') -> "dogs"
         singular('children') -> "child"
         singular('disinformation') -> "disinformation"
         singular('coxes') -> "cox"
         singular('parties') -> "party"
         singular('clouds') -> "cloud"
         singular('somethings') -> "something"

    """
    returned_word = name
    length = len(name)
    if name.endswith('ies'):
        returned_word = name[0:length-3] + 'y'
    elif name.endswith('xes'):
        returned_word = name[0:length-2]
    elif name.endswith('s'):
        returned_word = name[0:length-1]
    elif name.endswith('hildren'):
        returned_word = name[0:length-3]
    return returned_word


def remove_prefix(name, remove_package=True,
                  prefix='', remove_doc_prefix=False):
    """
    Remove prefix from a string; if we are writing an SBML package where the
    package prefix has been declared this will be removed.

    :param name: the string which we wish to remove the prefix from.
    :param remove_package: if True, and global prefix is "SBML",
        remove the package prefix either gv.package_prefix
        or 'prefix' argument given.
        Defaults to True.
    :param prefix: the prefix to remove if global prefix is "SBML",
        gv. package_prefix is empty, and remove_package is True.
        Defaults to ''.
    :param remove_doc_prefix: if True,
        and name ends in 'Document', remove prefix.
        Defaults to False.
    :return: the input string, possibly with something
        removed at the beginning.

    .. code-block:: default

        Writing SBML package with gv.package_prefix 'Fbc'

        remove_prefix('FbcType') returns 'Type'
        remove_prefix('FbcDocument', remove_doc_prefix=True) returns 'Document'
        remove_prefix('FbcDocument', remove_doc_prefix=False)
                      returns 'FbcDocument'

        Writing SBML package with gv. package_prefix ''

        remove_prefix('FbcType') returns 'FbcType'
        remove_prefix('FbcType', prefix='Fbc') returns 'Type'


    """
    prefix_to_remove = ''
    if gv.prefix == 'SBML' and remove_package:
        # we might want to remove the name of the package
        if gv.is_package and gv.package_prefix != '':
            prefix_to_remove = gv.package_prefix
        elif prefix != '':
            prefix_to_remove = prefix
    else:
        prefix_to_remove = gv.prefix
    length = len(prefix_to_remove)

    if length == 0 or not is_prefixed_name(name, prefix_to_remove):
        return name
    if not is_prefixed_document_class(name, prefix_to_remove):
        return name[length:]
    elif remove_doc_prefix:
        return name[length:]
    else:
        return name


def is_prefixed_name(name, prefix):
    """
    Returns true if name begins with given prefix.

    :param name: name to query.
    :param prefix: prefix to look for.
    :return: True if name begins with prefix with first letter of name
        being capital and prefix case insensitive, False otherwise.

    .. code-block:: default

        The following return True:
            is_prefixed_name('fooSalt',, 'foo')
            is_prefixed_name('FOOSalt',, 'foo')
            is_prefixed_name('foOSalt',, 'FOo')

        The following return False:
            is_prefixed_name('fooSalt',, 'foot')
            is_prefixed_name('FOOsalt',, 'foo')

    """

    uppername = name.upper()
    upperprefix = prefix.upper()

    if uppername.startswith(upperprefix):
        first = name[len(prefix)]
        if first == first.upper():
            return True
    return False


def is_prefixed_document_class(name, prefix):
    """
    :param name: name to query.
    :param prefix: prefix to look for.
    :return: True if name begins with prefix and endswith 'Document'
        and prefix is case insensitive, False otherwise.
    """
    if name.endswith('Document'):
        return is_prefixed_name(name, prefix)
    return False


def get_indefinite(name):
    """
    Get the indefinite article for the name supplied.

    :param name: the name we want the indefinite article (and or a) for.
    :return: 'an' if name starts with a vowel, else 'a'

    Note this function is not complete and makes no attempt to
    account for anomalies in the English language
    """
    for char in ('a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'):
        if name.startswith(char):
            return 'an'
    return 'a'


def standard_element_name(name):
    """
    Standardise an element name.

    :param name: the name to standardise
    :return: standardised name.

    Remove spaces, and any trailing '*', ',' or '_t'.
    If it's a list of something, convert to singular.
    Capitalise standard name.

    .. code-block:: default

        standard_element_name('listOfFoxes') -> "Fox"
        standard_element_name('apple') -> "Apple"
        standard_element_name('foo_t') -> "Foo"

    """
    name = remove_spaces(name)
    length = len(name)
    temp = name

    # Don't want * , _t at end
    if name.endswith('*'):
        temp = name[0:length-1]
    elif name.endswith(','):
        temp = name[0:length-1]
    elif name.endswith('_t'):
        temp = name[0:length-2]
    returned_word = temp

    # Also don't want ListOf
    if returned_word.startswith('ListOf') or \
            returned_word.startswith('listOf'):
        temp = singular(returned_word[6:length])
    return upper_first(temp)


def get_library_suffix(name):
    """
    Get library suffix of a word.

    :param name: the word
    :return: library suffix, with all but first character in lower-case.

    .. code-block:: default

         get_library_suffix('library') -> "Rary"
         get_library_suffix('libSBML') -> "Sbml"
         get_library_suffix('cat') -> "Cat"
         get_library_suffix('lib') -> ""

    """
    ret_name = name.lower()
    if ret_name.startswith('lib'):
        ret_name = ret_name[3:]
    return upper_first(ret_name)

############################################
# The following functions are specifically for use when writing latex
# TODO come back to writing tex files when fixing #53


def wrap_token(name, pkg=''):
    """
    Returns the name wrapped as a token specifically for writing latex

    :param name: the name to wrap
    :param pkg: include this, if present
    :return: the "wrapped" name

    This function is for use when writing latex so that an attribute name
    can be wrapped with the \\token command
    e.g. \\token{'id'} or \\token{'comp:\\-id'}

    """
    if pkg == '':
        return '\\token{' + name + '}'
    else:
        return '\\token{' + pkg + ':\\-' + name + '}'


def wrap_type(given_type, element, hack=False):
    """
    Wraps the given type in a string that will be used in a latex
    description of that type.

    :param given_type: the type we want to wrap, e.g. 'array', 'enum',...
    :param element:
    :param hack: special case which can be used for 'element' type
    :return: string describing the type and the element
    """
    if given_type == 'array':
        return 'consisting of an array of \\primtype{' + element + '}'
    elif given_type == 'enum':
        element_name = texify(element)
        return 'of type \\primtype{' + element_name + '}'
    elif given_type == 'element':
        if hack:
            return 'of type \\' + element
        else:
            return wrap_token(element)
    elif given_type == 'lo_element':
        return wrap_token(element)
    elif given_type == 'inline_lo_element':
        return 'TO DO: add type'
    else:
        return 'of type \\primtype{' + given_type + '}'


def wrap_section(name, add_class=True, add_extended=False):
    """
    'Wrap' a section

    TODO - a section of what???

    :param name:
    :param add_class:
    :param add_extended:
    :return:

    e.g. "Cat" -> "\\sec{cat-class}"
    """
    if add_class:
        return '\\sec{' + make_class(name, add_extended) + '}'
    else:
        return '\\sec{' + name + '}'


def make_class(name, add_extended=False):
    """
    Add '-class' to end of a lower-case string

    :param name: the string to take in, and convert to lower-case
    :param add_extended: if True, prepend result with 'extended-'
    :return: the string made as a class

    .. code-block:: default

        make_class('Irenaeus') -> "irenaeus-class"
        make_class('Irenaeus", True) -> "extended-irenaeus-class"

    """
    if add_extended:
        return 'extended-' + name.lower() + '-class'
    else:
        return name.lower() + '-class'


def wrap_enum(name):
    """
    'Wrap' an enum

    :param name: the enum to wrap
    :return: the wrapped form of the enum

    e.g. 'cat' -> '\\primtype{cat}'

    TODO when, how and why would this be used? It's used in the
    validation rules code, but at the moment I don't understand that.
    """
#    return '\\primtype{' + lower_first(name) + '}'
    return '\\primtype{' + name + '}'

# End of latex specific functions
##################################################


def get_sid_refs(refs):
    """
    This function is specifically designed for when an attribute can point to
    one or more element types and formatting lines in text referring to the
    element(s).

    :param refs: a string which is a comma-separated sequence of element names
    :return: a tuple where the first is a string representing a textual list
        of the elements and the second is a string
        representing a combined type.

    .. code-block:: default

        get_sid_refs('cat,dog') = ["Cat or \\Dog", "CatOrDog"]

    """
    if refs == '':
        return['', 'SId']
    elif ',' not in refs:
        return [upper_first(refs), upper_first(refs)]
    else:
        ret_string = ''
        ret_type = ''
        str_refs = refs.split(',')
        length = len(str_refs)
        if length > 0:
            ret_string = upper_first(str_refs[0])
            ret_type = upper_first(str_refs[0])
            for i in range(1, length):
                ret_string += ' or \\{0}'.format(upper_first(str_refs[i]))
                ret_type += 'Or{0}'.format(upper_first(str_refs[i]))
        return [ret_string, ret_type]


# TODO come back to writing tex files when fixing #53
def get_element_name(attribute, add_prefix_if_not_pkg=True,
                     leave_pkg_prefix=True):
    """
    Get the name of an element node for use in text (specifications or
    validation rules).

    :param attribute: dictionary of information about the element.
    :param add_prefix_if_not_pkg: boolean indicating whether the
        global prefix should be prepended to the name if this is not a package
    :param leave_pkg_prefix:
        boolean indication whether to leave a prefix in place
    :return: the name, if available, else 'FIX_ME'.
    """
    if 'type' in attribute:
        name = ''
        if 'texname' in attribute:
            name = attribute['texname']
        if len(name) == 0:  # No texname
            if leave_pkg_prefix:
                name = remove_prefix(attribute['name'])
            else:
                name = attribute['name']
        if attribute['type'] in ['lo_element', 'inline_lo_element']:
            if leave_pkg_prefix:
                return '\\{0}'.\
                    format(cap_list_of_name(name, add_prefix_if_not_pkg))
            else:
                if 'listOfClassName' in attribute and \
                        attribute['listOfClassName'] != '':
                    return '\\{0}'.format(
                        remove_prefix(attribute['listOfClassName']))
                else:
                    return '\\{0}'.format(cap_list_of_name_no_prefix(name))
        elif attribute['type'] == 'element':
            if attribute['element'] == 'ASTNode*':
                return 'MathML math'
            else:
                return attribute['element']
        else:
            return 'FIX_ME'
    elif 'isListOf' in attribute:
        if attribute['isListOf']:
            return '\\{0}'.format(cap_list_of_name(
                remove_prefix(attribute['name'])))
        else:
            return '\\{0}'.format(upper_first(
                remove_prefix(attribute['name'])))
    else:
        return 'FIX_ME'


def replace_digits(name):
    """
    Replace the numerical digits in a string with their English words.

    :param name: the input string, possibly containing digits
    :return: the same string, but with digits replaced by words

    .. code-block:: default

         replace_digits('John 3:16') -> "John Three:OneSix"

    """
    mydict = {'0': 'Zero', '1': 'One', '2': 'Two', '3': 'Three', '4': 'Four',
              '5': 'Five', '6': 'Six', '7': 'Seven', '8': 'Eight', '9': 'Nine'}

    for item in mydict:
        name = re.sub(item, mydict[item], name)

    return name


def replace_underscore(name):
    """
    Replace underscore characters in a string with escaped underscores.

    :param name: string to process
    :return: string with every '_' changed to '\\_'.
    """
    name = re.sub('_', '\\_', name)
    return name


def remove_spaces(name):
    """
    Remove all space characters in a string.

    :param name: input string, possibly containing spaces
    :return: the input string, but with space characters removed.

    .. code-block:: default

         remove_spaces('   hello   world  ') -> "helloworld"

    """
    newname = name.replace(' ', '')
    return newname


def remove_hyphens(name):
    """
    Remove hyphens and capitalise each word (after first hyphen) in a string.

    :param name: input string
    :return: [newstring, boolean indicating if hyphen was removed]

    .. code-block:: default

        remove_hyphens('this-is-a-test') -> ["thisIsATest", True]
        remove_hyphens('cat-') -> ["cat", True]
        remove_hyphens('-cat') -> ["Cat", True]
        remove_hyphens('NoHyphens') -> ["NoHyphens", False]

    """
    removed_hyphen = False
    if '-' not in name:
        return [name, removed_hyphen]
    else:
        newname = ''
        hyphen = False
        for c in name:
            if c != '-':
                if not hyphen:
                    newname += c
                else:
                    newname += c.upper()
                    hyphen = False
            else:
                hyphen = True
                removed_hyphen = True
        return [newname, removed_hyphen]


def texify(name):
    """
    Replace digits with number words, escape underscores, and remove spaces.

    :param name: input string
    :return: transformed string

    .. code-block:: default

         texify('  phase_1: part_2  ') -> "phase\\_One:part\\_Two')
         texify('012_27 44_8 ') -> "ZeroOneTwo\\_TwoSevenFourFour\\_Eight"

    """
    name = replace_digits(name)
    name = replace_underscore(name)
    name = remove_spaces(name)
    return name


def compare_no_case(test, reference):
    """
    Are these two strings the same, when both are in lower case?

    :param test: first string to compare
    :param reference: second word to compare
    :return: True if both strings identical when converted to lower case.

    .. code-block:: default

        compare_no_case('this is a test", "This iS a TEST') -> True

    """
    return test.lower() == reference.lower()


def get_class_from_plugin(plugin, package):
    """
    Get the name of a class from a plugin. A plugin class will
    have a name such as PkgFooPlugin. This function will
    return 'Foo'.

    :param plugin: the full name of the plugin class
    :param package: the name of the package
    :return: the name of the class

    .. code-block:: default

        get_class_from_plugin('CompModelPlugin", "comp') -> "Model"

    """
    len_pkg = len(package)
    len_plugin = len(plugin)
    # we are expecting PkgFooPlugin
    if len_plugin < len_pkg or len_pkg > len_plugin - 6 \
            or not plugin.endswith('Plugin'):
        return ''
    return plugin[len_pkg:len_plugin-6]


def prefix_name(name):
    """
    Prepend the global variables' prefix to a word, if not already present.
    Except for XMLNode and ASTNode.

    :param name: the word
    :return: the prefixed word
    """
    if name.startswith(gv.prefix):
        return name
    elif name == 'XMLNode' or name == 'ASTNode':
        return name
    elif name == 'SBase':
        return gv.prefix + "Base"
    else:
        return gv.prefix + name


def prefix_classes(working_class):
    """
    TODO: sort this function
    Prefix the names of items in a dictionary of information about
    an element node.

    :param working_class: the dictionary
    :return: nothing

    Prefix names - if we are working with another library we want class
    prefixed but element names to stay untouched
    """
    existing_name = working_class['name']
    working_class['name'] = prefix_name(existing_name)
    if working_class['baseClass'] != gv.baseClass:
        working_class['baseClass'] = prefix_name(working_class['baseClass'])
    if 'elementName' not in working_class or \
            len(working_class['elementName']) == 0:
        working_class['elementName'] = lower_first(existing_name)

    if 'lo_class_name' in working_class and \
            len(working_class['lo_class_name']) > 0:
        name = working_class['lo_class_name']
        working_class['lo_class_name'] = prefix_name(name)

    # TODO will 'attribs' always be a key which is present?
    # I added this check so a simple test would work, but I don't
    # know if this will actually ever occur in real life.
    if 'attribs' not in working_class:  # Is this ever true?
        return

    for attrib in working_class['attribs']:
        if attrib['type'] == 'lo_element' or attrib['type'] == 'element' or\
                attrib['type'] == 'inline_lo_element':
            attrib['element'] = prefix_name(attrib['element'])
        if 'concrete' in attrib:
            for conc in attrib['concrete']:
                conc['element'] = prefix_name(conc['element'])
        # if 'concrete' in attrib and len(attrib['concrete']) > 0:
        #     for conc in attrib['concrete']:
        #         conc['element'] = prefix_name(conc['element'])


def is_camel_case(name):
    """
    Is this word in camel case?

    :param name: the word we are interested in
    :return: True if word is in camel case, False if not

    .. code-block:: default

        is_camel_case('FooParameter') -> True
        is_camel_case('fooParameter') -> True
        is_camel_case('fooparameter') -> False
        is_camel_case('Fooparameter') -> False
    """
    camel_case = False
    adjust_name = lower_first(remove_prefix(name))
    lower_name = adjust_name.lower()
    if lower_name != adjust_name:
        camel_case = True
    return camel_case

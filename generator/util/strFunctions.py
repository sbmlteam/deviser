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

"""Functions that adjust strings in some way"""

import re
from util import global_variables as gv


def upper_first(word):
    """
    Change first character of a word to upper-case.
    Deal with words starting "csg" or "csG" differently.

    :param word: word we want to change.
    :return: changed word.

    e.g.
    "csgsomething" -> "CSGsomething", "cat" -> "Cat", "csgcat" -> "CSGcat",
    "cscat" -> "Cscat", "csgeometry" -> "CSGeometry",
    "csGeometry" -> "CSGeometry", "a" -> "A"
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

    TODO: could perhaps have one function to replace this
    and the upper_first() function? As they are quite similar.

    """
    # hack for spatial CSGFoo classes
    returned_word = ''
    if word is None or word == '':
        return returned_word
    elif len(word) == 1:  # The reverse of this is not done in upper_first()
        returned_word = word[0].lower()
    elif word.startswith('CSG'):
        if word == 'CSGeometry':
            returned_word = 'csGeometry'
        else:
            returned_word = 'csg' + word[3:len(word)]
    else:
        returned_word = word[0].lower() + word[1:len(word)]
    return returned_word


def get_indent(element):
    """
    Given a string, e.g. 'hello', work out length
    of string 'hello('.

    :param element: string to process
    :return: length of: string plus '('

    TODO when would this be used?
    """
    s1 = '{0}('.format(element)
    return len(s1)


def abbrev_name(element):
    """
    Abbreviate a name. Return in lower case.

    :param element: the name to abbreviate
    :return: returns abbreviated form

    e.g.
    "thisIsATest" -> "iat"  # TODO I'm surprised we don't want "IAT", etc.
    "CAT" -> "cat"
    "cat" -> "c"  # TODO is that what we want?
    """
    abbrev = ''
    for i in range(0, len(element)):
        if element[i].isupper():
            abbrev = abbrev + element[i]
    if abbrev == '' and len(element) > 0:
        abbrev = element[0]
    return abbrev.lower()


def abbrev_lo_name(loname):
    """
    TODO I can see what it does, but I don't know why, or what sort
    of lonames will be transformed.

    :param loname: string to transform
    :return: transformed string

    e.g.  "spaghetti" -> "LOtti"
    """
    return 'LO' + loname[6:]


def list_of_name(name, addPrefix=True):
    """
    Given a name, get "list of" name.

    :param name: the name to get "list of" name for
    :param addPrefix: if True, prepend the global prefix to returned string
    :return: the "list of" name string
    """
    # e.g. name might be "FooParameter", and
    # so we want "ListOfFooParameters"
    prefix = ''
    if addPrefix and not gv.is_package:
        prefix = gv.prefix  # e.g. "SBML"
    return prefix + 'ListOf' + plural_no_prefix(name)


def lower_list_of_name_no_prefix(name):
    """
    For a string, return "list of name", possibly without the prefix.

    :param name: string we want the "list of" name for
    :return: the "list of" name, possibly without prefix.

    e.g. "fox" -> "listOfFoxes"
    """
    return 'listOf' + plural_no_prefix(upper_first(name))


def cap_list_of_name(name, addPrefix=True):
    """
    Get the "list of" name for a string, with first letter in upper-case.

    :param name: the string we want the "list of" name for.
    :param addPrefix: if True, prepend returned name with global prefix
                      (e.g. "SBML") if not a package.
    """
    name = upper_first(name)
    return list_of_name(name, addPrefix)


def cap_list_of_name_no_prefix(name):
    """
    Get the "list of" name for a string, without the prefix,
    with the first letter in upper-case.

    :param name: the string which we want the "list of" name for.
    :return: the "list of" name.

    e.g. "fox" -> "ListOfFoxes"
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

    e.g.
    "cat" -> "cats", "dogs" -> "dogs", "child" -> "children",
    "disinformation" -> "disinformation", "fox" -> "foxes",
    "party" -> "parties", "cloud" -> "clouds", "something" -> "somethings".
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

# Good tests would be (e.g.) word == singular(plural(word)), etc.

def singular(name):
    """
    Attempt to find the singular of a word

    :param name: the word, probably in plural form.
    :return: the singular of the word, or the word itself
             if no singular found.

    e.g.
    "cats" -> "cat", "dogs" -> "dogs", "children" -> "child",
    "disinformation" -> "disinformation", "coxes" -> "cox",
    "parties" -> "party", "clouds" -> "cloud", "somethings" -> "something".

    NB issue #34
    "foxes" -> "fox" is ok
    but
    "apples" -> "appl", "skates" -> "skat" is wrong

    """
    returned_word = name
    length = len(name)
    if name.endswith('ies'):
        returned_word = name[0:length-3] + 'y'
    elif name.endswith('es'):
        returned_word = name[0:length-2]
    elif name.endswith('s'):
        returned_word = name[0:length-1]
    elif name.endswith('hildren'):
        returned_word = name[0:length-3]
    return returned_word


def remove_prefix(name, in_concrete=False, remove_package=False,
                  prefix='', remove_doc_prefix=False):
    """
    Remove prefix from a string.

    :param name: the string which we wish to remove the prefix from.
    :param in_concrete:
    :param remove_package: if True, and global prefix is "SBML", remove the prefix (4th function arg)
    :param prefix: the prefix to remove if global prefix is "SBML" and remove_package is True.
    :param remove_doc_prefix: if True, and name ends in 'Document', remove prefix.
    :return: the input string, possibly with something removed at the beginning.

    TODO an example or two would be helpful here. And I'm not sure about in_concrete argument.

    """
    prefix_to_remove = ''
    if gv.prefix == 'SBML':
        # we might want to remove the name of the package
        if not in_concrete and gv.is_package and gv.package_prefix != '':
           prefix_to_remove = gv.package_prefix
        elif remove_package and prefix != '':
            prefix_to_remove = prefix
    else:
        prefix_to_remove = gv.prefix
    length = len(prefix_to_remove)
    if length == 0:
        return name
    if not name.endswith('Document') and \
            (name.startswith(prefix_to_remove)
             or name.startswith(upper_first(prefix_to_remove))):
        newname = name[length:]  # Remove the prefix
    else:
        if remove_doc_prefix and name.endswith('Document'):
            newname = name[length:]  # Remove the prefix
        else:
            newname = name
    return newname


def get_indefinite(name):
    """
    Get the indefinite article for the name supplied.

    :param name: the name we want the indefinite article (and or a) for.
    :return: 'an' if name starts with a vowel, else 'a'

    TODO: what about words starting with h?
    e.g. "an hotel" and "a host of reasons" are both correct :-)
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

    e.g. "ListOfApples*" should return "Apple", but TODO bug in singular()
    needs fixing. (Currently -> "Appl").  See issue #34

    "listOfFoxes," -> "Fox"
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
    if returned_word.startswith('ListOf') or returned_word.startswith('listOf'):
        temp = singular(returned_word[6:length])
    return upper_first(temp)


def get_library_suffix(name):
    """
    Get library suffix of a word.

    :param name: the word
    :return: library suffix, with all but first character in lower-case.

    e.g.
    "library" -> "Rary", "libSBML" -> "Sbml", "cat" -> "Cat", "lib" -> ""
    """
    ret_name = name.lower()
    if ret_name.startswith('lib'):
        ret_name = ret_name[3:]
    return upper_first(ret_name)


def wrap_token(name, pkg=''):
    """ returns the name wrapped as a token
       e.g. \token{'id'} or \token{'comp:\-id'} """
    if pkg == '':
        return '\\token{' + name + '}'
    else:
        return '\\token{' + pkg + ':\\-' + name + '}'


def wrap_type(name, element, hack=False):
    if name == 'array':
        return 'consisting of an array of \\primtype{' + element + '}'
    elif name == 'enum':
        element_name = texify(element)
        return 'of type \\primtype{' + element_name + '}'
    elif name == 'element':
        if hack:
            return 'of type \\' + element
        else:
            return wrap_token(element)
    elif name == 'lo_element':
        return wrap_token(element)
    elif name == 'inline_lo_element':
        return 'TO DO: add type'
    else:
        return 'of type \\primtype{' + name + '}'


def wrap_section(name, add_class=True, add_extended=False):
    if add_class:
        return '\\sec{' + make_class(name, add_extended) + '}'
    else:
        return '\\sec{' + name + '}'


def make_class(name, add_extended=False):
    if add_extended:
        return 'extended-' + name.lower() + '-class'
    else:
        return name.lower() + '-class'


def wrap_enum(name):
#    return '\\primtype{' + lower_first(name) + '}'
    return '\\primtype{' + name + '}'


def get_sid_refs(refs):
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
                ret_string += ' or \{0}'.format(upper_first(str_refs[i]))
                ret_type += 'Or{0}'.format(upper_first(str_refs[i]))
        return [ret_string, ret_type]


def get_element_name(attribute, addPrefix=True):
    if 'type' in attribute:
        name = ''
        if 'texname' in attribute:
            name = attribute['texname']
        if len(name) == 0:
            name = remove_prefix(attribute['name'])
        if attribute['type'] == 'lo_element':
            return '\{0}'.format(cap_list_of_name(name, addPrefix))
        elif attribute['type'] == 'inline_lo_element':
            return '\{0}'.format(cap_list_of_name(name, addPrefix))
        elif attribute['type'] == 'element':
            if attribute['element'] == 'ASTNode*':
                return 'MathML math'
            else:
                return attribute['element']
        else:
            return 'FIX_ME'
    elif 'isListOf' in attribute:
        if attribute['isListOf']:
            return '\{0}'.format(cap_list_of_name(remove_prefix(attribute['name'])))
        else:
            return '\{0}'.format(upper_first(remove_prefix(attribute['name'])))
    else:
        return 'FIX ME'


def get_element_name_no_prefix(attribute):
    if 'type' in attribute:
        name = ''
        if 'texname' in attribute:
            name = attribute['texname']
        if len(name) == 0:
            name = attribute['name']
        if attribute['type'] == 'lo_element':
            if 'listOfClassName' in attribute and attribute['listOfClassName'] != '':
                return '\{0}'.format(remove_prefix(attribute['listOfClassName']))
            else:
                return '\{0}'.format(cap_list_of_name_no_prefix(name))
        elif attribute['type'] == 'inline_lo_element':
            return '\{0}'.format(cap_list_of_name_no_prefix(name))
        elif attribute['type'] == 'element':
            if attribute['element'] == 'ASTNode*':
                return 'MathML math'
            else:
                return attribute['element']
        else:
            return 'FIX_ME'
    elif 'isListOf' in attribute:
        if attribute['isListOf']:
            return '\{0}'.format(cap_list_of_name(attribute['name']))
        else:
            return '\{0}'.format(upper_first(attribute['name']))
    else:
        return 'FIX ME'


def replace_digits(name):
    """
    Replace the numerical digits in a string with their English words.

    :param name: the input string, possibly containing digits
    :return: the same string, but with digits replaced by words

    e.g. replace_digits("John 3:16") -> "John Three:OneSix"
    """
    mydict = {'0':'Zero', '1':'One', '2':'Two', '3':'Three', '4':'Four',
              '5':'Five', '6':'Six', '7':'Seven', '8':'Eight', '9':'Nine'}

    for item in mydict:
        name = re.sub(item, mydict[item], name)

    return name


def replace_underscore(name):
    """
    Replace underscore characters in a string with escaped underscores.

    :param name: string to process
    :return: string with every '_' changed to '\_'.
    """
    name = re.sub('_', '\_', name)
    return name


def remove_spaces(name):
    """
    Remove all space characters in a string.

    :param name: input string, possibly containing spaces
    :return: the input string, but with space characters removed.

    e.g. remove_spaces("   hello   world  ") -> "helloworld"
    """
    newname = name.replace(' ', '')
    return newname


def remove_hyphens(name):
    """
    Remove hyphens and capitalise each word (after first) in a string.

    :param name: input string
    :return: [newstring, removed?]

    e.g. remove_hyphens("this-is-a-test") -> ["thisIsATest", True]
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

    :param name: input string, e.g. "012_27 44_8 "
    :return: transformed string, e.g. "ZeroOneTwo\_TwoSevenFourFour\_Eight"
    """
    name = replace_digits(name)
    name = replace_underscore(name)
    name = remove_spaces(name)
    return name


def compare_no_case(test, reference):
    """
    Are these two strings the same, when both are in lower case?

    :param test: first string to compare, e.g. "this is a test"
    :param reference: second word to compare, e.g. "This iS a TEST"
    :return: True if both strings identical when converted to lower case.
    """
    return test.lower() == reference.lower()


def get_class_from_plugin(plugin, package):
    num = len(package)
    length = len(plugin)
    name = plugin[num:length-6]
    return name


def prefix_name(name):
    if name.startswith(gv.prefix):
        return name
    elif name == 'XMLNode' or name == 'ASTNode':
        return name
    elif name == 'SBase':
        # return '{0}Base'.format(gv.prefix)
        return gv.prefix + "Base"
    else:
        # return '{0}{1}'.format(gv.prefix, name)
        return gv.prefix + name


# Prefix names - if we are working with another library we want class
# prefixed but element names to stay untouched
def prefix_classes(working_class):
    existing_name = working_class['name']
    working_class['name'] = prefix_name(existing_name)
    if working_class['baseClass'] != gv.baseClass:
        working_class['baseClass'] = prefix_name(working_class['baseClass'])
    if 'elementName' not in working_class or len(working_class['elementName']) == 0:
        working_class['elementName'] = lower_first(existing_name)
    for attrib in working_class['attribs']:
        if attrib['type'] == 'lo_element' or attrib['type'] == 'element' or \
                        attrib['type'] == 'inline_lo_element':
            attrib['element'] = prefix_name(attrib['element'])
        if 'concrete' in attrib:
            for conc in attrib['concrete']:
                conc['element'] = prefix_name(conc['element'])
        # if 'concrete' in attrib and len(attrib['concrete']) > 0:
        #     for conc in attrib['concrete']:
        #         conc['element'] = prefix_name(conc['element'])
    if 'lo_class_name' in working_class and len(working_class['lo_class_name']) > 0:
        name = working_class['lo_class_name']
        working_class['lo_class_name'] = prefix_name(name)


def is_camel_case(name):
    camel_case = False
    adjust_name = lower_first(remove_prefix(name))
    lower_name = adjust_name.lower()
    if lower_name != adjust_name:
        camel_case = True
    return camel_case

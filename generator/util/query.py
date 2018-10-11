#!/usr/bin/env python
#
# @file    query.py
# @brief   general functions for querying objects
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

from . import strFunctions


# return True is any of the attributes are of type SIdRef
def has_sid_ref(attributes):
    if any(attribute['type'] == 'SIdRef' for attribute in attributes):
        return True
    return False


# return a set of attributes that are of type SIdRef
def get_sid_refs(attributes, unit=False):
    sid_refs = []
    if not unit:
        match = 'SIdRef'
    else:
        match = 'UnitSIdRef'
    for i in range(0, len(attributes)):
        if strFunctions.compare_no_case(attributes[i]['type'], match):
            sid_refs.append(attributes[i])
    return sid_refs


# return a set of attributes that are SIdRefs for the given class
def get_sid_refs_for_class(working_class):
    sid_refs = []
    child_element = get_class(working_class['element'],
                              working_class['root'])
    if child_element is not None:
        sid_refs = get_sid_refs(child_element['attribs'])
    return sid_refs


# return True is any of the attributes refer to elements
def has_children(attributes):
    for attribute in attributes:
        att_type = attribute['type']
        if att_type == 'element' or att_type == 'lo_element' or att_type == 'inline_lo_element':
            return True
    return False


# return True is any of the attributes refer to elements but not math
def has_children_not_math(attributes):
    for i in range(0, len(attributes)):
        if attributes[i]['type'] == 'lo_element':
            return True
        elif attributes[i]['type'] == 'element' \
                and attributes[i]['name'] != 'math':
            return True
    return False


# return the class with the matching name from the root object
def get_class(name, root_object):
    if name.startswith('listOf') or name.startswith('ListOf'):
        name = strFunctions.singular(name[6:])
    else:
        name = strFunctions.upper_first(name)
    if root_object is None:
        return None
    elif root_object['baseElements'] is None:
        return None
    else:
        for i in range(0, len(root_object['baseElements'])):
            if name == root_object['baseElements'][i]['name']:
                return root_object['baseElements'][i]


def is_inline_child(class_object):
    inline_parents = []
    parents = get_inline_parents(class_object)
    for parent in parents:
        inline_child = False
        parent_class = get_class(parent, class_object['root'])
        if parent_class and 'attribs' in parent_class:
            for attrib in parent_class['attribs']:
                if attrib['element'] == class_object['lo_child']:
                    if attrib['type'] == 'inline_lo_element':
                        inline_child = True
        if inline_child:
            inline_parents.append(parent)
    return inline_parents

def get_inline_parents(class_object):
    parents = []
    if class_object['is_list_of']:
        name = class_object['lo_child']
    else:
        name = class_object['name']
    for element in class_object['root']['baseElements']:
        for attrib in element['attribs']:
            if attrib['element'] == name and element['name'] not in parents:
                parents.append(element['name'])
    return parents

# return the parent class of this class
# if it is not given we assume it is a child of a plugin
# and get the base of the plugin
def get_parent_class(class_object):
    parent = ''
    if class_object['is_list_of']:
        name = class_object['lo_child']
    else:
        name = class_object['name']
    found = False
    if 'parent' in class_object:
        parent = class_object['parent']
    else:
        plugins = class_object['root']['plugins']
        for plugin in plugins:
            base = plugin['sbase']
            for extension in plugin['lo_extension']:
                if extension['name'] == name:
                    parent = base
                    found = True
                    break
            if not found:
                for extension in plugin['extension']:
                    if extension['name'] == name:
                        parent = base
                        found = True
                        break
            if found:
                break
    if not found and len(parent) == 0:
        for element in class_object['root']['baseElements']:
            if element['name'] != name:
                for attrib in element['attribs']:
                    if attrib['element'] == name:
                        parent = element['name']
                        found = True
                        break
            if found:
                break
    return parent


# return a list of the actual concrete classes
def get_concretes(root_object, concrete_list):
    concretes = []
    for c in concrete_list:
        add_concrete_to_list(root_object, c, concretes)
    return concretes


# add the non-abstract class to the list
def add_concrete_to_list(root, concrete, mylist):
    current = get_class(concrete['element'], root)
    if current is not None:
        if current['abstract'] is False:
            concrete['typecode'] = current['typecode']
            if concrete not in mylist:
                mylist.append(concrete)
        else:
            for c in current['concrete']:
                if c != concrete:
                    add_concrete_to_list(root, c, mylist)
                else:
                    concrete['typecode'] = current['typecode']
                    if concrete not in mylist:
                        mylist.append(concrete)


# return a set of attributes with any elements/lo_elements removed
# populating the version information
def separate_attributes(full_attributes):
    attributes = []
    for i in range(0, len(full_attributes)):
        att_type = full_attributes[i]['attType']
        name = full_attributes[i]['name']
        if att_type != 'element' and att_type != 'lo_element':
            existing = get_matching_element('name', name, attributes)
            if existing:
                vers = full_attributes[i]['version']
                existing['version_info'][vers-1] = True
            else:
                attributes.append(full_attributes[i])
    return attributes


# return attributes for the given version only
def get_version_attributes(attributes, version):
    ver_attribs = []
    for i in range(0, len(attributes)):
        att_type = attributes[i]['attType']
        if att_type != 'element' and att_type != 'lo_element':
            if attributes[i]['version'] == version:
                ver_attribs.append(attributes[i])
    return ver_attribs


# return attributes for the given version only
def get_version_elements(elements, version):
    ver_attribs = []
    for i in range(0, len(elements)):
        if elements[i]['version'] == version:
            ver_attribs.append(elements[i])
    return ver_attribs


# return a set of unique attributes
#  any with multiple versions appear only once
def get_unique_attributes(full_attributes):
    attributes = []
    for i in range(0, len(full_attributes)):
        name = full_attributes[i]['name']
        existing = get_matching_element('name', name, attributes)
        if existing:
            continue
        else:
            attributes.append(full_attributes[i])
    return attributes


def get_matching_element(name, match_name, list_elements):
    element = None
    if not list_elements:
        return element
    for existing in list_elements:
        if existing[name] == match_name:
            element = existing
    return element


# return True is any of the attributes are of type array
def has_array(attributes):
    if any(attribute['type'] == 'array' for attribute in attributes):
        return True
    return False


# return True is any of the attributes are of type vector
def has_vector(attributes):
    if any(attribute['type'] == 'vector' for attribute in attributes):
        return True
    return False


# return True is any of the attributes have another package
# and a listt of packages
def has_other_packages(attributes):
    list_pkgs = []
    has_pack = False
    for attribute in attributes:
        if 'other_package' in attribute and attribute['other_package']:
            has_pack = True
            list_pkgs.append(attribute['other_package'])
    return [has_pack, list_pkgs]


# return True is the attribute is saved as a string
def is_string(attribute):
    if attribute['attType'] == 'string':
        return True
    return False


# return True is the attribute has an isSet member variable
def has_is_set_member(attribute):
    if attribute['isNumber'] or attribute['attType'] == 'boolean':
        return True
    return False


# return True if the element has the attribute specified
def has_attribute(element, attribute):
    if element is None:
        return False
    elif element['attribs'] is None:
        return False
    else:
        for i in range(0, len(element['attribs'])):
            if attribute == element['attribs'][i]['name']:
                return True
    return False


# return True if the listOf class for element has the attribute specified
def has_lo_attribute(element, attribute):
    if element is None:
        return False
    elif element['lo_attribs'] is None:
        return False
    else:
        for attrib in element['lo_attribs']:
            if attribute == attrib['name']:
                return True
    return False


# works out if any classes use this element
# with a different name
def overwrites_name(root, name):
    if root is None:
        return False
    overwrites = False
    unprefixed_name = strFunctions.remove_prefix(name)
    for element in root['baseElements']:
        for attrib in element['attribs']:
            if attrib['element'] == unprefixed_name and attrib['type'] != 'SIdRef':
                if not strFunctions.compare_no_case(name, attrib['xml_name']):
                    overwrites = True
    return overwrites


def get_static_extension_attribs(num_versions, lv_info):
    attribs = []
    att = dict({'name': 'packageName',
                'capAttName': 'PackageName',
                'attTypeCode': 'std::string&',
                'attType': 'string',
                'memberName': ''})
    attribs.append(att)
    att = dict({'name': 'defaultLevel',
                'capAttName': 'DefaultLevel',
                'attTypeCode': 'unsigned int',
                'attType': 'unsigned integer',
                'memberName': lv_info[-1]['core_level']})
    attribs.append(att)
    att = dict({'name': 'defaultVersion',
                'capAttName': 'DefaultVersion',
                'attTypeCode': 'unsigned int',
                'attType': 'unsigned integer',
                'memberName': lv_info[-1]['core_version']})
    attribs.append(att)
    att = dict({'name': 'defaultPackageVersion',
                'capAttName': 'DefaultPackageVersion',
                'attTypeCode': 'unsigned int',
                'attType': 'unsigned integer',
                'memberName': lv_info[-1]['pkg_version']})
    attribs.append(att)
    for i in range(0, num_versions):
        this_lv = lv_info[i]
        name = 'xmlnsL{1}V{2}V{0}'.format(this_lv['pkg_version'], this_lv['core_level'], this_lv['core_version'])
        cap_name = strFunctions.upper_first(name)
        att = dict({'name': name,
                    'capAttName': cap_name,
                    'attTypeCode': 'std::string&',
                    'attType': 'string',
                    'memberName': [this_lv['pkg_version'], this_lv['core_level'], this_lv['core_version']]})
        attribs.append(att)

    return attribs


# get an enumeration of the typecodes of the elements
def get_typecode_enum(elements):
    value = []
    strvalue = []
    max_length = 0
    for i in range(0, len(elements)):
        tc = elements[i]['typecode']
        if len(tc) > max_length:
            max_length = len(tc)
        value.append(tc)
        strvalue.append(elements[i]['name'])
    return [value, strvalue, max_length]


# get enumeration values
def get_enum(element, class_name = ''):
    # this function works slightly differently with enums for documentation
    # it will only have a classname for them
    if class_name == '':
        name = element['name']
        value = []
        strvalue = []
        max_length = 0
        origsplittc = []
        for i in range(0, len(element['values'])):
            tc = element['values'][i]['name']
            if len(tc) > max_length:
                max_length = len(tc)
            value.append(tc)
            strvalue.append(element['values'][i]['value'])
            if i == 0:
                origsplittc = tc.split('_')
            else:
                splittc = tc.split('_')
                if len(splittc) < len(origsplittc):
                    origsplittc = splittc
        # newtc = ''
        # for i in range(0, len(origsplittc)-1):
        #     newtc = newtc + origsplittc[i] + '_'
        # tc = newtc + 'INVALID'
        # if len(tc) > max_length:
        #     max_length = len(tc)
        # value.append(tc)
        # strvalue.append('invalid {0}'.format(name))
        return [value, strvalue, max_length]
    else:
        name = element['name']
        nameclass = class_name + strFunctions.upper_first(name)
        value = []
        strvalue = []
        for i in range(0, len(element['values'])):
            tc = element['values'][i]['name']
            value.append(tc)
            strvalue.append(element['values'][i]['value'])
        # tc = get_prefix(nameclass) + '_INVALID'
        # value.append(tc)
        # strvalue.append('invalid {0}'.format(nameclass))
        return [value, strvalue]



def get_default_enum_value(attribute):
    default = 'INVALID'
    name = attribute['element']
    enums = attribute['root']['enums']
    for enum in enums:
        if name == enum['name']:
            default = enum['values'][-1]['name']
            return default
    return default


def get_first_enum_value(attribute):
    value = ''
    name = attribute['element']
    enums = attribute['root']['enums']
    for i in range(0, len(enums)):
        if name == enums[i]['name']:
            value = enums[i]['values'][0]['value']
            break
    return value


def get_prefix(name):
    prefix = ''
    first = True
    for i in range(0, len(name)):
        char = name[i]
        if char.isupper():
            if first:
                prefix += char
                first = False
            else:
                prefix += '_{0}'.format(char)
        else:
            prefix += char.upper()
    return prefix


def get_typecode_format(name, language):
    tc = language.upper()
    for i in range(0, len(name)):
        char = name[i]
        if char.isupper():
            tc += '_'
        tc += char.upper()
    return tc


def get_max_length(elements, attribute):
    if elements is None:
        return 0
    if attribute not in elements[0]:
        return 0
    else:
        max_len = len(elements[0][attribute])
    for i in range(1, len(elements)):
        if len(elements[i][attribute]) > max_len:
            max_len = len(elements[i][attribute])
    return max_len


def get_other_element_children(this_object, element):
    other_children = []
    child = get_class(element['element'], this_object['root'])
    if child is None or 'lo_attribs' not in child:
        return other_children
    for i in range(0, len(child['lo_attribs'])):
        if child['lo_attribs'][i]['type'] == 'element':
            other_children.append(child['lo_attribs'][i]['element'])
    return other_children

# get children that are concrete instanstaitions
def get_concrete_children(concretes, root, reqd_only, base_attributes, name):
    children = []
    for j in range(0, len(concretes)):
        if concretes[j]['element'] == 'CSGeometry':
            continue;
        grandchildren = get_children(concretes[j]['element'],
                                     root, reqd_only, '', base_attributes)
        children.append(grandchildren)
    if not reqd_only:
        children = insert_list_of(children, name, root)
    return children


# get the child elements of the class name
def get_children(name, root, reqd_only, xml_name='', base_attribs=[]):
    child = get_class(name, root)
    if not child:
        if name == 'ASTNode':
            return dict({'name': 'math', 'children': []})
        else:
            return dict({'name': name, 'children': []})
    children = []
    num_attribs = len(child['attribs'])
    if (has_children(child['attribs'])):
        for i in range(0, num_attribs):
            att_type = child['attribs'][i]['type']
            if att_type == 'element':
                # for distrib we have a child that is a list of children of itself
                # this will cause recursion
                if name != child['attribs'][i]['element']:
                    grandchildren = get_children(child['attribs'][i]['element'],
                                                 root, reqd_only, child['attribs'][i]['xml_name'])
                    children.append(grandchildren)
            elif att_type == 'lo_element':
                if 'concrete' in child['attribs'][i]:
                    num = len(child['attribs'][i]['concrete'])
                    if num == 0:
                        continue
                    elif name == 'MixedGeometry' and num > 0:
                        continue;
                    else:
                        base = get_class(child['attribs'][i]['element'], root)
                        grandchildren = get_concrete_children(child['attribs'][i]['concrete'],
                                                         root, reqd_only, base['attribs'], child['attribs'][i]['element'])
#                        for j in range(0, num):
#                            grandchildren = get_concrete_children(child['attribs'][i]['concrete'],
#                                                         root, reqd_only, '', base['attribs'])
#                            grandchildren = get_children(child['attribs'][i]['concrete'][j]['element'],
#                                                         root, reqd_only, '', base['attribs'])
                        children.append(grandchildren[0])
#                        if not reqd_only:
#                            grandchildren = insert_list_of(grandchildren, child['attribs'][i]['element'], root)

                else:
                    # for distrib we have a child that is a list of children of itself
                    # this will cause recursion
                    if name != child['attribs'][i]['element']:
                        grandchildren = get_children(child['attribs'][i]['element'],
                                                     root, reqd_only)
                        if not reqd_only:
                            grandchildren = insert_list_of(grandchildren, child['attribs'][i]['element'], root)
                        children.append(grandchildren)
            elif att_type == 'inline_lo_element':
                # for distrib we have a child that is a list of children of itself
                # this will cause recursion
                if name != child['attribs'][i]['element']:
                    grandchildren = get_children(child['attribs'][i]['element'],
                                                 root, reqd_only)
                    children.append(grandchildren)
            else:
                continue
    # need attributes from base class
    reqd_attribs = []
    for i in range(0, num_attribs):
        attrib = child['attribs'][i]
        if reqd_only:
            if attrib['reqd']:
                reqd_attribs.append(attrib)
        else:
            reqd_attribs.append(attrib)

    for i in range(0, len(base_attribs)):
        attrib = base_attribs[i]
        if reqd_only:
            if attrib['reqd']:
                reqd_attribs.append(attrib)
        else:
            reqd_attribs.append(attrib)
    if len(xml_name) > 0:
        name = xml_name
    return dict({'name': name, 'children': children, 'attribs': reqd_attribs})

# get a list of names of child elements
def get_child_elements(elements, lo_elements, root=None):
    child_elements = []
    typecode = 'TO_DO'
    for elem in elements:
        if elem['element'] != 'ASTNode' and elem['element'] != 'XMLNode':
            if root:
                thisclass = get_class(elem['element'], root)
                if thisclass and 'typecode' in thisclass:
                    typecode = thisclass['typecode']
            if 'concrete' in elem:
                conc = elem['concrete']
                concs = get_concretes(root, conc)
            else:
                concs = None
            name = strFunctions.remove_prefix(elem['name'])
            [used_child_name, unused] = strFunctions.remove_hyphens(name)
            if 'used_child_name' in elem and elem['used_child_name'] != '':
                used_child_name = elem['used_child_name']
            child_elements.append(dict({'name': name, 'typecode': typecode,
                                        'concrete': concs, 'element': elem['element'],
                                        'used_name': used_child_name}))
    for elem in lo_elements:
        if elem['element'] != 'ASTNode*' and elem['element'] != 'XMLNode*':
            if root:
                thisclass = get_class(strFunctions.lower_first(elem['element']), root)
                if thisclass and 'typecode' in thisclass:
                    typecode = thisclass['typecode']
            if 'concrete' in elem:
                conc = elem['concrete']
                concs = get_concretes(root, conc)
            else:
                concs = None
            xmlname = strFunctions.singular(elem['name'])
            name = strFunctions.lower_first(strFunctions.remove_prefix(elem['element']))
            if not elem['is_plugin'] and (xmlname != name):
                name = xmlname
            name = strFunctions.remove_prefix(elem['name'])
            used_child_name = name
            if 'used_child_name' in elem and elem['used_child_name'] != '':
                used_child_name = elem['used_child_name']
            child_elements.append(dict({'name': name, 'typecode': typecode,
                                        'concrete': concs, 'element': elem['element'],
                                        'used_name': used_child_name}))
    return child_elements

# insert a listOfParent into the tree
def insert_list_of(original, child_name, root):
    child = get_class(child_name, root)
    lo_name = strFunctions.list_of_name(child['name'])
    if 'lo_elementName' in child and len(child['lo_elementName']) > 0:
        lo_name = child['lo_elementName']
    lo_attribs = []
    for att in child['lo_attribs']:
        lo_attribs.append(att)
    lo_children = []
    if isinstance(original, list):
        for element in original:
            lo_children.append(element)
        new_child = []
        new_child.append(dict({'name': lo_name, 'children': lo_children, 'attribs': lo_attribs}))
    else:
        lo_children.append(original)
        new_child = dict({'name': lo_name, 'children': lo_children, 'attribs': lo_attribs})
    return new_child



# create a tree structure with each plugin listing its direct children
# and each class listing its direct children
# if reqd_only is false it will add the listOf elements as well
def create_object_tree(pkg_object, reqd_only = True):
    tree = []
    root = None
    for i in range(0, len(pkg_object['plugins'])):
        branch = None
        plugin = pkg_object['plugins'][i]
        children = []
        if len(plugin['extension']) > 0:
            root = plugin['extension'][0]['root']
        for j in range(0, len(plugin['extension'])):
            children.append(get_children(plugin['extension'][j]['name'],
                                         root, reqd_only))
        if not root and len(plugin['lo_extension']) > 0:
            root = plugin['lo_extension'][0]['root']
        for j in range(0, len(plugin['lo_extension'])):
            grandchildren = get_children(plugin['lo_extension'][j]['name'],
                                         root, reqd_only, plugin['lo_extension'][j]['xml_name'])
            if not reqd_only:
                grandchildren = insert_list_of(grandchildren, plugin['lo_extension'][j]['name'], root)
            children.append(grandchildren)
        branch = dict({'base': plugin['sbase'],
                       'ext': 'core',
                       'children': children,
                       'attribs': plugin['attribs']})
        tree.append(branch)
    return tree


#return true if the attribute type given represents a number
def is_number(att_type):
    number = False
    if att_type == 'double' or att_type == 'uint' or att_type == 'int':
        number = True
    return number

#return true if the attribute type given represents an element
def is_element(att_type):
    element = False
    if att_type == 'element' or att_type == 'lo_element' or \
                    att_type == 'inline_lo_element':
        element = True
    return element

# create a list of attribute types and names for use with generic attribute functions
def sort_attributes(all_attributes):
    double_atts = []
    uint_atts = []
    int_atts = []
    bool_atts = []
    string_atts = []
    attributes = get_unique_attributes(all_attributes)
    for attrib in attributes:
        att_type = attrib['attType']
        if att_type == 'double':
            double_atts.append(attrib)
        elif att_type == 'boolean':
            bool_atts.append(attrib)
        elif att_type == 'unsigned integer':
            uint_atts.append(attrib)
        elif att_type == 'integer':
            int_atts.append(attrib)
        elif att_type == 'string' or att_type == 'enum':
            string_atts.append(attrib)
    return dict({'double_atts': double_atts,
                 'bool_atts': bool_atts,
                 'uint_atts': uint_atts,
                 'int_atts': int_atts,
                 'string_atts': string_atts})
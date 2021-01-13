#!/usr/bin/env python
#
# @file    query.py
# @brief   general functions for querying objects
# @author  Frank Bergmann
# @author  Sarah Keating
# @author  Matthew Gillman
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

"""General functions for querying objects"""

from . import strFunctions


def has_sid_ref(attributes):
    """
    Iterate over dictionaries (representing attribute nodes) to see if
    any attribute nodes are of type `SIdRef`

    :param attributes: structure containing attribute dictionaries
    :return: Return True if any of the `<attribute>` nodes are of type `SIdRef`

    e.g. the following will return `True` (... to represent content).

    .. code-block:: xml

       <attributes>
          <attribute ... />
          <attribute name="id" required="false" type="SId" abstract="false"/>
          <attribute ... />
       </attributes>

   """
    if any(attribute['type'] == 'SIdRef' for attribute in attributes):
        return True
    return False


def get_sid_refs(attributes, unit=False):
    """
    Return a set of attributes that are of type `SIdRef` or `UnitSidRef`

    :param attributes: The set of attributes we wish to select from.
    :param unit: True to match on `UnitSidRef`, otherwise match on `SidRef`.
    :return: the list of attributes which match.
    """
    sid_refs = []
    if unit:
        match = 'UnitSIdRef'
    else:
        match = 'SIdRef'
    for i in range(0, len(attributes)):
        if strFunctions.compare_no_case(attributes[i]['type'], match):
            sid_refs.append(attributes[i])
    return sid_refs


def get_sid_refs_for_class(working_class):
    """
    Return a set of attributes that are SIdRefs for the given class.

    :param working_class: TODO I'm not sure of this one.
    :return: the list of selected attributes, if any.
    """
    sid_refs = []
    child_element = get_class(working_class['element'],
                              working_class['root'])
    if child_element is not None:
        sid_refs = get_sid_refs(child_element['attribs'])
    return sid_refs


def has_children(attributes):
    """
    Return True if any of the attributes refer to elements
    (i.e. `type` is 'element', 'lo_element' or 'inline_lo_element')

    :param attributes: the attributes to check
    :return: `True` if at least one type match

    e.g.

    .. code-block:: xml

       <attribute name="boundaryMin" required="true" type="element"
          element="Boundary" abstract="false"/>

    or

    .. code-block:: xml

       <listOfAttribute name="defaultTerm" required="true" type="element"
          element="DefaultTerm" abstract="false" />

    would both return `True`.
    """
    for attribute in attributes:
        att_type = attribute['type']
        if att_type in ['element', 'lo_element', 'inline_lo_element']:
            return True
    return False


def has_children_not_math(attributes):
    """
    Return True if any of the attributes refer to elements but *not* math

    :param attributes: the <attribute> nodes we want to check
    :return: see above.

    e.g. this attribute node would not match:

    .. code-block:: xml

       <attribute name="math" required="true" type="element" element="ASTNode*...>

    """
    for i in range(0, len(attributes)):
        if attributes[i]['type'] == 'lo_element':
            return True
        elif attributes[i]['type'] == 'element' \
                and attributes[i]['name'] != 'math':
            return True
    return False


def get_class(name, root_object):
    """
    Return the class with the matching name from the root object.

    :param name: name of the class to find
    :param root_object: dict of all elements
    :return: the structure representing class `name`

    The `get_class()` function is designed to find the specific `name`
    of an sbml class within the root_object, which will be the big
    structure created by parseXML.
    """
    if root_object is None:
        return None
    if root_object['baseElements'] is None:
        return None

    if name.startswith('listOf') or name.startswith('ListOf'):
        name = strFunctions.singular(name[6:])
    else:
        name = strFunctions.upper_first(name)

    for i in range(0, len(root_object['baseElements'])):
        if name == root_object['baseElements'][i]['name']:
            return root_object['baseElements'][i]


def is_inline_child(class_object):
    """
    If this object is an 'inline child', get list of inline parents.

    :param class_object: structure representing a class
    :return: list of parents objects for which this class is an inline child

    According to the manual:

    `On occasion an element may contain multiple children of the same type
    which are not specified as being within a listOf element. From a code
    point of view it is easier to consider these children as being within
    a listOf element as this provides functionality to access and
    manipulate potentially variable numbers of child elements.
    The 'inline_lo_element' type allows the user to specify that there are
    multiple instances of the same child element but that these do not occur
    within a specified ListOf element.`

    e.g. The parameter nodes here are not inline children
    (and child element type = 'lo_element'):

    .. code-block:: xml

       <container>
           <listOfParameters>
               <parameter attributes= . . . />
               <parameter attributes= . . . />
               . . .
           </listOfParameters>
       </container>

    but the parameter nodes here are inline children.
    (Child element type = 'inline_lo_element'):

    .. code-block:: xml

       <container>
           <parameter attributes= . . . />
           <parameter attributes= . . . />
           . . .
       </container>

    NB A single parameter node like the following has type = 'element':

    .. code-block:: xml

       <container>
           <parameter attributes= . . . />
       </container>

    This function is called from ../code_files/CppHeaderFile.py,
    which iterates over the list returned.
    """
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


# Sarah added issue: Sort out is_inline_child and get_inline_parents #35


def get_inline_parents(class_object):
    """
    TODO I'm guessing an inline parent is the node enclosing
    a set of inline children, as in the last function?

    :param class_object:
    :return:
    """
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


def get_parent_class(class_object):
    """
    NB Open Github Issue: Revise query get_parent_class code #36

    Return the parent class of this class.
    if it is not given we assume it is a child of a plugin
    and get the base of the plugin.

    :param class_object: the object representing the class.
    :return: parent class, if found.

    e.g. in the following XML, the 'unit' attribute is an element of type 'Unit'
    so

    .. code-block:: default

       get_parent_class(class_object_for Unit)

    would return

    .. code-block:: default

       'ArrayChild'

    .. code-block:: xml

       <element name="ArrayChild" typeCode="SBML_TEST_ARRAYCHILD" hasListOf="false" hasChildren="false" hasMath="false" childrenOverwriteElementName="false" baseClass="SBase" abstract="false" elementName="arrayChild">
          <attributes>
             <attribute name="unit" required="false" type="element" element="Unit" abstract="false"/>
          </attributes>
       </element>
    """
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
                    return base
                    # parent = base
                    # found = True
                    # break
            if not found:
                for extension in plugin['extension']:
                    if extension['name'] == name:
                        return base
                        # parent = base
                        # found = True
                        # break
            # if found:
            #    break

    if not found and len(parent) == 0:
        for element in class_object['root']['baseElements']:
            if element['name'] != name:
                for attrib in element['attribs']:
                    if attrib['element'] == name:
                        return element['name']
                        # parent = element['name']
                        # found = True
                        # break
            # if found:
            #    break

    return parent


def get_concretes(root_object, concrete_list):
    """
    Return a list of the actual concrete classes.

    :param root_object: dict of all elements
    :param concrete_list:
    :return:
    """
    concretes = []
    for c in concrete_list:
        add_concrete_to_list(root_object, c, concretes)
    return concretes


def is_instantiated(element):
    """
    Basic function that checks whether the given element is instantiated.

    :param element: the element object to check.
    :returns: True if instantiated

    TODO add description of line with string equality check
    """
    if element is None:
        return False
    if 'concrete' not in element:
        return False
    if 'element' not in element:
        return False
    for c in element['concrete']:
        if c['element'] == element['element']:
            return True
    return False


def add_concrete_to_list(root, concrete, mylist):
    """
    Add the non-abstract class to the list `mylist`

    :param root: dict of all elements
    :param concrete:
    :param mylist:
    :return: returns nothing
    """
    current = get_class(concrete['element'], root)

    if current is not None:
        # sometimes the baseclass is also instantiated
        # (the ui calls the property isbaseclass)
        if current['abstract'] is False or is_instantiated(current):
            concrete['typecode'] = current['typecode']
            found = False
            i = 0
            while not found and i < len(mylist):
                if mylist[i]['element'] == concrete['element']:
                    found = True
                i += 1
            if not found:
                mylist.append(concrete)
        else:
            for c in current['concrete']:
                # full comparison too expensive ... causes stackoverflow,
                # just compare the element name
                if c['element'] != concrete['element']:
                    add_concrete_to_list(root, c, mylist)
                else:
                    concrete['typecode'] = current['typecode']
                    found = False
                    i = 0
                    while not found and i < len(mylist):
                        if mylist[i]['element'] == concrete['element']:
                            found = True
                        i += 1
                    if not found:
                        mylist.append(concrete)


def separate_attributes(full_attributes):
    """
    Return a set of attributes with any elements/lo_elements removed,
    populating the version information.

    :param full_attributes:
    :return: the filtered list of attributes
    """
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


def get_version_attributes(attributes, version):
    """
    Return attributes for the given version only.

    :param attributes: list of attribute objects.
    :param version: the version we are matching on
    :return: the list of matching attributes
    """
    ver_attribs = []
    for i in range(0, len(attributes)):
        att_type = attributes[i]['attType']
        if att_type != 'element' and att_type != 'lo_element':
            if attributes[i]['version'] == version:
                ver_attribs.append(attributes[i])
    return ver_attribs


def get_version_elements(elements, version):
    """
    Return elements for the given version only.

    :param elements: list of element objects.
    :param version: the version we are matching on
    :return: the list of matching elements
    """
    ver_elems = []
    for i in range(0, len(elements)):
        if elements[i]['version'] == version:
            ver_elems.append(elements[i])
    return ver_elems


def get_unique_attributes(full_attributes):
    """
    Return a set of unique attributes.
    Any with multiple versions appear only once.

    :param full_attributes: list of all attribute objects
    :return: returns the list of unique attributes.
    """
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
    """

    :param name:
    :param match_name: the name to match on
    :param list_elements: the elements to check
    :return: the element that matches, or None if no match.
    """
    element = None
    if not list_elements:
        return element
    for existing in list_elements:
        if existing[name] == match_name:
            return existing
    return element


def has_array(attributes):
    """
    Check if any of the attributes represented in a list are of type 'array'.

    :param attributes: list representing the attribute nodes to check
    :return: return `True` if any of the attributes are of type 'array'.

    e.g. if the following attribute node was represented in the list,
    we would return `True`:

    .. code-block:: xml

       <attribute name="samples" required="true" type="array"
            element="int" abstract="false"/>
    """
    if any(attribute['type'] == 'array' for attribute in attributes):
        return True
    return False


def has_vector(attributes):
    """
    Check if any of the attributes represented in a list are of type 'vector'.

    :param attributes: list representing the attribute nodes to check
    :return: Return `True` if any of the attributes are of type 'vector'

    e.g. if the following attribute node was represented in the list,
    we would return `True`:

    .. code-block:: xml

       <attribute name="value" required="false" type="vector"
            element="double" abstract="false"/>
    """
    if any(attribute['type'] == 'vector' for attribute in attributes):
        return True
    return False


def has_other_packages(attributes):
    """
    Check to see if a list of attributes have other packages.

    :param attributes: the list to check
    :return: Tuple with `True` if any of the attributes have another package,
             plus a list of packages (empty if `False`).

    e.g. the following entries would result in a return of

    .. code-block:: default

       [True, ['layout']]

    .. code-block:: xml

       <elements>
           <element name="LineEnding" ...>
             <attributes>
               <attribute name="boundingBox" required="false" type="element"
                       element="BoundingBox" abstract="false"/>
             </attributes>
           </element>
       ...
       </elements>
       <mappings>
           <mapping name="BoundingBox" package="layout"/>
       </mappings>

    Note: the additional attribute information is populated by the
    BaseCppFile `expand_class()` and `expand_attributes()` functions.
    """
    list_pkgs = []
    has_pack = False
    for attribute in attributes:
        if 'other_package' in attribute and attribute['other_package']:
            has_pack = True
            list_pkgs.append(attribute['other_package'])
    return [has_pack, list_pkgs]


def is_string(attribute):
    """
    Is the attribute of Type string?

    :param attribute: attribute to check
    :return: return `True` if the attribute is of Type string
    """
    if attribute['attType'] == 'string':
        return True
    return False


def has_is_set_member(attribute):
    """
    return True if the attribute has an isSet member variable.

    :param attribute: an attribute object
    :return: `True` if attribute has `isSet` member variable, `False` otherwise

    e.g. in order to determine in code whether an attribute of type
    boolean or number has been explicitly set, the variable, say `constant`,
    is stored with an additional `isSetConstant` variable of type boolean
    that can be queried to determine if the variable value has been
    explicitly set

    Consider Foo class with member variables `constant` (boolean) and
    `number` (unsigned int, defaulting to 0):

    .. code-block:: xml

       <foo/>

    would result in variables:

    .. code-block:: default

       mConstant = False
       mIsSetConstant = False
       mNumber = 0
       mIsSetNumber = False

    whereas

    .. code-block:: xml

       <foo constant="false" number="0"/>

    would result in variables:

    .. code-block:: default

       mConstant = False
       mIsSetConstant = True
       mNumber = 0
       mIsSetNumber = True

    Deviser creates an `isSetXYZ` variable for any attribute that
    is a number or a boolean
    """
    if attribute['isNumber'] or attribute['attType'] == 'boolean':
        return True
    return False


def has_attribute(element, attribute):
    """
    Does this element have this particular attribute?

    :param element: element node object to check.
    :param attribute: the attribute to check
    :return: return `True` if the element has the attribute specified

    e.g. if the element represented this node:

    .. code-block:: xml

       <element name="FooRule" typeCode="SBML_FOO_RULE" ... >

    and we wanted to know if it had the typeCode attribute,
    we would return `True`.
    """
    if element is None:
        return False
    elif element['attribs'] is None:
        return False
    else:
        for i in range(0, len(element['attribs'])):
            if attribute == element['attribs'][i]['name']:
                return True
    return False


def has_lo_attribute(element, attribute):
    """
    Does the element's `listOf` class have the attribute specified?

    :param element: an element object
    :param attribute: an attribute object
    :return: Return `True` if `listOf` class for element has attribute specified
    """
    if element is None:
        return False
    elif isV2BaseAttribute(element, attribute):
        return True
    elif element['lo_attribs'] is None:
        return False
    else:
        for attrib in element['lo_attribs']:
            if attribute == attrib['name']:
                return True
    return False


def isV2BaseAttribute(element, attribute):
    """
    Is the base version of this element equal to 2 ?

    :param element: an element object
    :param attribute: an attribute object
    :return: `True` if `base_version` is 2, `False` otherwise.
    """
    if attribute != 'id' and attribute != 'name':
        return False
    if 'root' in element:
        if 'base_version' in element['root']:
            if element['root']['base_version'] == 2:
                return True
    return False


def overwrites_name(root, name):
    """
    Works out if the xml name used for this attribute is different from the
    name used in the dict objects.

    :param root_object: dict of all elements
    :param name: the name of the attribute to check
    :return: `True` if the attribute has a different xml name, `False` otherwise
    """
    if root is None:
        return False
    overwrites = False
    unprefixed_name = strFunctions.remove_prefix(name)
    for element in root['baseElements']:
        for attrib in element['attribs']:
            if attrib['element'] == unprefixed_name and \
                    attrib['type'] != 'SIdRef':
                if not strFunctions.compare_no_case(name, attrib['xml_name']):
                    overwrites = True
    return overwrites


def get_static_extension_attribs(num_versions, lv_info):
    """
    Creates a set of attributes that will be used with a
    PkgExtension class when generating the code.
    This facilitates the reuse of class code generation for member
    variable getters and setters.

    :param num_versions:
    :param lv_info:
    :return: list of attribute dictionaries
    """
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
        name = 'xmlnsL{1}V{2}V{0}'.format(this_lv['pkg_version'],
                                          this_lv['core_level'],
                                          this_lv['core_version'])
        cap_name = strFunctions.upper_first(name)
        att = dict({'name': name,
                    'capAttName': cap_name,
                    'attTypeCode': 'std::string&',
                    'attType': 'string',
                    'memberName': [this_lv['pkg_version'],
                                   this_lv['core_level'],
                                   this_lv['core_version']]})
        attribs.append(att)

    return attribs


def get_typecode_enum(elements):
    """
    Get an enumeration of the typecodes of the elements

    :param elements: representation of element nodes to enumerate.
    :return: tuple (see example)

    e.g. given the following XML elements, represented in object form
    by 'elements' parameter:

    .. code-block:: xml

       <element name="Algebraic" typeCode="SBML_FOO_ALGEBRAIC"
                hasListOf="false" baseClass="FooRule" abstract="false"/>
       <element name="FooRate" typeCode="SBML_FOO_FOORATE" hasListOf="false"
                baseClass="Assignment" abstract="false" elementName="rate"/>
       <element name="FooAssignment" typeCode="SBML_FOO_FOOASSIGNMENT"
                hasListOf="false" baseClass="Assignment" abstract="false"
                elementName="assignment"/>

    would return

    .. code-block:: default

       [value, strvalue, max_length]

    with contents:

    .. code-block:: default

       value = ["SBML_FOO_ALGEBRAIC", "SBML_FOO_FOORATE",
                "SBML_FOO_FOOASSIGNMENT"]
       strvalue = ["Algebraic", "FooRate", "FooAssignment"]
       max_length = length of longest typecode = 22 (characters).
    """
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


def get_enum(element, class_name=''):
    """
    Get enumeration values.
    This function works slightly differently with enums for documentation;
    it will only have a classname for them.

    :param element:
    :param class_name:
    :return:
    """
    name = element['name']
    value = []
    strvalue = []

    if class_name == '':
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
        # nameclass = class_name + strFunctions.upper_first(name)
        _ = class_name + strFunctions.upper_first(name)
        for i in range(0, len(element['values'])):
            tc = element['values'][i]['name']
            value.append(tc)
            strvalue.append(element['values'][i]['value'])
        # tc = get_prefix(nameclass) + '_INVALID'
        # value.append(tc)
        # strvalue.append('invalid {0}'.format(nameclass))
        return [value, strvalue]


def get_default_enum_value(attribute):
    """
    Returns the default/invalid value for the enumeration of
    values for the given attribute.

    :param attribute: attribute dict for required
    :return: string representing the invalid enum value or 'INVALID' if
             the attribute dict does not have an element name corresponding to a
             listed enumeration.

    e.g. An attribute

    .. code-block:: xml

       <attribute name="transitionEffect" required="true" type="enum"
                  element="TransitionOutputEffect" abstract="false" />

    uses values from the enumeration specified

    .. code-block:: xml

       <enum name="TransitionOutputEffect">
         <enumValues>
           <enumValue name="OUTPUT_TRANSITION_EFFECT_PRODUCTION"
                      value="production" />
           <enumValue name="OUTPUT_TRANSITION_EFFECT_ASSIGNMENT_LEVEL"
                      value="assignment level" />
         </enumValues>
       </enum>

    Processing of the XML should have added a further value to the
    enum equivalent to

    .. code-block:: xml

       <enumValue name="OUTPUT_TRANSITION_INVALID"
                  value="invalid TransitionOutputEffect value" />

    The function returns the name of the invalid enumeration value.
    For example:

    .. code-block::

       get_default_enum_value(attribute dict for transitionEffect)

    will return string

    .. code-block:: default

       'OUTPUT_TRANSITION_INVALID'
    """
    default = 'INVALID'
    name = attribute['element']
    enums = attribute['root']['enums']
    for enum in enums:
        if name == enum['name']:
            default = enum['values'][-1]['name']
            return default
    return default


def get_first_enum_value(attribute):
    """
    Returns the first value in the list for the enumeration of values
    for the given attribute.

    :param attribute: attribute dict for required
    :return: string representing the first enum value or '' if
             the attribute dict does not have an element name corresponding to a
             listed enumeration.

    e.g. An attribute

    .. code-block:: xml

       <attribute name="transitionEffect" required="true" type="enum"
                  element="TransitionOutputEffect" abstract="false" />

    uses values from the enumeration specified:

    .. code-block:: xml

       <enum>
         <enum name="TransitionOutputEffect">
         <enumValues>
           <enumValue name="OUTPUT_TRANSITION_EFFECT_PRODUCTION"
                      value="production" />
           <enumValue name="OUTPUT_TRANSITION_EFFECT_ASSIGNMENT_LEVEL"
                      value="assignment level" />
         </enumValues>
       </enum>

    Processing of the XML should have added a further value to the
    enum equivalent to

    .. code-block:: xml

       <enumValue name="OUTPUT_TRANSITION_INVALID"
                  value="invalid TransitionOutputEffect value" />

    because as part of the parseXML and then further parsing of the results
    the code will automatically add an INVALID value to any enumeration

    The function returns the name of the first listed enumeration value.
    For example:

    .. code-block:: default

       get_First_enum_value(attribute dict for transitionEffect)

    will return string

    .. code-block:: default

       'OUTPUT_TRANSITION_EFFECT_PRODUCTION'
    """
    value = ''
    name = attribute['element']
    enums = attribute['root']['enums']
    for i in range(0, len(enums)):
        if name == enums[i]['name']:
            value = enums[i]['values'][0]['value']
            break
    return value

# commented out as is not used but may be needed so leave for now
# def get_prefix(name):
#     """
#     TODO revisit
#
#     :param name:
#     :return:
#     """
#     prefix = ''
#     first = True
#     for i in range(0, len(name)):
#         char = name[i]
#         if char.isupper():
#             if first:
#                 prefix += char
#                 first = False
#             else:
#                 prefix += '_{0}'.format(char)
#         else:
#             prefix += char.upper()
#     return prefix
#

def get_typecode_format(classname, language):
    """
    Formats the typecode for the class in a standard format:
    uppercase language followed by '_' followed by uppercase classname
    with any classnames using camelcase separated by '_'
    where class name contains camelcase

    :param classname: name of the class
    :param language: name of the XML language being targeted
    :return: string representing the formatted typecode

    e.g.

    .. code-block:: default

       get_typecode_format(model, sbml)

    returns

    .. code-block:: default

       SBML_MODEL

    and

    .. code-block:: default

       get_typecode_format(speciesReference, sbml)

    returns

    .. code-block:: default

       SBML_SPECIES_REFERENCE

    and

    .. code-block:: default

       get_typecode_format(model, sedml)

    returns

    .. code-block:: default

        SEDML_MODEL
   """
    tc = language.upper()
    for i in range(0, len(classname)):
        char = classname[i]
        if char.isupper():
            tc += '_'
        tc += char.upper()
    return tc


def get_max_length(elements, attribute):
    """
    Get the max length of the attribute in a list of elements

    :param elements: list of objects representing element nodes.
    :param attribute: an attribute in those nodes

    e.g. given the following elements:

    .. code-block:: XML

       <element name="Algebraic" typeCode="SBML_FOO_ALGEBRAIC" ... />
       <element name="FooRate" typeCode="SBML_FOO_FOORATE" ... />
       <element name="FooAssignment" typeCode="SBML_FOO_FOOASSIGNMENT" .../>

    a function call like:

    .. code-block:: default

       width = query.get_max_length(elements, 'name')

    will return the length of the longest string in

    .. code-block:: default

       ["Algebraic", "FooRate", "FooAssignment"]

    TODO will this throw an exception if elements other
    than the first one do *not* have the attribute?
    Is that possible? <--- Issue added to Github:
    Look at query get_max_length #38
    """
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
    """
    Return a list of the names of other elements that may be
    children of the ListOfFoo element.

    :param this_object: object dict to be queried
    :param element: dict of element (e.g. `Foo`) for which we wish to discover
        whether the corresponding `listOfFoo` element contains children of a type
        other than `Foo`
    :return: list of names of any children of a `listOfFoo` that are not of
        type `Foo`

    e.g. In this case the `DefaultTerm` object is contained within the
    `ListOfFunctionTerms` which also contains `FunctionTerm` Objects:

    .. code-block:: xml

       <listOfFunctionsTerms>
           <functionTerm ... />
           <functionTerm ... />
           <defaultTerm ... />
       </listOfFunctionTerms>

    .. code-block:: default

       get_other_element_children(parent_object dict, functionTerm object dict)

    returns

    .. code-block:: default

       ['defaultTerm']
    """
    other_children = []
    child = get_class(element['element'], this_object['root'])
    if child is None or 'lo_attribs' not in child:
        return other_children
    for i in range(0, len(child['lo_attribs'])):
        if child['lo_attribs'][i]['type'] == 'element':
            other_children.append(child['lo_attribs'][i]['element'])
    return other_children


def get_concrete_children(concretes, root, reqd_only, base_attributes, name):
    """
    Get children that are concrete instantiations

    :param concretes:
    :param root: dict of all elements
    :param reqd_only:
    :param base_attributes:
    :param name:
    :return:

    TODO an example would be helpful.
    """
    children = []
    for j in range(0, len(concretes)):
        if concretes[j]['element'] == 'CSGeometry':
            continue
        grandchildren = get_children(concretes[j]['element'],
                                     root, reqd_only, '', base_attributes)
        children.append(grandchildren)
    if not reqd_only:
        children = insert_list_of(children, name, root)
    return children


def get_children(name, root, reqd_only, xml_name='', base_attribs=[]):
    """
    Get the child elements of the class name

    :param name:
    :param root:
    :param reqd_only:
    :param xml_name:
    :param base_attribs:
    :return:

    TODO lots of explanation needed!
    """
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
                # for distrib we have a child that is a list of
                # children of itself
                # this will cause recursion
                if name != child['attribs'][i]['element']:
                    grandchildren = \
                        get_children(child['attribs'][i]['element'],
                                     root, reqd_only,
                                     child['attribs'][i]['xml_name'])
                    children.append(grandchildren)
            elif att_type == 'lo_element':
                if 'concrete' in child['attribs'][i]:
                    num = len(child['attribs'][i]['concrete'])
                    if num == 0:
                        continue
                    elif name == 'MixedGeometry' and num > 0:
                        continue
                    else:
                        base = get_class(child['attribs'][i]['element'], root)
                        grandchildren = \
                            get_concrete_children(
                                child['attribs'][i]['concrete'],
                                root, reqd_only, base['attribs'],
                                child['attribs'][i]['element'])

                        # for j in range(0, num):
                        #     grandchildren = get_concrete_children(
                        #         child['attribs'][i]['concrete'],
                        #         root, reqd_only, '', base['attribs'])
                        #     grandchildren =
                        #        get_children(
                        #          child['attribs'][i]['concrete']\
                        #                 [j]['element'],
                        #                 root, reqd_only, '',
                        #                 base['attribs'])

                        children.append(grandchildren[0])

                        # if not reqd_only:
                        #   grandchildren = insert_list_of(grandchildren,
                        #   child['attribs'][i]['element'], root)

                else:
                    # for distrib we have a child that is a list
                    # of children of itself
                    # this will cause recursion
                    if name != child['attribs'][i]['element']:
                        grandchildren = \
                            get_children(child['attribs'][i]['element'],
                                         root, reqd_only)
                        if not reqd_only:
                            grandchildren = \
                                insert_list_of(grandchildren,
                                               child['attribs'][i]['element'],
                                               root)
                        children.append(grandchildren)
            elif att_type == 'inline_lo_element':
                # for distrib we have a child that is a list of children
                # of itself
                # this will cause recursion
                if name != child['attribs'][i]['element']:
                    grandchildren = \
                        get_children(child['attribs'][i]['element'],
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


def get_child_elements(elements, lo_elements, root=None):
    """
    Get a list of names (and other info) of child elements.

    :param elements:
    :param lo_elements:
    :param root:
    :return: list of child element dictionaries
    """
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
            # if 'xml_name' in elem and elem['xml_name'] != '':
            #     name = elem['xml_name']
            [used_child_name, unused] = \
                strFunctions.remove_hyphens(elem['capAttName'])
            # if 'used_child_name' in elem and elem['used_child_name'] != '':
            #     used_child_name = elem['used_child_name']
            child_elements.append(dict({'name': name, 'typecode': typecode,
                                        'concrete': concs,
                                        'element': elem['element'],
                                        'used_name': used_child_name}))
    for elem in lo_elements:
        if elem['element'] != 'ASTNode*' and elem['element'] != 'XMLNode*':
            if root:
                thisclass = \
                    get_class(strFunctions.lower_first(elem['element']), root)
                if thisclass and 'typecode' in thisclass:
                    typecode = thisclass['typecode']
            if 'concrete' in elem:
                conc = elem['concrete']
                concs = get_concretes(root, conc)
            else:
                concs = None
            xmlname = strFunctions.\
                singular(strFunctions.remove_prefix(elem['name']))
            name = strFunctions.\
                lower_first(strFunctions.remove_prefix(elem['element']))
            if not elem['is_plugin'] and (xmlname != name):
                name = xmlname
            used_child_name = name
            if 'used_child_name' in elem and elem['used_child_name'] != '':
                used_child_name = elem['used_child_name']
            child_elements.append(dict({'name': name, 'typecode': typecode,
                                        'concrete': concs,
                                        'element': elem['element'],
                                        'used_name': used_child_name}))
    return child_elements


def insert_list_of(original, child_name, root):
    """
    insert a listOfParent into the tree

    :param original:
    :param child_name:
    :param root:
    :return: either a list of dictionaries, or a single dictionary,
             depending on context
    """
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
        new_child.append(dict({'name': lo_name, 'children': lo_children,
                               'attribs': lo_attribs}))
    else:
        lo_children.append(original)
        new_child = dict({'name': lo_name, 'children': lo_children,
                          'attribs': lo_attribs})
    return new_child


def create_object_tree(pkg_object, reqd_only=True):
    """
    Create a tree structure with each plugin listing its direct children
    and each class listing its direct children.
    If `reqd_only` is `False` it will add the `listOf` elements as well.

    :param pkg_object:
    :param reqd_only:
    :return: list of dictionaries
    """
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
                                         root, reqd_only,
                                         plugin['lo_extension'][j]['xml_name'])
            if not reqd_only:
                grandchildren = insert_list_of(
                    grandchildren,
                    plugin['lo_extension'][j]['name'], root)
            children.append(grandchildren)
        branch = dict({'base': plugin['sbase'],
                       'ext': 'core',
                       'children': children,
                       'attribs': plugin['attribs']})
        tree.append(branch)
    return tree


def is_number(att_type):
    """
    Does this attribute type represent a number?

    :param att_type: the type, e.g. "int", "SIdRef", "string", ...
    :param return: Return `True` if the attribute type given represents a number

    e.g. an attribute node like this

    .. code-block:: XML

       <attribute name="ordinal" required="true" type="int" abstract="false"/>

    has type "int", so would return `True`.

    TODO I'm assuming this is for <attribute> nodes?
    """
    number = False
    if att_type == 'double' or att_type == 'uint' or att_type == 'int':
        number = True
    return number


def is_element(att_type):
    """
    Does this attribute type represent an element?

    :param att_type: the type, e.g. "lo_element", "SIdRef", "string", ...
    :return: `True` if the attribute type given represents an element
    """
    element = False
    if att_type == 'element' or att_type == 'lo_element' or \
            att_type == 'inline_lo_element':
        element = True
    return element


def sort_attributes(all_attributes):
    """
    Create a list of attribute types and names for use with
    generic attribute functions.

    :param all_attributes:
    :return: dictionary of lists of different attribute types.
    """
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


def is_lo_repeated(class_object):
    """


    :param class_object:
    :return: True if
    """
    count = 0
    if 'root' not in class_object or class_object['root'] is None:
        return False
    elif 'lo_child' not in class_object or class_object['lo_child'] == '':
        return False
    else:
        child = class_object['lo_child']
    for element in class_object['root']['baseElements']:
        # if element['typecode'] == class_object['typecode']:
        #     # skip this element
        #     continue
        for attrib in element['attribs']:
            if attrib['type'] == 'lo_element' \
                    or attrib['type'] == 'inline_lo_element':
                if attrib['element'] == child:
                    if 'xml_name' in attrib and \
                            attrib['xml_name'].lower() != strFunctions. \
                            remove_prefix(attrib['element']).lower():
                        count = count + 1
    if count > 0:
        return True
    return False

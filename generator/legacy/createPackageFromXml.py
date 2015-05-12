# reads a package from given Deviser XML file

from xml.dom import *
from xml.dom.minidom import *
import weakref;
import os.path;
import strFunctions
import generalFunctions

def toBool(v):
  if (v == None): 
    return False
  return v.lower() in ("yes", "true", "1")

def toInt(v):
  if (v == None): 
    return 0
  return int(float(v))


def getValue(node, name):
  temp = node.getAttributeNode(name)
  if temp == None: 
    return None
  return temp.nodeValue


def findLoElement(elements, name):
  if elements == None or name == None: 
    return None
  for element in elements:
    currentLoName = generalFunctions.getListOfClassNameForElement(element);
    if currentLoName == name:
      return element
  return None

def findElement(elements, name):
  if elements == None or name == None: 
    return None
  for element in elements:
    if element['name'] == name:
      return element
  return None

def standardize_types(attrib_type):
    if attrib_type == 'boolean':
        return 'bool'
    elif attrib_type == 'unsigned integer':
        return 'uint'
    elif attrib_type == 'unsigned int':
        return 'uint'
    elif attrib_type == 'integer':
        return 'int'
    else:
        return attrib_type

def parseDeviserXML(filename):
  """
  Parses the given filename and returns a dictionary with
  the definition contained in it
  """

  packageName = ''
  number = 0
  offset = 0
  sbmlElements = []
  elements = []
  plugins = []
  enums = []

  dom = parse(filename)

  packageName = getValue( dom.documentElement, 'name')
  number = toInt(getValue( dom.documentElement, 'number'))
  offset = toInt(getValue( dom.documentElement, 'offset'))
  version = toInt(getValue( dom.documentElement, 'version'))
  required = getValue( dom.documentElement, 'required') == 'true'

  addPkgDecls = getValue(dom.documentElement, 'additionalDecls')
  addPkgDefs = getValue(dom.documentElement, 'additionalDefs')


  concrete_dict = dict({})

  # read concrete versions of abstract classes and fill dictionary
  for node in dom.getElementsByTagName('element'):
    elementName = getValue( node, 'name')
    concrete_list = []
    for concrete in node.getElementsByTagName('concrete'):
      concrete_list.append(
                           dict({
                                 'name': getValue(concrete, "name"), 
                                 'element':getValue(concrete, "element")}))
    concrete_dict[elementName] = concrete_list;

  # read element
  for node in dom.getElementsByTagName('element'):
    
    elementName = getValue( node, 'name')
    baseClass = getValue( node, 'baseClass')

    # currently all deviser generated classes have to derive from SBase or its
    # derived classes
    if baseClass == None:
      baseClass = 'SBase'

    typeCode = getValue( node, 'typeCode')
    hasMath = toBool( getValue( node, 'hasMath'))
    hasChildren = toBool( getValue( node, 'hasChildren'))
    hasListOf = toBool( getValue( node, 'hasListOf'))
    abstract = toBool(getValue(node, 'abstract'))
    childrenOverwriteElementName = toBool(getValue(node, 'childrenOverwriteElementName'))
    xmlElementName = getValue(node, 'elementName')
    xmlLoElementName = getValue(node, 'listOfName')
    xmlLoElementClassName = getValue(node, 'listOfClassName')

    addDecls = getValue(node, 'additionalDecls')
    addDefs = getValue(node, 'additionalDefs')

    attributes = []
    
    # add attributes
    for attr in node.getElementsByTagName('attribute'):
 
        attrName = getValue( attr, 'name')
        required = toBool(getValue( attr, 'required'))
        type = standardize_types(getValue( attr, 'type'))
        attrAbstract = toBool(getValue( attr, 'abstract'))
        attrElement = getValue( attr, 'element')
     

        attribute_dict = dict({
                                 'type': type, 
                                 'reqd' : required, 
                                 'name' : attrName, 
                                 'element':attrElement, 
                                 'abstract':attrAbstract,                                 
                                 })
        if attrAbstract:
          attribute_dict['concrete'] = concrete_dict[attrElement]

        attributes.append(attribute_dict)

          

    # construct element
    element = dict({
                    'name': elementName, 
                    'package': packageName, 
                    'typecode': typeCode, 
                    'hasListOf': hasListOf, 
                    'attribs':attributes, 
                    'hasChildren':hasChildren, 
                    'hasMath':hasMath, 
                    'childrenOverwriteElementName':childrenOverwriteElementName, 
                    'baseClass': baseClass,
                    'abstract' : abstract
                    })     
    if xmlElementName != None:
      element['elementName'] = xmlElementName
    
    if xmlLoElementName != None:
      element['lo_elementName'] = xmlLoElementName

    if xmlLoElementClassName  != None:
      element['lo_elementClassName'] = xmlLoElementClassName       

    if addDecls != None:
      if os.path.exists( os.path.dirname(filename) + '/' + addDecls):
        addDecls = os.path.dirname(filename) + '/' + addDecls
      element['addDecls'] = addDecls

    if addDefs != None:
      if os.path.exists( os.path.dirname(filename) + '/' + addDefs):
        addDefs = os.path.dirname(filename) + '/' + addDefs
      element['addDefs'] = addDefs

    if abstract:
      element['concrete'] = concrete_dict[elementName]

    elements.append(
                    dict({
                          'name': elementName, 
                          'typecode': typeCode, 
                          'isListOf': hasListOf
                          }))
    sbmlElements.append(element)
    
  for node in dom.getElementsByTagName('plugin'):

    plugElements = []
    extPoint = getValue( node, 'extensionPoint')
    addDecls = getValue(node, 'additionalDecls')
    addDefs = getValue(node, 'additionalDefs')
    package = getValue(node, 'package')
    typecode = getValue(node, 'typecode')

    attributes = []
    
    # read additional attributes
    for attr in node.getElementsByTagName('attribute'):
 
        attrName = getValue( attr, 'name')
        required = toBool(getValue( attr, 'required'))
        type = getValue( attr, 'type')
        attrAbstract = toBool(getValue( attr, 'abstract'))
        attrElement = getValue( attr, 'element')
     

        attribute_dict = dict({
                                 'type': type, 
                                 'reqd' : required, 
                                 'name' : attrName, 
                                 'element':attrElement, 
                                 'abstract':attrAbstract
                                 })
        if attrAbstract:
          attribute_dict['concrete'] = concrete_dict[attrElement]

        attributes.append(attribute_dict)

    # read references to elements
    for reference in node.getElementsByTagName('reference'):
      reference = getValue( reference, 'name')
      temp = findElement(elements, reference)
      if temp != None:
        plugElements.append(temp)
      else: 
        # uh oh ... we did not find the object, lets have another 
        # look, maybe it was a listOf class
        temp = findLoElement(sbmlElements, reference)
        if temp != None:
          # now just add it to the attributes
          lo_attr = dict({
                                 'type': 'lo_element', 
                                 'reqd' : True, 
                                 'name' : temp['name'], 
                                 'element':temp['name'], 
                                 'abstract':False
                                 })
          attributes.append(lo_attr)


    plugin_dict = dict({'sbase': extPoint, 'extension': plugElements, 'attribs':attributes})

    if package != None:
      plugin_dict['package'] = package
    if package != typecode:
      plugin_dict['typecode'] = typecode

    if addDecls != None:
      if os.path.exists( os.path.dirname(filename) + '/' + addDecls):
        addDecls = os.path.dirname(filename) + '/' + addDecls
      plugin_dict['addDecls'] = addDecls

    if addDefs != None:
      if os.path.exists( os.path.dirname(filename) + '/' + addDefs):
        addDefs = os.path.dirname(filename) + '/' + addDefs
      plugin_dict['addDefs'] = addDefs

    plugins.append( plugin_dict)

  for node in dom.getElementsByTagName('enum'):
    values = []
    enumName = getValue( node, 'name')

    for val in node.getElementsByTagName('enumValue'):
      values.append(dict({'name': getValue( val, 'name'), 'value': getValue( val, 'value')}))

    enums.append(dict({'name': enumName, 'values': values}))

  mappings = []
  for node in dom.getElementsByTagName('mapping'):
    mappings .append(dict({'name': getValue( node, 'name'), 'package': getValue( node, 'package')}))


  package = dict({
               'name' : packageName, 
               'elements': elements, 
               'plugins': plugins, 
               'number': number, 
               'sbmlElements': sbmlElements, 
               'enums': enums, 
               'offset': offset,
               'version' : version,
               'required' : required,
               'mappings': mappings
               })

  if addPkgDecls != None:
    if os.path.exists( os.path.dirname(filename) + '/' + addPkgDecls):
      addPkgDecls = os.path.dirname(filename) + '/' + addPkgDecls
    package['addDecls'] = addPkgDecls

  if addPkgDefs != None:
    if os.path.exists( os.path.dirname(filename) + '/' + addPkgDefs):
      addPkgDefs = os.path.dirname(filename) + '/' + addPkgDefs
    package['addDefs'] = addPkgDefs


  # link elements
  for elem in package['elements']:
      elem['root'] = package
      if elem.has_key('attribs'):
        for attr in elem['attribs']:
            attr['parent'] = elem
            attr['root'] = package
  
  for elem in package['sbmlElements']:
      elem['root'] = package
      if elem.has_key('attribs'):
        for attr in elem['attribs']:
            attr['parent'] = elem
            attr['root'] = package
      if elem.has_key('concrete'):
        for attr in elem['concrete']:
            attr['parent'] = elem
            attr['root'] = package


  return package


#parseDeviserXML("D:/Development/CsDeviser/Samples/spatial.xml")

  
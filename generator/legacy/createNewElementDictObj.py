#!/usr/bin/env python
#
# @file   createNewElementDictObj.py
# @brief  Create element object to pass to functions
# @author Sarah Keating
#

import sys

def createNewDictObj() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  qualSp = dict({'type':'SIdRef', 'reqd':True, 'name':'sidRef'})
  unit = dict({'type':'UnitSIdRef', 'reqd':True, 'name':'unitsRef'})
  unitA = dict({'type':'UnitSId', 'reqd':False, 'name':'units'})
#  math = dict({'type':'element', 'reqd':True, 'name':'element'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'string'})
  multiplier = dict({'type': 'double', 'reqd' : True, 'name':'double'})
  scale = dict({'type': 'int', 'reqd' : False, 'name':'int'})
  exp = dict({'type': 'uint', 'reqd' : True, 'name':'unsignedInt'})
  constant = dict({'type': 'bool', 'reqd' : False, 'name':'boolean'})
  attributes = [id, qualSp, unit, unitA, name, multiplier, scale, exp, constant]
  element = dict({'name': 'Input', 'package': 'Qual', 'typecode': 'SBML_QUAL_INPUT', 'hasListOf': True, 'attribs':attributes}) 
  return element

  #arrays
def createArraysDim() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  size = dict({'type': 'SIdRef', 'reqd' : True, 'name':'size'})
  dim = dict({'type': 'uint', 'reqd' : True, 'name':'arrayDimension'})
  attributes = [id, name, size, dim ]
  element = dict({'name': 'Dimension', 'package': 'Arrays', 'typecode': 'SBML_ARRAYS_DIMENSION', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createArraysIndex() :
  name = dict({'type': 'string', 'reqd' : True, 'name':'referencedAttribute'})
  dim = dict({'type': 'uint', 'reqd' : True, 'name':'arrayDimension'})
  math = dict({'type': 'element', 'reqd' : True, 'name':'math', 'element': 'Math'})
  attributes = [name, dim, math ]
  element = dict({'name': 'Index', 'package': 'Arrays', 'typecode': 'SBML_ARRAYS_INDEX', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':True}) 
  return element
#end of arrays

## Comp
def createSBaseRef() :
  portRef = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'portRef'})
  idRef = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'idRef'})
  unitRef = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'unitRef'})
  metaidRef = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'metaIdRef'})
  sbaseRef = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'sBaseRef'})
  attributes = [portRef, idRef, unitRef, metaidRef, sbaseRef]
  element = dict({'name': 'SBaseRef', 'package': 'Comp', 'typecode': 'SBML_COMP_DELETION', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element


def createCompDeletion() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  attributes = [id, name]
  element = dict({'name': 'Deletion', 'package': 'Comp', 'typecode': 'SBML_COMP_DELETION', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createCompSubModel() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  modelRef = dict({'type': 'SIdRef', 'reqd' : True, 'name' : 'modelRef'})
  timeConv = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'timeConversionFactor'})
  extentConv = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'extentConversionFactor'})
  loDel = dict({'type': 'lo_element', 'reqd' : False, 'name':'deletion', 'element': 'Deletion'})
  attributes = [id, name, modelRef, timeConv, extentConv, loDel]
  element = dict({'name': 'Submodel', 'package': 'Comp', 'typecode': 'SBML_COMP_SUBMODEL', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
  
def createCompPort() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  attributes = [id, name]
  element = dict({'name': 'Port', 'package': 'Comp', 'typecode': 'SBML_COMP_DELETION', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createCompReplacedE() :
  id = dict({'type': 'SIdRef', 'reqd' : True, 'name':'submodelRef'})
  timeConv = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'deletion'})
  extentConv = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'conversionFactor'})
  attributes = [id, timeConv, extentConv]
  element = dict({'name': 'ReplacedElement', 'package': 'Comp', 'typecode': 'SBML_COMP_DELETION', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createCompReplacedBy() :
  id = dict({'type': 'SIdRef', 'reqd' : True, 'name':'submodelRef'})
  attributes = [id]
  element = dict({'name': 'ReplacedBy', 'package': 'Comp', 'typecode': 'SBML_COMP_DELETION', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createCompExtModDef() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  src = dict({'type': 'string', 'reqd' : True, 'name' : 'source'})
  modelRef = dict({'type': 'SIdRef', 'reqd' : False, 'name' : 'modelRef'})
  attributes = [id, src, name, modelRef]
  element = dict({'name': 'ExternalModelDefinition', 'package': 'Comp', 'typecode': 'SBML_COMP_SUBMODEL', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element
  ##end of comp

## distrib
def createDistribInput() :
  id = dict({'type': 'string', 'reqd' : True, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  ind = dict({'type': 'uint', 'reqd' : True, 'name' : 'index'})
  attributes = [id, name, ind]
  element = dict({'name': 'DistribInput', 'package': 'Distrib', 'typecode': 'SBML_DISTRIB_INPUT', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
  
def createDistribDraw() :
  loInputs = dict({'type': 'lo_element', 'reqd' : False, 'name':'distribInput', 'element': 'DistribInput'})
  dist = dict({'type': 'element', 'reqd' : True, 'name':'UncertML', 'element': 'UncertMLNode'})
  attributes = [loInputs, dist]
  element = dict({'name': 'DrawFromDistribution', 'package': 'Distrib', 'typecode': 'SBML_DISTRIB_DRAW_FROM_DISTRIBUTION', 'hasListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
  
def createDistribUncertainty() :
  id = dict({'type': 'string', 'reqd' : False, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  dist = dict({'type': 'element', 'reqd' : True, 'name':'UncertML', 'element': 'UncertMLNode'})
  attributes = [id, name, dist]
  element = dict({'name': 'Uncertainty', 'package': 'Distrib', 'typecode': 'SBML_DISTRIB_UNCERTAINTY', 'hasListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
#end of distrib

  #fbc
def createFBCObj() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  reaction = dict({'type':'SIdRef', 'reqd':True, 'name':'reaction'})
  operation = dict({'type': 'string', 'reqd' : False, 'name':'operation'})
  value = dict({'type': 'double', 'reqd' : True, 'name':'value'})
  attributes = [id, reaction, operation, value]
  element = dict({'name': 'FluxBound', 'package': 'Fbc', 'typecode': 'SBML_FBC_FLUXBOUND', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createFBCObjective() :
  type = dict({'type': 'string', 'reqd' : True, 'name':'type'})
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  loFluxes = dict({'type': 'lo_element', 'reqd' : True, 'name':'fluxes', 'element': 'FluxObjective'})
  attributes = [type, id, loFluxes]
  element = dict({'name': 'Objective', 'package': 'Fbc', 'typecode': 'SBML_FBC_OBJECTIVE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createFBCFluxObjective() :
  reaction = dict({'type': 'SIdRef', 'reqd' : True, 'name':'reaction'})
  coeff = dict({'type': 'double', 'reqd' : True, 'name':'coefficient'})
  attributes = [reaction, coeff]
  element = dict({'name': 'FluxObjective', 'package': 'Fbc', 'typecode': 'SBML_FBC_FLUX_OBJECTIVE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element
#end of fbc

  #groups
def createGroupsMember() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  idRef = dict({'type':'SIdRef', 'reqd':False, 'name':'idRef'})
  metaIdRef = dict({'type': 'string', 'reqd' : False, 'name':'metaIdRef'})
  attributes = [id, name, idRef, metaIdRef]
  element = dict({'name': 'Member', 'package': 'Groups', 'typecode': 'SBML_GROUPS_MEMBER', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createGroupsMemberConstraint() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  distinct = dict({'type':'string', 'reqd':False, 'name':'distinctAttribute'})
  ident = dict({'type': 'string', 'reqd' : False, 'name':'identicalAttribute'})
  attributes = [id, name, distinct, ident]
  element = dict({'name': 'MemberConstraint', 'package': 'Groups', 'typecode': 'SBML_GROUPS_MEMBER_CONSTRAINT', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createGroupsGroup() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  kind = dict({'type':'string', 'reqd':True, 'name':'kind'})
  loMems = dict({'type': 'lo_element', 'reqd' : False, 'name':'member', 'element': 'Member'})
  loMCs = dict({'type': 'lo_element', 'reqd' : False, 'name':'memberConstraint', 'element': 'MemberConstraint'})
  attributes = [id, name, kind, loMems, loMCs]
  element = dict({'name': 'Group', 'package': 'Groups', 'typecode': 'SBML_GROUPS_GROUP', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
#end of groups

#layout
def createLayoutBB() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  name = dict({'type': 'element', 'reqd' : True, 'name':'position', 'element': 'Point'})
  dist = dict({'type': 'element', 'reqd' : True, 'name':'dimensions', 'element': 'Dimensions'})
  attributes = [id, name, dist]
  element = dict({'name': 'BoundingBox', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_BOUNDINGBOX', 'hasListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createLayoutCompGlyph() :
  id = dict({'type': 'SIdRef', 'reqd' : False, 'name':'compartment'})
  x = dict({'type': 'double', 'reqd' : False, 'name':'order'})
  attributes = [id, x]
  element = dict({'name': 'CompartmentGlyph', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_COMPARTMENTGLYPH', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createLayoutCubicBez() :
  name = dict({'type': 'element', 'reqd' : True, 'name':'basePoint1', 'element': 'Point'})
  dist = dict({'type': 'element', 'reqd' : True, 'name':'basePoint2', 'element': 'Point'})
  attributes = [name, dist]
  element = dict({'name': 'CubicBezier', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_CUBICBEZIER', 'hasListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createLayoutCurve() :
  name = dict({'type': 'lo_element', 'reqd' : True, 'name':'curveSegment', 'element': 'LineSegment'})
  attributes = [name]
  element = dict({'name': 'Curve', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_CURVE', 'hasListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createLayoutDimensions() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  x = dict({'type': 'double', 'reqd' : True, 'name':'width'})
  y = dict({'type': 'double', 'reqd' : True, 'name':'height'})
  z = dict({'type': 'double', 'reqd' : False, 'name':'depth'})
  attributes = [id, x, y, z]
  element = dict({'name': 'Dimensions', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_DIMENSIONS', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createLayoutGraphObj() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'metaidRef'})
  dist = dict({'type': 'element', 'reqd' : True, 'name':'boundingBox', 'element': 'BoundingBox'})
  attributes = [id, name, dist]
  element = dict({'name': 'GraphicalObject', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_GRAPHICALOBJECT', 'hasListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createLayoutLayout() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'metaidRef'})
  dist = dict({'type': 'element', 'reqd' : True, 'name':'dimensions', 'element': 'Dimensions'})
  loCG = dict({'type': 'lo_element', 'reqd' : False, 'name':'compartmentGlyph', 'element': 'CompartmentGlyph'})
  loSG = dict({'type': 'lo_element', 'reqd' : False, 'name':'speciesGlyph', 'element': 'SpeciesGlyph'})
  loRG = dict({'type': 'lo_element', 'reqd' : False, 'name':'reactionGlyph', 'element': 'ReactionGlyph'})
  loTG = dict({'type': 'lo_element', 'reqd' : False, 'name':'textGlyph', 'element': 'TextGlyph'})
  loAddG = dict({'type': 'lo_element', 'reqd' : False, 'name':'graphicalObject', 'element': 'GraphicalObject'})
  attributes = [id, name, dist, loCG, loSG, loRG, loTG, loAddG]
  element = dict({'name': 'Layout', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_LAYOUT', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createLayoutLineSeg() :
  id = dict({'type': 'string', 'reqd' : True, 'name':'xsi:type'})
  name = dict({'type': 'element', 'reqd' : True, 'name':'start', 'element': 'Point'})
  dist = dict({'type': 'element', 'reqd' : True, 'name':'end', 'element': 'Point'})
  attributes = [id, name, dist]
  element = dict({'name': 'LineSegment', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_LINESEGMENT', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createLayoutPoint() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  x = dict({'type': 'double', 'reqd' : True, 'name':'x'})
  y = dict({'type': 'double', 'reqd' : True, 'name':'y'})
  z = dict({'type': 'double', 'reqd' : False, 'name':'z'})
  attributes = [id, x, y, z]
  element = dict({'name': 'Point', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_POINT', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createLayoutReactionGlyph() :
  id = dict({'type': 'SIdRef', 'reqd' : True, 'name':'reaction'})
  loSRG = dict({'type': 'lo_element', 'reqd' : True, 'name':'speciesReference', 'element':'SpeciesReferenceGlyph'})
  curve = dict({'type': 'element', 'reqd' : False, 'name':'curve', 'element': 'Curve'})
  attributes = [id, loSRG, curve]
  element = dict({'name': 'ReactionGlyph', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_REACTIONGLYPH', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
   
def createLayoutSpeciesGlyph() :
  id = dict({'type': 'SIdRef', 'reqd' : False, 'name':'species'})
  attributes = [id]
  element = dict({'name': 'SpeciesGlyph', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_SPECIESGLYPH', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createLayoutSpeciesRefGlyph() :
  id = dict({'type': 'SIdRef', 'reqd' : True, 'name':'speciesGlyph'})
  name = dict({'type': 'SIdRef', 'reqd' : False, 'name':'speciesReference'})
  dist = dict({'type': 'string', 'reqd' : False, 'name':'roleType'})
  curve = dict({'type': 'element', 'reqd' : False, 'name':'curve', 'element': 'Curve'})
  attributes = [id, name, dist, curve]
  element = dict({'name': 'SpeciesReferenceGlyph', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_SPECIESREFERENCEGLYPH', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element
  
def createLayoutTextGlyph() :
  id = dict({'type': 'SIdRef', 'reqd' : False, 'name':'graphicalObject'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'text'})
  dist = dict({'type': 'SIdRef', 'reqd' : False, 'name':'originOfText'})
  attributes = [id, name, dist]
  element = dict({'name': 'TextGlyph', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_TEXTGLYPH', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element
  
def createLayoutRefGlyph() :
  id = dict({'type': 'SIdRef', 'reqd' : True, 'name':'glyph'})
  name = dict({'type': 'SIdRef', 'reqd' : False, 'name':'reference'})
  dist = dict({'type': 'string', 'reqd' : False, 'name':'role'})
  attributes = [id, name, dist]
  element = dict({'name': 'ReferenceGlyph', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_REFERENCEGLYPH', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createLayoutGeneralGlyph() :
  id = dict({'type': 'SIdRef', 'reqd' : False, 'name':'reference'})
  sub = dict({'type': 'lo_element', 'reqd' : False, 'name':'subGlyph', 'element':'GraphicalObject'})
  ref = dict({'type': 'lo_element', 'reqd' : False, 'name':'referenceGlyph', 'element':'ReferenceGlyph'})
  curve = dict({'type': 'element', 'reqd' : False, 'name':'curve', 'element': 'Curve'})
  attributes = [id, sub, ref, curve]
  element = dict({'name': 'GeneralGlyph', 'package': 'Layout', 'typecode': 'SBML_LAYOUT_GENERALGLYPH', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

  #end of layout

#multi
def createCompartmentReference():
  att1 = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  att2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  att3 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'compartment'})
  attributes = [att1, att2, att3]
  element = dict({'name': 'CompartmentReference', 'package': 'Multi', 'typecode': 'SBML_MULTI_COMPARTMENT_REFERENCE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createDenotedSpeciesTypeComponentIndex():
  att1 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'speciesTypeComponentIndex'})
  attributes = [att1]
  element = dict({'name': 'DenotedSpeciesTypeComponentIndex', 'package': 'Multi', 'typecode': 'SBML_MULTI_DENOTED_SPECIES_TYPE_COMPONENT_INDEX', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createInSpeciesTypeBond():
  att1 = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  att2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  att3 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'bindingSite1'})
  att4 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'bindingSite2'})
  attributes = [att1, att2, att3, att4]
  element = dict({'name': 'InSpeciesTypeBond', 'package': 'Multi', 'typecode': 'SBML_MULTI_IN_SPECIES_TYPE_BOND', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createMultiSpeciesType():
  att1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  att2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  att3 = dict({'type': 'bool', 'reqd' : True, 'name':'isBindingSite'})
  att4 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'compartment'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'speciesFeatureType', 'element': 'SpeciesFeatureType'})
  child2 = dict({'type': 'lo_element', 'reqd': False, 'name': 'speciesTypeInstance', 'element': 'SpeciesTypeInstance'})
  child3 = dict({'type': 'lo_element', 'reqd': False, 'name': 'speciesTypeComponentIndex', 'element': 'SpeciesTypeComponentIndex'})
  child4 = dict({'type': 'lo_element', 'reqd': False, 'name': 'inSpeciesTypeBond', 'element': 'InSpeciesTypeBond'})
  attributes = [att1, att2, att3, att4, child1, child2, child3, child4]
  element = dict({'name': 'MultiSpeciesType', 'package': 'Multi', 'typecode': 'SBML_MULTI_SPECIES_TYPE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
  
def createOutwardBindingSite():
  att1 = dict({'type': 'BindingStatus', 'reqd' : True, 'name':'bindingStatus'})
  att2 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'component'})
  attributes = [att1, att2]
  element = dict({'name': 'OutwardBindingSite', 'package': 'Multi', 'typecode': 'SBML_MULTI_OUTWARD_BINDING_SITE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createPossibleSpeciesFeatureValue():
  att1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  att2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  att3 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'numericValue'})
  attributes = [att1, att2, att3]
  element = dict({'name': 'PossibleSpeciesFeatureValue', 'package': 'Multi', 'typecode': 'SBML_MULTI_POSSIBLE_SPECIES_FEATURE_VALUE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createSpeciesFeature():
  att1 = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  att2 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'speciesFeatureType'})
  att3 = dict({'type': 'uint', 'reqd' : True, 'name':'occur'})
  att4 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'component'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'speciesFeatureValue', 'element': 'SpeciesFeatureValue'})
  attributes = [att1, att2, att3, att4, child1]
  element = dict({'name': 'SpeciesFeature', 'package': 'Multi', 'typecode': 'SBML_MULTI_SPECIES_FEATURE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
  
def createSpeciesFeatureChange():
  att1 = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  att2 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'reactantSpeciesFeature'})
  att3 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'productSpeciesFeature'})
  attributes = [att1, att2, att3]
  element = dict({'name': 'SpeciesFeatureChange', 'package': 'Multi', 'typecode': 'SBML_MULTI_SPECIES_FEATURE_CHANGE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createSpeciesFeatureType():
  att1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  att2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  att3 = dict({'type': 'uint', 'reqd' : True, 'name':'occur'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'possibleSpeciesFeatureValue', 'element': 'PossibleSpeciesFeatureValue'})
  attributes = [att1, att2, att3, child1]
  element = dict({'name': 'SpeciesFeatureType', 'package': 'Multi', 'typecode': 'SBML_MULTI_SPECIES_FEATURE_TYPE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createSpeciesFeatureValue():
  att1 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'value'})
  attributes = [att1]
  element = dict({'name': 'SpeciesFeatureValue', 'package': 'Multi', 'typecode': 'SBML_MULTI_SPECIES_FEATURE_VALUE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createSpeciesTypeComponentIndex():
  att1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  att2 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'component'})
  att3 = dict({'type': 'uint', 'reqd' : True, 'name':'occur'})
  att4 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'identifyingParent'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'denotedSpeciesTypeComponentIndex', 'element': 'DenotedSpeciesTypeComponentIndex'})
  attributes = [att1, att2, att3, att4, child1]
  element = dict({'name': 'SpeciesTypeComponentIndex', 'package': 'Multi', 'typecode': 'SBML_MULTI_SPECIES_TYPE_COMPONENT_INDEX', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createSpeciesTypeComponentMapInProduct():
  att1 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'reactant'})
  att2 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'reactantComponent'})
  att3 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'productComponent'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'speciesFeatureChange', 'element': 'SpeciesFeatureChange'})
  attributes = [att1, att2, att3, child1]
  element = dict({'name': 'SpeciesTypeComponentMapInProduct', 'package': 'Multi', 'typecode': 'SBML_MULTI_SPECIES_TYPE_COMPONENT_MAP_IN_PRODUCT', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
 
def createSpeciesTypeInstance():
  att1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  att2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  att3 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'speciesType'})
  att4 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'compartmentReference'})
  att5 = dict({'type': 'uint', 'reqd' : True, 'name':'occur'})
  attributes = [att1, att2, att3, att4, att5]
  element = dict({'name': 'SpeciesTypeInstance', 'package': 'Multi', 'typecode': 'SBML_MULTI_SPECIES_TYPE_INSTANCE', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

#these are hacks for the plugins as I have not yet implemented attributes on plugins
def createCompartmentPlugin():
  att1 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'compartmentType'})
  att2 = dict({'type': 'bool', 'reqd' : True, 'name':'isType'})
  attributes = [att1, att2]
  element = dict({'name': 'CompPlugin', 'package': 'Multi', 'typecode': 'HACK', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createSpeciesPlugin():
  att1 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'speciesType'})
  attributes = [att1]
  element = dict({'name': 'SpeciesPlugin', 'package': 'Multi', 'typecode': 'HACK', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createReactionPlugin():
  att1 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'compartmentType'})
  att2 = dict({'type': 'bool', 'reqd' : False, 'name':'isIntraSpeciesReaction'})
  attributes = [att2]
  element = dict({'name': 'ReactPlugin', 'package': 'Multi', 'typecode': 'HACK', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createSimplePlugin():
  att1 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'compartmentReference'})
  att2 = dict({'type': 'bool', 'reqd' : True, 'name':'isType'})
  attributes = [att1]
  element = dict({'name': 'SimplePlugin', 'package': 'Multi', 'typecode': 'HACK', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

#end of multi  
  
  #qual
def createQualSpecies() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  comp = dict({'type': 'SIdRef', 'reqd' : True, 'name':'compartment'})
  constant = dict({'type': 'bool', 'reqd' : True, 'name':'constant'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  initL = dict({'type': 'int', 'reqd' : False, 'name':'initialLevel'})
  maxL = dict({'type': 'int', 'reqd' : False, 'name':'maxLevel'})
  attributes = [id, comp, constant, name, initL, maxL ]
  element = dict({'name': 'QualitativeSpecies', 'package': 'Qual', 'typecode': 'SBML_QUAL_QUALITATIVE_SPECIES', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createQualTransition() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  loInputs = dict({'type': 'lo_element', 'reqd' : False, 'name':'input', 'element': 'Input'})
  loOutputs = dict({'type': 'lo_element', 'reqd' : False, 'name':'output', 'element': 'Output'})
  loFunc = dict({'type': 'lo_element', 'reqd' : False, 'name':'functionTerm', 'element': 'FunctionTerm'})
  attributes = [id, name, loInputs, loOutputs, loFunc ]
  element = dict({'name': 'Transition', 'package': 'Qual', 'typecode': 'SBML_QUAL_TRANSITION', 'hasListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createQualInput() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  qs = dict({'type': 'SIdRef', 'reqd' : True, 'name':'qualitativeSpecies'})
  effect = dict({'type': 'string', 'reqd' : True, 'name':'transitionEffect'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  sign = dict({'type': 'string', 'reqd' : False, 'name':'sign'})
  maxL = dict({'type': 'int', 'reqd' : False, 'name':'thresholdLevel'})
  attributes = [id, qs, effect, name, sign, maxL ]
  element = dict({'name': 'Input', 'package': 'Qual', 'typecode': 'SBML_QUAL_INPUT', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createQualOutput() :
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  qs = dict({'type': 'SIdRef', 'reqd' : True, 'name':'qualitativeSpecies'})
  effect = dict({'type': 'string', 'reqd' : True, 'name':'transitionEffect'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  maxL = dict({'type': 'int', 'reqd' : False, 'name':'outputLevel'})
  attributes = [id, qs, effect, name, maxL ]
  element = dict({'name': 'Output', 'package': 'Qual', 'typecode': 'SBML_QUAL_OUTPUT', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createQualFunctionTerm() :
  maxL = dict({'type': 'int', 'reqd' : True, 'name':'resultLevel'})
  math = dict({'type': 'element', 'reqd' : True, 'name':'math', 'element': 'Math'})
  attributes = [maxL, math ]
  element = dict({'name': 'FunctionTerm', 'package': 'Qual', 'typecode': 'SBML_QUAL_FUNCTION_TERM', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':True}) 
  return element

def createQualDefaultTerm() :
  maxL = dict({'type': 'int', 'reqd' : True, 'name':'resultLevel'})
  attributes = [maxL ]
  element = dict({'name': 'DefaultTerm', 'package': 'Qual', 'typecode': 'SBML_QUAL_DEFAULT_TERM', 'hasListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element
#end of qual

#render - not complete !!

def createRenderColorDefinition():
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  value = dict({'type': 'string', 'reqd' : False, 'name':'value'})
  attributes = [id, value]
  element = dict({'name': 'ColorDefinition', 'package': 'Render', 'typecode': 'SBML_RENDER_COLORDEFINITION', 'hasListOf': True, 'attribs':   attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

#end of render

#req

def createReqChangedMath():
  id = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  effect = dict({'type': 'bool', 'reqd' : True, 'name':'viableWithoutChange'})
  name = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  changed = dict({'type': 'string', 'reqd' : True, 'name':'changedBy'})
  attributes = [id, name, changed, effect ]
  element = dict({'name': 'ChangedMath', 'package': 'Req', 'typecode': 'SBML_REQ_CHANGED_MATH', 'hasListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False})
  return element

#end of req


#spatial

def createSpatialCompartmentMapping() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  domainType = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domainType'})
  unitSize = dict({'type': 'double', 'reqd' : True, 'name':'unitSize'})
  attributes = [id, domainType, unitSize]
  element = dict(
                 {'name': 'CompartmentMapping', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_COMPARTMENTMAPPING', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialSymbolReference() :
  spatialRef = dict({'type': 'SIdRef', 'reqd' : True, 'name':'spatialRef'})
  attributes = [spatialRef]
  element = dict(
                 {'name': 'SpatialSymbolReference', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_SPATIALSYMBOLREFERENCE', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCoordinateIndex() :
  coordinate = dict({'type': 'int', 'reqd' : True, 'name':'coordinate'})
  attributes = [coordinate]
  element = dict(
                 {'name': 'CoordinateIndex', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_COORDINATEINDEX', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialDiffusionCoefficient() :
  variable = dict({'type': 'SIdRef', 'reqd' : True, 'name':'variable'})
  type = dict({'type': 'int', 'reqd' : True, 'name':'type'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'coordinateIndex', 'element': 'CoordinateIndex'})
  attributes = [variable, type, child1 ]
  element = dict(
                 {'name': 'DiffusionCoefficient', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_DIFFUSIONCOEFFICIENT', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialAdvectionCoefficient() :
  variable = dict({'type': 'SIdRef', 'reqd' : True, 'name':'variable'})
  coordinateIndex = dict({'type': 'int', 'reqd' : True, 'name':'coordinateIndex'})
  attributes = [variable, coordinateIndex]
  element = dict(
                 {'name': 'AdvectionCoefficient', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_ADVECTIONCOEFFICIENT', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialBoundaryCondition() :
  variable = dict({'type': 'SIdRef', 'reqd' : True, 'name':'variable'})
  type = dict({'type': 'int', 'reqd' : True, 'name':'type'})
  coordinateBoundary = dict({'type': 'SIdRef', 'reqd' : False, 'name':'coordinateBoundary'})
  boundaryDomainType = dict({'type': 'SIdRef', 'reqd' : False, 'name':'boundaryDomainType'})
  attributes = [variable, type, coordinateBoundary, boundaryDomainType]
  element = dict(
                 {'name': 'BoundaryCondition', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_BOUNDARYCONDITION', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialGeometry() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  coordinateSystem = dict({'type': 'int', 'reqd' : True, 'name':'coordinateSystem'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'coordinateComponent', 'element': 'CoordinateComponent'})
  child2 = dict({'type': 'lo_element', 'reqd': False, 'name': 'domainType', 'element': 'DomainType'})
  child3 = dict({'type': 'lo_element', 'reqd': False, 'name': 'domain', 'element': 'Domain'})
  child4 = dict({'type': 'lo_element', 'reqd': False, 'name': 'adjacentDomain', 'element': 'AdjacentDomain'})
  child5 = dict({'type': 'lo_element', 'reqd': False, 'name': 'geometryDefinition', 'element': 'GeometryDefinition'})
  attributes = [id, coordinateSystem, child1, child2, child3, child4, child5]
  element = dict(
                 {'name': 'Geometry', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_GEOMETRY', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':True, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCoordinateComponent() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  componentType = dict({'type': 'int', 'reqd' : True, 'name':'componentType'})
  unit = dict({'type': 'SIdRef', 'reqd' : True, 'name':'unit'})
  child1 = dict({'type': 'Boundary', 'reqd': True, 'name': 'boundaryMin'})
  child2 = dict({'type': 'Boundary', 'reqd': True, 'name': 'boundaryMax'})
  attributes = [id, componentType, unit, child1, child2]
  element = dict(
                 {'name': 'CoordinateComponent', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_COORDINATECOMPONENT', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':True, 
                  'hasMath':False
                  }) 
  return element

def createSpatialBoundary() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  value = dict({'type': 'double', 'reqd' : True, 'name':'value'})
  attributes = [id, value]
  element = dict(
                 {'name': 'Boundary', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_BOUNDARY', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialDomainType() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  spatialDimension = dict({'type': 'int', 'reqd' : True, 'name':'spatialDimension'})
  attributes = [id, spatialDimension]
  element = dict(
                 {'name': 'DomainType', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_DOMAINTYPE', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialDomain() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  domainType = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domainType'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'interiorPoint', 'element': 'InteriorPoint'})
  attributes = [id, domainType, child1]
  element = dict(
                 {'name': 'Domain', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_DOMAIN', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialInteriorPoint() :
  #id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  coord1 = dict({'type': 'double', 'reqd' : True, 'name':'coord1'})
  coord2 = dict({'type': 'double', 'reqd' : False, 'name':'coord2'})
  coord3 = dict({'type': 'double', 'reqd' : False, 'name':'coord3'})
  attributes = [coord1, coord2, coord3]
  element = dict(
                 {'name': 'InteriorPoint', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_INTERIORPOINT', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialAdjacentDomain() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  domain1 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domain1'})
  domain2 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domain2'})
  attributes = [id, domain1, domain2]
  element = dict(
                 {'name': 'AdjacentDomain', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_ADJACENTDOMAINS', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialGeometryDefinition() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  attributes = [id]
  element = dict(
                 {'name': 'GeometryDefinition', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_GEOMETRYDEFINITION', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialAnalyticGeometry() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'AnalyticVolume', 'element': 'AnalyticVolume'})
  attributes = [id, child1]
  element = dict(
                 {'name': 'AnalyticGeometry', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_ANALYTICGEOMETRY', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialAnalyticVolume() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  functionType = dict({'type': 'int', 'reqd' : True, 'name':'functionType'})
  ordinal = dict({'type': 'int', 'reqd' : False, 'name':'ordinal'})
  domainType = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domainType'})
  attributes = [id, functionType, ordinal, domainType]
  element = dict(
                 {'name': 'AnalyticVolume', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_ANALYTICVOLUME', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':True
                  }) 
  return element

def createSpatialSampledFieldGeometry() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'sampledVolume', 'element': 'SampledVolume'})
  child2 = dict({'type': 'SampledField', 'reqd': False, 'name': 'sampledField', 'element': 'SampledField'})
  attributes = [id, child1, child2]
  element = dict(
                 {'name': 'SampledFieldGeometry', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_SAMPLEDFIELDGEOMETRY', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':True, 
                  'hasMath':False
                  }) 
  return element

def createSpatialSampledVolume() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  domainType = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domainType'})
  sampledValue = dict({'type': 'double', 'reqd' : True, 'name':'sampledValue'})
  minValue = dict({'type': 'double', 'reqd' : False, 'name':'minValue'})
  maxValue = dict({'type': 'double', 'reqd' : False, 'name':'maxValue'})
  attributes = [id, domainType, sampledValue, minValue, maxValue]
  element = dict(
                 {'name': 'SampledVolume', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_SAMPLEDVOLUME', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialSampledField() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  dataType = dict({'type': 'string', 'reqd' : False, 'name':'dataType'})
  numSamples1 = dict({'type': 'int', 'reqd' : True, 'name':'numSamples1'})
  numSamples2 = dict({'type': 'int', 'reqd' : False, 'name':'numSamples2'})
  numSamples3 = dict({'type': 'int', 'reqd' : False, 'name':'numSamples3'})
  interpolationType = dict({'type': 'string', 'reqd' : False, 'name':'interpolationType'})
  encoding = dict({'type': 'string', 'reqd' : False, 'name':'encoding'})
  child1 = dict({'type': 'ImageData', 'reqd': True, 'name': 'imageData', 'element': 'ImageData'})
  attributes = [id, dataType, numSamples1, numSamples2, numSamples3, interpolationType, encoding, child1]
  element = dict(
                 {'name': 'SampledField', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_SAMPLEDFIELD', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':True, 
                  'hasMath':False
                  }) 
  return element

def createSpatialImageData() :
  samples = dict({'type': 'int*', 'reqd' : True, 'name':'samples'})
  samplesLength = dict({'type': 'int', 'reqd' : True, 'name':'samplesLength'})
  dataType = dict({'type': 'string', 'reqd' : True, 'name':'dataType'})
  attributes = [samples, samplesLength, dataType]
  element = dict(
                 {'name': 'ImageData', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_IMAGEDATA', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGeometry() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'csgObject', 'element': 'CSGObject'})
  attributes = [id, child1]
  element = dict(
                 {'name': 'CSGeometry', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGGEOMETRY', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGObject() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  domainType = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domainType'})
  ordinal = dict({'type': 'int', 'reqd' : True, 'name':'ordinal'})
  attributes = [id, domainType, ordinal]
  element = dict(
                 {'name': 'CSGObject', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGOBJECT', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGNode() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  attributes = [id]
  element = dict(
                 {'name': 'CSGNode', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGNODE', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGPrimitive() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  primitiveType = dict({'type': 'string', 'reqd' : True, 'name':'primitiveType'})
  attributes = [id, primitiveType]
  element = dict(
                 {'name': 'CSGPrimitive', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGPRIMITIVE', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGPseudoPrimitive() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  csgObjectRef = dict({'type': 'SIdRef', 'reqd' : True, 'name':'csgObjectRef'})
  attributes = [id, csgObjectRef]
  element = dict(
                 {'name': 'CSGPseudoPrimitive', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGPSEUDOPRIMITIVE', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGSetOperator() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  operationType = dict({'type': 'int', 'reqd' : True, 'name':'operationType'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'csgNode', 'element': 'CSGNode'})
  attributes = [id, operationType, child1]
  element = dict(
                 {'name': 'CSGSetOperator', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGSETOPERATOR', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGTransformation() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  child1 = dict({'type': 'CSGNode', 'reqd': False, 'name': 'csgNode', 'element': 'CSGNode'})
  attributes = [id, child1]
  element = dict(
                 {'name': 'CSGTransformation', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGTRANSFORMATION', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':True, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGTranslation() :
  translateX = dict({'type': 'double', 'reqd' : True, 'name':'translateX'})
  translateY = dict({'type': 'double', 'reqd' : False, 'name':'translateY'})
  translateZ = dict({'type': 'double', 'reqd' : False, 'name':'translateZ'})
  attributes = [translateX, translateY, translateZ]
  element = dict(
                 {'name': 'CSGTranslation', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGTRANSLATION', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGRotation() :
  rotateAxisX = dict({'type': 'double', 'reqd' : True, 'name':'rotateAxisX'})
  rotateAxisY = dict({'type': 'double', 'reqd' : False, 'name':'rotateAxisY'})
  rotateAxisZ = dict({'type': 'double', 'reqd' : False, 'name':'rotateAxisZ'})
  rotateAngleInRadians = dict({'type': 'double', 'reqd' : True, 'name':'rotateAngleInRadians'})
  attributes = [rotateAxisX, rotateAxisY, rotateAxisZ, rotateAngleInRadians]
  element = dict(
                 {'name': 'CSGRotation', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGROTATION', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGScale() :
  scaleX = dict({'type': 'double', 'reqd' : True, 'name':'scaleX'})
  scaleY = dict({'type': 'double', 'reqd' : False, 'name':'scaleY'})
  scaleZ = dict({'type': 'double', 'reqd' : False, 'name':'scaleZ'})
  attributes = [scaleX, scaleY, scaleZ]
  element = dict(
                 {'name': 'CSGScale', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGSCALE', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialCSGHomogeneousTransformation() :
  forwardTransformation = dict({'type': 'TransformationComponent', 'reqd' : True, 'name':'forwardTransformation', 'element': 'TransformationComponent'})
  reverseTransformation = dict({'type': 'TransformationComponent', 'reqd' : True, 'name':'reverseTransformation', 'element': 'TransformationComponent'})
  attributes = [forwardTransformation, reverseTransformation]
  element = dict(
                 {'name': 'CSGHomogeneousTransformation', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_CSGHOMOGENEOUSTRANSFORMATION', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialTransformationComponent() :
  components = dict({'type': 'double*', 'reqd' : True, 'name':'components'})
  componentsLength = dict({'type': 'double*', 'reqd' : True, 'name':'componentsLength'})
  attributes = [components, componentsLength]
  element = dict(
                 {'name': 'TransformationComponent', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_TRANSFORMATIONCOMPONENTS', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialParametricGeometry() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  child1 = dict({'type': 'lo_element', 'reqd': False, 'name': 'spatialPoint', 'element': 'SpatialPoint'})
  child2 = dict({'type': 'lo_element', 'reqd': False, 'name': 'parametricObject', 'element': 'ParametricObject'})
  attributes = [id, child1, child2]
  element = dict(
                 {'name': 'ParametricGeometry', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_PARAMETRICGEOMETRY', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialPoint() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  coord1 = dict({'type': 'double', 'reqd' : True, 'name':'coord1'})
  coord2 = dict({'type': 'double', 'reqd' : False, 'name':'coord2'})
  coord3 = dict({'type': 'double', 'reqd' : False, 'name':'coord3'})
  domain = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domain'})
  attributes = [id, coord1, coord2, coord3, domain]
  element = dict(
                 {'name': 'SpatialPoint', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_SPATIALPOINT', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialParametricObject() :
  id = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  polygonType = dict({'type': 'string', 'reqd' : True, 'name':'polygonType'})
  domain = dict({'type': 'SIdRef', 'reqd' : True, 'name':'domain'})
  child1 = dict({'type': 'PolygonObject', 'reqd': True, 'name': 'polygonObject', 'element': 'PolygonObject'})
  attributes = [id, polygonType, domain, child1]
  element = dict(
                 {'name': 'ParametricObject', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_PARAMETRICOBJECT', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

def createSpatialPolygonObject() :
  pointIndex = dict({'type': 'int*', 'reqd' : True, 'name':'pointIndex'})
  attributes = [pointIndex]
  element = dict(
                 {'name': 'PolygonObject', 
                  'package': 'Spatial', 
                  'typecode': 'SBML_SPATIAL_POLYGONOBJECT', 
                  'hasListOf': False, 
                  'attribs':attributes, 
                  'hasChildren':False, 
                  'hasMath':False
                  }) 
  return element

#end of spatial

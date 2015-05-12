#!/usr/bin/env python
#
# @file   createNewPackage.py
# @brief  Create package object to pass to functions
# @author Sarah Keating
#

import sys
import createNewElementDictObj
import createPackageFromXml



#note arrays is not finished - NEED To create the objects
def createArrays():
  # for each sbml class create the sbml obj and the overall description object
  #dimension
  sbml_dim = createNewElementDictObj.createArraysDim()
  dim = dict({'name': sbml_dim['name'], 'typecode': sbml_dim['typecode'], 'isListOf': True})
  #index
  sbml_index = createNewElementDictObj.createArraysIndex()
  dim = dict({'name': sbml_index['name'], 'typecode': sbml_index['typecode'], 'isListOf': True})
  index = dict({'name': 'Dimension', 'typecode': 'SBML_ARRAYS_DIMENSION', 'isListOf': True})
  # create a list of the sbml classes
  sbml_classes = [sbml_dim, sbml_index]
  # create a list of the types
  elem = [dim, index]
  # define information about plugins
  sb_elem = [dim, index]
  sb_plug = dict({'sbase': 'SBase', 'extension': sb_elem})  
  plug = [sb_plug]
  #create the overall package description
  package = dict({'name' : 'Arrays', 'elements': elem, 'plugins': plug, 'number': 1200, 'sbmlElements': sbml_classes, 'offset': 8000000})
  return package


# fbc - not fully working as I did not specifically use this for fbc
def createFbc():
  # for each sbml class create the sbml obj and the overall description object
  #FluxBound
  sbml_bound = createNewElementDictObj.createFBCObj()
  bound = dict({'name': sbml_bound['name'], 'typecode': sbml_bound['typecode'], 'isListOf': True})
  #Objective
  sbml_obj = createNewElementDictObj.createFBCObjective()
  obj = dict({'name': sbml_obj['name'], 'typecode': sbml_obj['typecode'], 'isListOf': True})
  #FluxObjective
  sbml_flux_obj = createNewElementDictObj.createFBCFluxObjective()
  flux_obj = dict({'name': sbml_flux_obj['name'], 'typecode': sbml_flux_obj['typecode'], 'isListOf': True})
  # create a list of the sbml classes
  sbml_classes = [sbml_bound, sbml_obj, sbml_flux_obj]
  # create a list of the types
  elem = [bound, obj, flux_obj]
  # define information about plugins
  model_elem = [bound, obj]
  model_plug = dict({'sbase': 'Model', 'extension': model_elem}) 
  species_plug = dict({'sbase': 'Species', 'extension': []})  
  plug = [model_plug, species_plug]
  #create the overall package description
  package = dict({'name' : 'Fbc', 'elements': elem, 'plugins': plug, 'number': 800, 'sbmlElements': sbml_classes, 'offset': 2000000})
  return package
    
  
#distrib - in line with v0.12
def createDistrib():
  # for each sbml class create the sbml obj and the overall description object
  #Draw
  sbml_draw = createNewElementDictObj.createDistribDraw()
  draw = dict({'name': sbml_draw['name'], 'typecode': sbml_draw['typecode'], 'isListOf': False})
  #Input
  sbml_in = createNewElementDictObj.createDistribInput()
  input = dict({'name': sbml_in['name'], 'typecode': sbml_in['typecode'], 'isListOf': True})
  #Uncert
  sbml_pdf = createNewElementDictObj.createDistribUncertainty()
  pdf = dict({'name': sbml_pdf['name'], 'typecode': sbml_pdf['typecode'], 'isListOf': False})
  # create a list of the sbml classes
  sbml_classes = [sbml_draw, sbml_in, sbml_pdf]
  # create a list of the types
  elem = [draw, input, pdf]
  # define information about plugins
  fd_elem = [draw]
  fd_plug = dict({'sbase': 'FunctionDefinition', 'extension': fd_elem})
  sb_elem = [pdf]
  sb_plug = dict({'sbase': 'SBase', 'extension': sb_elem})  
  plug = [fd_plug, sb_plug]
  #create the overall package description
  package = dict({'name' : 'Distrib', 'elements': elem, 'plugins': plug, 'number': 1300, 'sbmlElements': sbml_classes, 'offset': 5000000})
  return package
  
  
def createGroups():
  # for each sbml class create the sbml obj and the overall description object
  #Member
  sbml_mem = createNewElementDictObj.createGroupsMember()
  mem = dict({'name': sbml_mem['name'], 'typecode': sbml_mem['typecode'], 'isListOf': True})
  #MemberConstrainst
  sbml_mc = createNewElementDictObj.createGroupsMemberConstraint()
  mc = dict({'name': sbml_mc['name'], 'typecode': sbml_mc['typecode'], 'isListOf': True})
  #Group
  sbml_gp = createNewElementDictObj.createGroupsGroup()
  gp = dict({'name': sbml_gp['name'], 'typecode': sbml_gp['typecode'], 'isListOf': True})
  # create a list of the sbml classes
  sbml_classes = [sbml_mem, sbml_mc, sbml_gp]
  # create a list of the types
  elem = [mem, mc, gp]
  # define information about plugins
  model_elem = [gp]
  model_plug = dict({'sbase': 'Model', 'extension': model_elem}) 
  plug = [model_plug]
  #create the overall package description
  package = dict({'name' : 'Groups', 'elements': elem, 'plugins': plug, 'number': 200, 'sbmlElements': sbml_classes, 'offset': 4000000})
  return package

  
def createLayout():
  # for each sbml class create the sbml obj and the overall description object
  #BoundingBox
  sbml_bb = createNewElementDictObj.createLayoutBB()
  bb = dict({'name': sbml_bb['name'], 'typecode': sbml_bb['typecode'], 'isListOf': False})
  #CompartmentGlyph
  sbml_cg = createNewElementDictObj.createLayoutCompGlyph()
  cg = dict({'name': sbml_cg['name'], 'typecode': sbml_cg['typecode'], 'isListOf': True})
  #CubicBezier
  sbml_cbez = createNewElementDictObj.createLayoutCubicBez()
  cbez = dict({'name': sbml_cbez['name'], 'typecode': sbml_cbez['typecode'], 'isListOf': False})
  #Curve
  sbml_cur = createNewElementDictObj.createLayoutCurve()
  cur = dict({'name': sbml_cur['name'], 'typecode': sbml_cur['typecode'], 'isListOf': False})
  #Dimensions
  sbml_dim = createNewElementDictObj.createLayoutDimensions()
  dim = dict({'name': sbml_dim['name'], 'typecode': sbml_dim['typecode'], 'isListOf': False})
  #GraphicalObject
  sbml_go = createNewElementDictObj.createLayoutGraphObj()
  go = dict({'name': sbml_go['name'], 'typecode': sbml_go['typecode'], 'isListOf': False})
  #Layout
  sbml_lay = createNewElementDictObj.createLayoutLayout()
  lay = dict({'name': sbml_lay['name'], 'typecode': sbml_lay['typecode'], 'isListOf': True})
  #LineSegment
  sbml_ls = createNewElementDictObj.createLayoutLineSeg()
  ls = dict({'name': sbml_ls['name'], 'typecode': sbml_ls['typecode'], 'isListOf': True})
  #Point
  sbml_pt = createNewElementDictObj.createLayoutPoint()
  pt = dict({'name': sbml_pt['name'], 'typecode': sbml_pt['typecode'], 'isListOf': False})
  #ReactionGlyph
  sbml_rg = createNewElementDictObj.createLayoutReactionGlyph()
  rg = dict({'name': sbml_rg['name'], 'typecode': sbml_rg['typecode'], 'isListOf': True})
  #SpeciesGlyph
  sbml_sg = createNewElementDictObj.createLayoutSpeciesGlyph()
  sg = dict({'name': sbml_sg['name'], 'typecode': sbml_sg['typecode'], 'isListOf': True})
  #SpeciesReferenceGlyph
  sbml_srg = createNewElementDictObj.createLayoutSpeciesRefGlyph()
  srg = dict({'name': sbml_srg['name'], 'typecode': sbml_srg['typecode'], 'isListOf': True})
  #TextGlyph
  sbml_tg = createNewElementDictObj.createLayoutTextGlyph()
  tg = dict({'name': sbml_tg['name'], 'typecode': sbml_tg['typecode'], 'isListOf': True})
  #ReferenceGlyph
  sbml_refg = createNewElementDictObj.createLayoutRefGlyph()
  refg = dict({'name': sbml_refg['name'], 'typecode': sbml_refg['typecode'], 'isListOf': True})
  #GeneralGlyph
  sbml_gg = createNewElementDictObj.createLayoutGeneralGlyph()
  gg = dict({'name': sbml_gg['name'], 'typecode': sbml_gg['typecode'], 'isListOf': True})
  # create a list of the sbml classes
  sbml_classes = [sbml_bb, sbml_cg, sbml_cbez, sbml_cur, sbml_dim, sbml_go, sbml_lay, sbml_ls, sbml_pt, sbml_rg, sbml_sg, sbml_srg, sbml_tg, sbml_refg, sbml_gg]
  # create a list of the types
  elem = [bb, cg, cbez, cur, dim, go, lay, ls, pt, rg, sg, srg, tg, refg, gg]
  # define information about plugins
  model_elem = [lay]
  model_plug = dict({'sbase': 'Model', 'extension': model_elem}) 
  plug = [model_plug]
  #create the overall package description
  package = dict({'name' : 'Layout', 'elements': elem, 'plugins': plug, 'number': 100, 'sbmlElements': sbml_classes, 'offset': 6000000})
  return package
 
def createMulti():
  sbml_classes = []
  elements = []
  model_elem = []
  compartment_elem = []
  species_elem = []
  reaction_elem = []
  simpleSR_elem = []
  sR_elem = []
  sbml_class = createNewElementDictObj.createPossibleSpeciesFeatureValue()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sbml_class = createNewElementDictObj.createSpeciesFeatureValue()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sbml_class = createNewElementDictObj.createCompartmentReference()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  compartment_elem.append(sbml)
  sbml_class = createNewElementDictObj.createSpeciesTypeInstance()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sbml_class = createNewElementDictObj.createInSpeciesTypeBond()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sbml_class = createNewElementDictObj.createDenotedSpeciesTypeComponentIndex()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sbml_class = createNewElementDictObj.createOutwardBindingSite()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  species_elem.append(sbml)
  sbml_class = createNewElementDictObj.createSpeciesFeatureChange()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sbml_class = createNewElementDictObj.createSpeciesFeatureType()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sbml_class = createNewElementDictObj.createSpeciesTypeComponentIndex()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sbml_class = createNewElementDictObj.createSpeciesFeature()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  species_elem.append(sbml)
  sbml_class = createNewElementDictObj.createSpeciesTypeComponentMapInProduct()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  sR_elem.append(sbml)
  sbml_class = createNewElementDictObj.createMultiSpeciesType()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)  
  model_elem.append(sbml)
  #hacks for plugin attributes
  sbml_class = createNewElementDictObj.createCompartmentPlugin()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)  
  sbml_class = createNewElementDictObj.createSpeciesPlugin()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)  
  sbml_class = createNewElementDictObj.createReactionPlugin()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)  
  sbml_class = createNewElementDictObj.createSimplePlugin()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)    
  plug = []
  plugin = dict({'sbase': 'Model', 'extension': model_elem}) 
  plug.append(plugin)
  plugin = dict({'sbase': 'Compartment', 'extension': compartment_elem}) 
  plug.append(plugin)
  plugin = dict({'sbase': 'Species', 'extension': species_elem}) 
  plug.append(plugin)
  plugin = dict({'sbase': 'Reaction', 'extension': reaction_elem}) 
  plug.append(plugin)
  plugin = dict({'sbase': 'SimpleSpeciesReference', 'extension': simpleSR_elem}) 
  plug.append(plugin)
  plugin = dict({'sbase': 'SpeciesReference', 'extension': sR_elem}) 
  plug.append(plugin)
  package = dict({'name' : 'Multi', 'elements': elements, 'plugins': plug, 'number': 1400, 'sbmlElements': sbml_classes, 'offset': 7000000})
  return package 

def createQual():
  sbml_classes = []
  elements = []
  model_elem = []
  # for each sbml class create the sbml obj and the overall description object
  #QualitativeSpecies
  sbml_class = createNewElementDictObj.createQualSpecies()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  model_elem.append(sbml)
  #Transition
  sbml_class = createNewElementDictObj.createQualTransition()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  model_elem.append(sbml)
  #Input
  sbml_class = createNewElementDictObj.createQualInput()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  #Output
  sbml_class = createNewElementDictObj.createQualOutput()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  #FunctionTerm
  sbml_class = createNewElementDictObj.createQualFunctionTerm()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': False})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  #DefaultTerm
  sbml_class = createNewElementDictObj.createQualDefaultTerm()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': False})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
  model_plug = dict({'sbase': 'Model', 'extension': model_elem}) 
  plug = [model_plug]
  #create teh overall package description
  package = dict({'name' : 'Qual', 'elements': elements, 'plugins': plug, 'number': 1100, 'sbmlElements': sbml_classes, 'offset': 3000000})
  return package
  
def createRender():
  sbml_classes = []
  elements = []
  model_elem = []
  # for each sbml class create the sbml obj and the overall description object
  #ColorDefinitiom
  sbml_class = createNewElementDictObj.createRenderColorDefinition()
  sbml = dict({'name': sbml_class['name'], 'typecode': sbml_class['typecode'], 'isListOf': True})
  sbml_classes.append(sbml_class)
  elements.append(sbml)
#  model_elem.append(sbml)
#  model_plug = dict({'sbase': 'Model', 'extension': model_elem}) 
  plug = []
  #create teh overall package description
  package = dict({'name' : 'Render', 'elements': elements, 'plugins': plug, 'number': 1500, 'sbmlElements': sbml_classes, 'offset': 9000000})
  return package

#req - in line with v0.5
def createReq():
  # for each sbml class create the sbml obj and the overall description object
  #changedMath
  sbml_draw = createNewElementDictObj.createReqChangedMath()
  draw = dict({'name': sbml_draw['name'], 'typecode': sbml_draw['typecode'], 'isListOf': True})
  # create a list of the sbml classes
  sbml_classes = [sbml_draw]
  # create a list of the types
  elem = [draw]
  # define information about plugins
  sb_elem = [draw]
  sb_plug = dict({'sbase': 'SBase', 'extension': sb_elem})
  plug = [sb_plug]
  #create the overall package description
  package = dict({'name' : 'Req', 'elements': elem, 'plugins': plug, 'number': 1600, 'sbmlElements': sbml_classes, 'offset': 1100000})
  return package

def createSpatial():
  # for each sbml class create the sbml obj and the overall description object
  #CompartmentMapping
  sbml_cm = createNewElementDictObj.createSpatialCompartmentMapping()
  cm = dict({'name': sbml_cm['name'], 'typecode': sbml_cm['typecode'], 'isListOf': False})
  #CoordinateIndex
  sbml_ci = createNewElementDictObj.createSpatialCoordinateIndex()
  ci = dict({'name': sbml_ci['name'], 'typecode': sbml_ci['typecode'], 'isListOf': False})
  #SpatialSymbolReference
  sbml_ssr = createNewElementDictObj.createSpatialSymbolReference()
  ssr = dict({'name': sbml_ssr['name'], 'typecode': sbml_ssr['typecode'], 'isListOf': False})
  #DiffusionCoefficient
  sbml_dc = createNewElementDictObj.createSpatialDiffusionCoefficient()
  dc = dict({'name': sbml_dc['name'], 'typecode': sbml_dc['typecode'], 'isListOf': False})
  #AdvectionCoefficient
  sbml_ac = createNewElementDictObj.createSpatialAdvectionCoefficient()
  ac = dict({'name': sbml_ac['name'], 'typecode': sbml_ac['typecode'], 'isListOf': False})
  #BoundaryCondition
  sbml_bc = createNewElementDictObj.createSpatialBoundaryCondition()
  bc = dict({'name': sbml_bc['name'], 'typecode': sbml_bc['typecode'], 'isListOf': False})
  #Geometry
  sbml_g = createNewElementDictObj.createSpatialGeometry()
  g = dict({'name': sbml_g['name'], 'typecode': sbml_g['typecode'], 'isListOf': False})
  #CoordinateComponent
  sbml_cc = createNewElementDictObj.createSpatialCoordinateComponent()
  cc = dict({'name': sbml_cc['name'], 'typecode': sbml_cc['typecode'], 'isListOf': True})
  #Boundary
  sbml_b = createNewElementDictObj.createSpatialBoundary()
  b = dict({'name': sbml_b['name'], 'typecode': sbml_b['typecode'], 'isListOf': False})
  #DomainType
  sbml_dt = createNewElementDictObj.createSpatialDomainType()
  dt = dict({'name': sbml_dt['name'], 'typecode': sbml_dt['typecode'], 'isListOf': True})
  #Domain
  sbml_d = createNewElementDictObj.createSpatialDomain()
  d = dict({'name': sbml_d['name'], 'typecode': sbml_d['typecode'], 'isListOf': True})
  #InteriorPoint
  sbml_ip = createNewElementDictObj.createSpatialInteriorPoint()
  ip = dict({'name': sbml_ip['name'], 'typecode': sbml_ip['typecode'], 'isListOf': True})
  #AdjacentDomain
  sbml_ad = createNewElementDictObj.createSpatialAdjacentDomain()
  ad = dict({'name': sbml_ad['name'], 'typecode': sbml_ad['typecode'], 'isListOf': True})
  #GeometryDefinition
  sbml_gd = createNewElementDictObj.createSpatialGeometryDefinition()
  gd = dict({'name': sbml_gd['name'], 'typecode': sbml_gd['typecode'], 'isListOf': True})
  #AnalyticGeometry
  sbml_ag = createNewElementDictObj.createSpatialAnalyticGeometry()
  ag = dict({'name': sbml_ag['name'], 'typecode': sbml_ag['typecode'], 'isListOf': False})
  #AnalyticVolume
  sbml_av = createNewElementDictObj.createSpatialAnalyticVolume()
  av = dict({'name': sbml_av['name'], 'typecode': sbml_av['typecode'], 'isListOf': True})
  #SampledFieldGeometry
  sbml_sfg = createNewElementDictObj.createSpatialSampledFieldGeometry()
  sfg = dict({'name': sbml_sfg['name'], 'typecode': sbml_sfg['typecode'], 'isListOf': False})
  #SampledVolume
  sbml_sv = createNewElementDictObj.createSpatialSampledVolume()
  sv = dict({'name': sbml_sv['name'], 'typecode': sbml_sv['typecode'], 'isListOf': True})
  #SampledField
  sbml_sf = createNewElementDictObj.createSpatialSampledField()
  sf = dict({'name': sbml_sf['name'], 'typecode': sbml_sf['typecode'], 'isListOf': False})
  #ImageData
  sbml_id = createNewElementDictObj.createSpatialImageData()
  id = dict({'name': sbml_id['name'], 'typecode': sbml_id['typecode'], 'isListOf': False})
  #CSGeometry
  sbml_csg = createNewElementDictObj.createSpatialCSGeometry()
  csg = dict({'name': sbml_csg['name'], 'typecode': sbml_csg['typecode'], 'isListOf': False})
  #CSGObject
  sbml_csgo = createNewElementDictObj.createSpatialCSGObject()
  csgo = dict({'name': sbml_csgo['name'], 'typecode': sbml_csgo['typecode'], 'isListOf': True})
  #CSGNode
  sbml_csgn = createNewElementDictObj.createSpatialCSGNode()
  csgn = dict({'name': sbml_csgn['name'], 'typecode': sbml_csgn['typecode'], 'isListOf': True})
  #CSGPrimitive
  sbml_csgp = createNewElementDictObj.createSpatialCSGPrimitive()
  csgp = dict({'name': sbml_csgp['name'], 'typecode': sbml_csgp['typecode'], 'isListOf': False})
  #CSGPseudoPrimitive
  sbml_csgpp = createNewElementDictObj.createSpatialCSGPseudoPrimitive()
  csgpp = dict({'name': sbml_csgpp['name'], 'typecode': sbml_csgpp['typecode'], 'isListOf': False})
  #CSGSetOperator
  sbml_csgso = createNewElementDictObj.createSpatialCSGSetOperator()
  csgso = dict({'name': sbml_csgso ['name'], 'typecode': sbml_csgso ['typecode'], 'isListOf': False})
  #CSGTransformation
  sbml_csgt = createNewElementDictObj.createSpatialCSGTransformation()
  csgt = dict({'name': sbml_csgt['name'], 'typecode': sbml_csgt['typecode'], 'isListOf': False})
  #CSGTranslation
  sbml_csgtr = createNewElementDictObj.createSpatialCSGTranslation()
  csgtr = dict({'name': sbml_csgtr['name'], 'typecode': sbml_csgtr['typecode'], 'isListOf': False})
  #CSGRotation
  sbml_csgr = createNewElementDictObj.createSpatialCSGRotation()
  csgr = dict({'name': sbml_csgr['name'], 'typecode': sbml_csgr['typecode'], 'isListOf': False})
  #CSGScale
  sbml_csgs = createNewElementDictObj.createSpatialCSGScale()
  csgs = dict({'name': sbml_csgs['name'], 'typecode': sbml_csgs['typecode'], 'isListOf': False})
  #CSGHomogeneousTransformation
  sbml_csgh = createNewElementDictObj.createSpatialCSGHomogeneousTransformation()
  csgh = dict({'name': sbml_csgh['name'], 'typecode': sbml_csgh['typecode'], 'isListOf': False})
  #TransformationComponent
  sbml_tc = createNewElementDictObj.createSpatialTransformationComponent()
  tc = dict({'name': sbml_tc['name'], 'typecode': sbml_tc['typecode'], 'isListOf': False})
  #ParametricGeometry
  sbml_pg = createNewElementDictObj.createSpatialParametricGeometry()
  pg = dict({'name': sbml_pg['name'], 'typecode': sbml_pg['typecode'], 'isListOf': False})
  #SpatialPoint
  sbml_sp = createNewElementDictObj.createSpatialPoint()
  sp = dict({'name': sbml_sp['name'], 'typecode': sbml_sp['typecode'], 'isListOf': True})
  #ParametricObject
  sbml_po = createNewElementDictObj.createSpatialParametricObject()
  po = dict({'name': sbml_po['name'], 'typecode': sbml_po['typecode'], 'isListOf': True})
  #PolygonObject
  sbml_pob = createNewElementDictObj.createSpatialPolygonObject()
  pob = dict({'name': sbml_pob['name'], 'typecode': sbml_pob['typecode'], 'isListOf': False})

  # create a list of the sbml classes
  sbml_classes = [sbml_cm, sbml_ci, sbml_ssr, sbml_dc, sbml_ac, sbml_bc, sbml_g, sbml_cc, sbml_b, sbml_dt, sbml_d, sbml_ip, sbml_ad, sbml_gd, sbml_ag, sbml_av, sbml_sfg, sbml_sv, sbml_sf, sbml_id, sbml_csg, sbml_csgo, sbml_csgn, sbml_csgp, sbml_csgpp,sbml_csgso,sbml_csgt,sbml_csgr, sbml_csgs, sbml_csgh, sbml_tc,sbml_pg, sbml_sp, sbml_po, sbml_pob]
  # create a list of the types
  elem = [cm, ci, ssr, dc, ac, bc, g, cc, b, dt, d, ip, ad, gd, ag, av, sfg, sv, sf, id, csg, csgo, csgn, csgp, csgpp,csgso,csgt,csgr, csgs, csgh, tc,pg, sp, po, pob]
  
  # define information about plugins
  model_elem = [g]
  model_plug = dict({'sbase': 'Model', 'extension': model_elem}) 
  comp_elem = [cm]
  comp_plug = dict({'sbase': 'Compartment', 'extension': comp_elem}) 
  param_elem = [ssr, dc, ac, bc]
  param_plug = dict({'sbase': 'Parameter', 'extension': param_elem}) 
  species_elem = [dict({'name': 'isSpatial', 'typecode': 'boolean', 'isListOf': False})]
  species_plug = dict({'sbase': 'Species', 'extension': species_elem}) 
  reaction_plug = dict({'sbase': 'Reaction', 'extension': []}) 
  plug = [model_plug, comp_plug, species_plug, reaction_plug ]
  
  #create the overall package description
  package = dict({'name' : 'Spatial', 'elements': elem, 'plugins': plug, 'number': 300, 'sbmlElements': sbml_classes, 'offset': 1200000})
  return package

def createPackage(name):
  if (name == 'qual'):
    package = createQual()
  elif (name == 'distrib'):
    package = createDistrib()
  elif (name == 'groups'):
    package = createGroups()
  elif (name == 'layout'):
    package = createLayout()
  elif (name == 'fbc'):
    package = createFbc()
  elif (name == 'multi'):
    package = createMulti()
  elif (name == "arrays"):
    package = createArrays()
  elif (name == "render"):
    package = createRender()
  elif (name == "req"):
    package = createReq()
  elif (name == "spatial"):
    package = createSpatial()
  else:
    package = None
  return package
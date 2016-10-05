/**
 * @file VersSpeciesPlugin.h
 * @brief Definition of the VersSpeciesPlugin class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class VersSpeciesPlugin
 * @sbmlbrief{vers} Extension of Species.
 */


#ifndef VersSpeciesPlugin_H__
#define VersSpeciesPlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBasePlugin.h>
#include <sbml/packages/vers/sbml/ClassOne.h>
#include <sbml/packages/vers/sbml/ClassTwo.h>
#include <sbml/packages/vers/sbml/ListOfAnothers.h>
#include <sbml/packages/vers/sbml/Another.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN VersSpeciesPlugin : public SBasePlugin
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mSpecies_att_v1;
  std::string mString_plugin_att;
  std::string mSpecies_att_v2;
  ClassOne* mClassOne;
  ClassTwo* mClassTwo;
  ListOfAnothers mAnothers;

  /** @endcond */

public:

  /**
   * Creates a new VersSpeciesPlugin using the given uri, prefix and package
   * namespace.
   *
   * @param uri a string, representing the uri of the package.
   *
   * @param prefix a string, the prefix to be used.
   *
   * @param versns a pointer to the VersPkgNamespaces object to be used.
   */
  VersSpeciesPlugin(const std::string& uri,
                    const std::string& prefix,
                    VersPkgNamespaces* versns);


  /**
   * Copy constructor for VersSpeciesPlugin.
   *
   * @param orig the VersSpeciesPlugin instance to copy.
   */
  VersSpeciesPlugin(const VersSpeciesPlugin& orig);


  /**
   * Assignment operator for VersSpeciesPlugin.
   *
   * @param rhs the VersSpeciesPlugin object whose values are to be used as the
   * basis of the assignment.
   */
  VersSpeciesPlugin& operator=(const VersSpeciesPlugin& rhs);


  /**
   * Creates and returns a deep copy of this VersSpeciesPlugin object.
   *
   * @return a (deep) copy of this VersSpeciesPlugin object.
   */
  virtual VersSpeciesPlugin* clone() const;


  /**
   * Destructor for VersSpeciesPlugin.
   */
  virtual ~VersSpeciesPlugin();


  /**
   * Returns the value of the "species_att_v1" attribute of this
   * VersSpeciesPlugin.
   *
   * @return the value of the "species_att_v1" attribute of this
   * VersSpeciesPlugin as a string.
   */
  const std::string& getSpecies_att_v1() const;


  /**
   * Returns the value of the "string_plugin_att" attribute of this
   * VersSpeciesPlugin.
   *
   * @return the value of the "string_plugin_att" attribute of this
   * VersSpeciesPlugin as a string.
   */
  const std::string& getString_plugin_att() const;


  /**
   * Returns the value of the "species_att_v2" attribute of this
   * VersSpeciesPlugin.
   *
   * @return the value of the "species_att_v2" attribute of this
   * VersSpeciesPlugin as a string.
   */
  const std::string& getSpecies_att_v2() const;


  /**
   * Predicate returning @c true if this VersSpeciesPlugin's "species_att_v1"
   * attribute is set.
   *
   * @return @c true if this VersSpeciesPlugin's "species_att_v1" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetSpecies_att_v1() const;


  /**
   * Predicate returning @c true if this VersSpeciesPlugin's
   * "string_plugin_att" attribute is set.
   *
   * @return @c true if this VersSpeciesPlugin's "string_plugin_att" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetString_plugin_att() const;


  /**
   * Predicate returning @c true if this VersSpeciesPlugin's "species_att_v2"
   * attribute is set.
   *
   * @return @c true if this VersSpeciesPlugin's "species_att_v2" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetSpecies_att_v2() const;


  /**
   * Sets the value of the "species_att_v1" attribute of this
   * VersSpeciesPlugin.
   *
   * @param species_att_v1 std::string& value of the "species_att_v1" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setSpecies_att_v1(const std::string& species_att_v1);


  /**
   * Sets the value of the "string_plugin_att" attribute of this
   * VersSpeciesPlugin.
   *
   * @param string_plugin_att std::string& value of the "string_plugin_att"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setString_plugin_att(const std::string& string_plugin_att);


  /**
   * Sets the value of the "species_att_v2" attribute of this
   * VersSpeciesPlugin.
   *
   * @param species_att_v2 std::string& value of the "species_att_v2" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setSpecies_att_v2(const std::string& species_att_v2);


  /**
   * Unsets the value of the "species_att_v1" attribute of this
   * VersSpeciesPlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSpecies_att_v1();


  /**
   * Unsets the value of the "string_plugin_att" attribute of this
   * VersSpeciesPlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetString_plugin_att();


  /**
   * Unsets the value of the "species_att_v2" attribute of this
   * VersSpeciesPlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSpecies_att_v2();


  /**
   * Returns the value of the "classOne" element of this VersSpeciesPlugin.
   *
   * @return the value of the "classOne" element of this VersSpeciesPlugin as a
   * ClassOne*.
   */
  const ClassOne* getClassOne() const;


  /**
   * Returns the value of the "classOne" element of this VersSpeciesPlugin.
   *
   * @return the value of the "classOne" element of this VersSpeciesPlugin as a
   * ClassOne*.
   */
  ClassOne* getClassOne();


  /**
   * Returns the value of the "classTwo" element of this VersSpeciesPlugin.
   *
   * @return the value of the "classTwo" element of this VersSpeciesPlugin as a
   * ClassTwo*.
   */
  const ClassTwo* getClassTwo() const;


  /**
   * Returns the value of the "classTwo" element of this VersSpeciesPlugin.
   *
   * @return the value of the "classTwo" element of this VersSpeciesPlugin as a
   * ClassTwo*.
   */
  ClassTwo* getClassTwo();


  /**
   * Predicate returning @c true if this VersSpeciesPlugin's "classOne" element
   * is set.
   *
   * @return @c true if this VersSpeciesPlugin's "classOne" element has been
   * set, otherwise @c false is returned.
   */
  bool isSetClassOne() const;


  /**
   * Predicate returning @c true if this VersSpeciesPlugin's "classTwo" element
   * is set.
   *
   * @return @c true if this VersSpeciesPlugin's "classTwo" element has been
   * set, otherwise @c false is returned.
   */
  bool isSetClassTwo() const;


  /**
   * Sets the value of the "classOne" element of this VersSpeciesPlugin.
   *
   * @param classOne ClassOne* value of the "classOne" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setClassOne(const ClassOne* classOne);


  /**
   * Sets the value of the "classTwo" element of this VersSpeciesPlugin.
   *
   * @param classTwo ClassTwo* value of the "classTwo" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setClassTwo(const ClassTwo* classTwo);


  /**
   * Creates a new ClassOne object, adds it to this VersSpeciesPlugin object
   * and returns the ClassOne object created.
   *
   * @return a new ClassOne object instance.
   */
  ClassOne* createClassOne();


  /**
   * Creates a new ClassTwo object, adds it to this VersSpeciesPlugin object
   * and returns the ClassTwo object created.
   *
   * @return a new ClassTwo object instance.
   */
  ClassTwo* createClassTwo();


  /**
   * Unsets the value of the "classOne" element of this VersSpeciesPlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetClassOne();


  /**
   * Unsets the value of the "classTwo" element of this VersSpeciesPlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetClassTwo();


  /**
   * Returns the ListOfAnothers from this VersSpeciesPlugin.
   *
   * @return the ListOfAnothers from this VersSpeciesPlugin.
   */
  const ListOfAnothers* getListOfAnothers() const;


  /**
   * Returns the ListOfAnothers from this VersSpeciesPlugin.
   *
   * @return the ListOfAnothers from this VersSpeciesPlugin.
   */
  ListOfAnothers* getListOfAnothers();


  /**
   * Get an Another from the VersSpeciesPlugin.
   *
   * @param n an unsigned int representing the index of the Another to
   * retrieve.
   *
   * @return the nth Another in the ListOfAnothers within this
   * VersSpeciesPlugin.
   *
   * @see getNumAnothers()
   */
  Another* getAnother(unsigned int n);


  /**
   * Get an Another from the VersSpeciesPlugin.
   *
   * @param n an unsigned int representing the index of the Another to
   * retrieve.
   *
   * @return the nth Another in the ListOfAnothers within this
   * VersSpeciesPlugin.
   *
   * @see getNumAnothers()
   */
  const Another* getAnother(unsigned int n) const;


  /**
   * Get an Another from the VersSpeciesPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the Another to
   * retrieve.
   *
   * @return the Another in the ListOfAnothers within this VersSpeciesPlugin
   * with the given id or NULL if no such Another exists.
   *
   * @see getAnother(unsigned int n)
   * @see getNumAnothers()
   */
  Another* getAnother(const std::string& sid);


  /**
   * Get an Another from the VersSpeciesPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the Another to
   * retrieve.
   *
   * @return the Another in the ListOfAnothers within this VersSpeciesPlugin
   * with the given id or NULL if no such Another exists.
   *
   * @see getAnother(unsigned int n)
   * @see getNumAnothers()
   */
  const Another* getAnother(const std::string& sid) const;


  /**
   * Adds a copy of the given Another to this VersSpeciesPlugin.
   *
   * @param a the Another object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createAnother()
   */
  int addAnother(const Another* a);


  /**
   * Get the number of Another objects in this VersSpeciesPlugin.
   *
   * @return the number of Another objects in this VersSpeciesPlugin.
   */
  unsigned int getNumAnothers() const;


  /**
   * Creates a new Another object, adds it to this VersSpeciesPlugin object and
   * returns the Another object created.
   *
   * @return a new Another object instance.
   *
   * @see addAnother(const Another* a)
   */
  Another* createAnother();


  /**
   * Removes the nth Another from this VersSpeciesPlugin and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the Another to remove.
   *
   * @return a pointer to the nth Another in this VersSpeciesPlugin.
   *
   * @see getNumAnothers
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Another* removeAnother(unsigned int n);


  /**
   * Removes the Another from this VersSpeciesPlugin based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the Another to remove.
   *
   * @return the Another in this VersSpeciesPlugin based on the identifier or
   * NULL if no such Another exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Another* removeAnother(const std::string& sid);


  /**
   * Predicate returning @c true if all the required attributes for this
   * VersSpeciesPlugin object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * VersSpeciesPlugin have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the VersSpeciesPlugin object are:
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * VersSpeciesPlugin object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * VersSpeciesPlugin have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the VersSpeciesPlugin object are:
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Connects to parent element
   */
  virtual void connectToParent(SBase* base);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this VersSpeciesPlugin's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this VersSpeciesPlugin's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this
   * VersSpeciesPlugin.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * filter, an ElementFilter that may impose restrictions on the objects to be
   * retrieved.
   *
   * @return a List* pointer of pointers to all SBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(ElementFilter * filter = NULL);



  /** @cond doxygenLibsbmlInternal */

  /**
   * Append items from model (used in comp flattening)
   *
   * @param model a pointer to a model object.
   *
   */
  int appendFrom(const Model* model);

  /** @endcond */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readV1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readV2Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeV1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeV2Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#endif /* !VersSpeciesPlugin_H__ */



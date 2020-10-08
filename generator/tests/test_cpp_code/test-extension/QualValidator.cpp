/**
 * @file QualValidator.cpp
 * @brief Definition of QualValidator.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
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
 */

#include <sbml/validator/VConstraint.h>

#include <sbml/packages/qual/common/QualExtensionTypes.h>
#include <sbml/packages/qual/validator/QualValidator.h>

/** @cond doxygenLibsbmlInternal */

using namespace std;

/** @endcond */



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


// -------------------------------------------
// Apply<T>
// -------------------------------------------
/**
 * Applies a Constraint<T> to an SBML object of type T.
 */

template <typename T>
struct Apply : public unary_function<TConstraint<T>*, void>
{
  Apply(const Model& m, const T& o)
    : model(m)
    , object(o)
  {
  }


  void
  operator()(TConstraint<T>* constraint)
  {
    constraint->check(model, object);
  }


  const Model& model;
  const T& object;
};


// -------------------------------------------
// ConstraintSet<T>
// -------------------------------------------
template <typename T>
class ConstraintSet
{
public:

  ConstraintSet() { }
  ~ConstraintSet() { }


  /*
   * Adds a Constraint to this ConstraintSet
   */
  void
  add(TConstraint<T>* c)
  {
    constraints.push_back(c);
  }


  /*
   * Applies all Constraints in this ConstraintSet to the given SBML object of
   * type T. Constraint violations are logged to Validator.
   */
  void
  applyTo(const Model& model, const T& object)
  {
    for_each(constraints.begin(), constraints.end(), Apply<T>(model, object));
  }


  /*
   * Returns true if the ConstraintSet is empty, false otherwise
   */
  bool
  empty() const
  {
    return constraints.empty();
  }


protected:

  std::list< TConstraint<T>* > constraints;
};


// -------------------------------------------
// ValidatorConstraints
// -------------------------------------------
struct QualValidatorConstraints
{

  ConstraintSet<SBMLDocument>                   mSBMLDocument;
  ConstraintSet<Model>                          mModel;
  ConstraintSet<QualitativeSpecies>             mQualitativeSpecies;
  ConstraintSet<Transition>                     mTransition;
  ConstraintSet<Input>                          mInput;
  ConstraintSet<Output>                         mOutput;
  ConstraintSet<DefaultTerm>                    mDefaultTerm;
  ConstraintSet<FunctionTerm>                   mFunctionTerm;

  map<VConstraint*, bool> ptrMap;

  ~QualValidatorConstraints();

  void add(VConstraint* c);

};


/*
 * Destroys this QualValidatorConstraints object.
 */
QualValidatorConstraints::~QualValidatorConstraints()
{
  map<VConstraint*, bool>::iterator it = ptrMap.begin();

  while (it != ptrMap.end())
  {
    if (it->second)
    {
      delete it->first;
    }

    ++it;
  }
}


/*
 * Adds the given Constraint to the appropriate ConstraintSet
 */
void
QualValidatorConstraints::add(VConstraint* c)
{
  if (c == NULL) return;

  ptrMap.insert(pair<VConstraint*, bool>(c, true));

  if (dynamic_cast< TConstraint<SBMLDocument>* >(c) != NULL)
  {
    mSBMLDocument.add(static_cast< TConstraint<SBMLDocument>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Model>* >(c) != NULL)
  {
    mModel.add(static_cast< TConstraint<Model>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<QualitativeSpecies>* >(c) != NULL)
  {
    mQualitativeSpecies.add(static_cast< TConstraint<QualitativeSpecies>* >(c)
      );
    return;
  }

  if (dynamic_cast< TConstraint<Transition>* >(c) != NULL)
  {
    mTransition.add(static_cast< TConstraint<Transition>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Input>* >(c) != NULL)
  {
    mInput.add(static_cast< TConstraint<Input>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Output>* >(c) != NULL)
  {
    mOutput.add(static_cast< TConstraint<Output>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<DefaultTerm>* >(c) != NULL)
  {
    mDefaultTerm.add(static_cast< TConstraint<DefaultTerm>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<FunctionTerm>* >(c) != NULL)
  {
    mFunctionTerm.add(static_cast< TConstraint<FunctionTerm>* >(c) );
    return;
  }
}


// -------------------------------------------
// ValidatingVisitor
// -------------------------------------------

class QualValidatingVisitor: public SBMLVisitor
{
public:

  QualValidatingVisitor(QualValidator& v, const Model& m)
    : v(v)
    , m(m)
  {
  }


  using SBMLVisitor::visit;

  bool
  visit(const QualitativeSpecies& x)
  {
    v.mQualConstraints->mQualitativeSpecies.applyTo(m, x);
    return !v.mQualConstraints->mQualitativeSpecies.empty();
  }


  bool
  visit(const Transition& x)
  {
    v.mQualConstraints->mTransition.applyTo(m, x);
    return !v.mQualConstraints->mTransition.empty();
  }


  bool
  visit(const Input& x)
  {
    v.mQualConstraints->mInput.applyTo(m, x);
    return !v.mQualConstraints->mInput.empty();
  }


  bool
  visit(const Output& x)
  {
    v.mQualConstraints->mOutput.applyTo(m, x);
    return !v.mQualConstraints->mOutput.empty();
  }


  bool
  visit(const DefaultTerm& x)
  {
    v.mQualConstraints->mDefaultTerm.applyTo(m, x);
    return !v.mQualConstraints->mDefaultTerm.empty();
  }


  bool
  visit(const FunctionTerm& x)
  {
    v.mQualConstraints->mFunctionTerm.applyTo(m, x);
    return !v.mQualConstraints->mFunctionTerm.empty();
  }


  virtual bool
  visit(const SBase& x)
  {
    if (x.getPackageName() != "qual")
    {
      return SBMLVisitor::visit(x);
    }

    int code = x.getTypeCode();

    const ListOf* list = dynamic_cast<const ListOf*>(&x);

    if (list != NULL)
    {
      return SBMLVisitor::visit(x);
    }
    else
    {
      if (code == SBML_QUAL_QUALITATIVE_SPECIES)
      {
        return visit((const QualitativeSpecies&)x);
      }
      else if (code == SBML_QUAL_TRANSITION)
      {
        return visit((const Transition&)x);
      }
      else if (code == SBML_QUAL_INPUT)
      {
        return visit((const Input&)x);
      }
      else if (code == SBML_QUAL_OUTPUT)
      {
        return visit((const Output&)x);
      }
      else if (code == SBML_QUAL_DEFAULT_TERM)
      {
        return visit((const DefaultTerm&)x);
      }
      else if (code == SBML_QUAL_FUNCTION_TERM)
      {
        return visit((const FunctionTerm&)x);
      }
      else
      {
        return SBMLVisitor::visit(x);
      }
    }
  }


protected:

  QualValidator& v;
  const Model& m;
};


// -------------------------------------------
// QualValidator
// -------------------------------------------

/*
 * Creates a new QualValidator object for the given category of validation.
 */
QualValidator::QualValidator(SBMLErrorCategory_t category)
  : Validator(category)
{
  mQualConstraints = new QualValidatorConstraints();
}


/*
 * Destroys this QualValidator object.
 */
QualValidator::~QualValidator()
{
  delete mQualConstraints;
}


/*
 * Adds the given VConstraint object to this QualValidator.
 */
void
QualValidator::addConstraint(VConstraint* c)
{
  mQualConstraints->add(c);
}


/*
 * Validates the given SBMLDocument
 */
unsigned int
QualValidator::validate(const SBMLDocument& d)
{
  const Model* m = d.getModel();

  if (m != NULL)
  {
    QualValidatingVisitor vv(*this, *m);
    const QualSBMLDocumentPlugin* plugin = static_cast<const
      QualSBMLDocumentPlugin*>(d.getPlugin("qual"));
    if (plugin != NULL)
    {
      plugin->accept(vv);
    }
  }

  // ADD ANY OTHER OBJECTS THAT HAS PLUGINS

  return (unsigned int)(mFailures.size());
}


/*
 * Validates the SBMLDocument located at the given filename
 */
unsigned int
QualValidator::validate(const std::string& filename)
{
  SBMLReader reader;
  SBMLDocument* d = reader.readSBML(filename);


  unsigned int numErrors = d->getNumErrors();


  for (unsigned int n=0; n < numErrors; ++n)
  {
    logFailure(*d->getError(n));
  }

  numErrors = validate(*d);
  delete d;
  return numErrors;
}




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END



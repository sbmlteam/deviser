
Background
===============

The Systems Biology Markup Language (SBML) provides a *lingua franca* for 
representing computational models in a machine readable format.  This facilitates
both the exchange of models between different software platforms and the re-use 
of these models for subsequent research.

SBML Level 3 and Packages
--------------------------

SBML Level 3 (L3) is being developed using a modular approach. A core specification
(SBML L3 Core) captures the basics of a model, with optional additional packages providing
extensions relevant to particular areas of modeling. There are several 
L3 packages at various stages of development encompassing such things as
flux balance modeling and models involving spatial components. An up to date
list of these packages can be found at the 
`sbml.org website <http://sbml.org/Documents/Specifications#SBML_Level_3_Packages>`_.


LibSBML
--------

LibSBML is a free open-source API library for working with SBML. Support for
L3 packages in libSBML is also provided in a modular fashion using 
`CMake <https://cmake.org/>`_ (a system for managing the build process) to allow users to configure and build
with options to enable/disable the various L3 packages.   A wide range of 
programming languages are supported by libSBML
which uses `SWIG <http://www.swig.org/>`_ (an interface compiler) 
to create the different interfaces necessary. Options to configure and build 
these interfaces are also available using the CMake system.

As a general note it is worth pointing out that a release of libSBML does 
include targeted installers for several 
languages and operating systems; although for users of Deviser these will not be 
relevant. Further information is available from 
the `libSBML page <http://sbml.org/Software/libSBML>`_.

A complete L3 package for libSBML includes
the C++ and C code, as well as all the necessary SWIG and CMake files to allow
the package to be integrated into an existing libSBML build and have all
the language interfaces available.


Development of L3 Packages
---------------------------

Each SBML L3 Package that has been proposed goes through a period of development
by a focussed group of people (known as the package working group or PWG) 
who are either interested and/or actively trying 
to use the additional functionality provided by the package.  This leads to a 
number of iterations of the package design as the PWG work towards a specification
that is agreed upon and meets the requirements of the parties involved.

Deviser has been developed to provide a fast, efficient means of changing both 
API code and specification documentation to facilitate the update of documentation 
and implementation necessary as the package itself evolves.

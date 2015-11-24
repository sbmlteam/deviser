
Getting started
===============

Deviser allows a user to define an SBML L3 package and produce libSBML
code which can be overlaid onto the existing libSBML source tree to add
support for the package.

Deviser can also use the package description to create a basic
specification files for the package based on the SBML Level 3 package
class specification.

Both creating code or tex files can be done via a command line
interface.

The Deviser Edit tool provides a GUI to facilitate defining the
necessary information; as well as a convenient way of invoking the
functionality. It also provides some additional functionality (view UML,
create PDF, integrate and test code) to aid the process of definition
and testing.

Functionality
-------------

The Deviser Edit tool outputs an XML definition of the package. This
definition is then used by Deviser code to generate the requested files.
Samples are included with the source code and the full text created by
the examples used in this manual is given in Appendix A.

There is command line version of the function that can be used to invoke
the deviser functionality on the XML file. This is the deviser.py file
found in the generator directory.

deviser.py [--generate][--latex] input-file.xml

This program takes as input a Deviser XML file and either

-  --generate (-g) generates the libSBML code for the package or

-  --latex (-l) generates a LaTeX scaffold for its specification.

The basic Deviser Edit tool provides a number of forms that allow a user
to define an SBML L3 package. Once defined the following functions are
available.

1. Generate the necessary libSBML code for the package.

2. Integrate and test the package with libSBML.

3. Generate TeX files for basic specification of the package.

4. Generate a pdf of a basic specification document for the package.

5. Create and view a UML diagram.

Deviser is not a standalone package and other software may be necessary
in order to access certain functionality. The main functionality is
invoked using a Python Interpreter. Other functions may require further
software. The prerequisites for each function are listed below.

Prerequisites
-------------

Note that since this is a beta release of Deviser we are not bundling
all of the dependencies. Future releases will hope to reduce the
prerequisites.

TO DO: What about this release ?

Source code for libSBML
~~~~~~~~~~~~~~~~~~~~~~~

In order to generate code for libSBML a Python Interpreter is necessary.
Our code has been tested on Python 2.7, 3.3 and 3.4.

-  Python Interpreter

   1. .. rubric:: Integration and testing
         :name: integration-and-testing

Deviser Edit does allow you to automatically integrate and test your
newly created code with libSBML. In order to do this you will need to
have CMake (http://www.cmake.org/), SWIG (http://www.swig.org/) and a
C++ compiler available. In addition you will require the libSBML source
code and the source code for the libSBML dependencies.

-  Python Interpreter

-  CMake

-  SWIG

-  C++ compiler

-  libSBML source code

-  libSBML dependencies source code

   1. .. rubric:: Basic TeX files
         :name: basic-tex-files

Deviser will generate the necessary TeX files with only a Python
Interpreter present.

-  Python Interpreter

   1. .. rubric:: Basic documentation
         :name: basic-documentation

In order to create a PDF it will be necessary to have access to a
version of pdflatex. On Windows having MiKTEX (http://miktex.org/)
installed provides this functionality. The PDF generation also requires
the SBML documentation class files sbmlpkgspec
(https://sourceforge.net/projects/sbml/files/specifications/tex/).

-  Python Interpreter

-  pdflatex (MiKTEX on Windows OS)

-  sbmlpkgspec

Note on a standard Linux OS we found it necessary to install the
following packages:

-  xzdec

-  texlive-latex-base

-  texlive-latex-extra

-  texlive-fonts-extra

and run the following from the command line

-  tlmgr init-usertree

-  tlmgr install bbding

-  tlmgr install fourier

TO DO: Add anything Mac specific

UML diagrams
~~~~~~~~~~~~

Deviser allows you to create and view very basic UML diagrams based on
the classes specified. It uses the free yUML (http://yuml.me/) web
service. Thus it will be necessary to be connected to the internet to
create UML diagrams.

-  Internet connection

   1. .. rubric:: Available bundles
         :name: available-bundles

TO DO: What are we releasing this time ?

Useful links
~~~~~~~~~~~~

1. libSBML source code (latest release):
   https://sourceforge.net/projects/sbml/files/libsbml/5.11.4/stable/libSBML-5.11.4-core-src.tar.gz/download

2. libSBML source code (latest code):
   https://sourceforge.net/p/sbml/code/HEAD/tree/trunk/libsbml/

3. libSBML dependencies (for Windows users):

   https://github.com/sbmlteam/libSBML-dependencies

4. SBML package specification template files:
   https://sourceforge.net/projects/sbml/files/specifications/tex/sbmlpkgspec-1.6.0.tar.gz/download

   1. .. rubric:: Setting up the Deviser Edit tool
         :name: setting-up-the-deviser-edit-tool

In order to access the functionality for generation it is necessary to
tell the Deviser Edit tool where it will find things on your system.

Select Edit->Edit Preferences (Preferences on Mac OSX)

.. image:: ../screenshots/deviser-preferences.png

Figure The ‘Preferences’ sheet - adding information about other required
software.

Fill in or browse to the location of the files requested by each field.
Note it is not necessary to fill in all the fields if you are not
intending to use all the functionality. Figure 1 illustrates a case
where you could generate code and TeX files but not generate a PDF or
integrate the code automatically.

Without any of this information the Deviser Edit tool will save the XML
description and create UML diagrams.

The fields requested are:

**Python Interpreter**. This is location of the python executable. This
is necessary to invoke any functionality of Deviser.

**Deviser repository**. This is the location of the deviser/generator
directory. This will have been bundled with an installer but may also be
obtained directly from our GitHub repository
[https://github.com/sbmlteam/deviser].

**Default output dir**. The location where generated files should be
written\ **.**

**sbmlpkgspec dir**. The location of the SBML documentation class files
sbmlpkgspec.

**MikTeX Bin dir**. The location of the MikTex executables.

NEED TO CLARIFY THIS

**Compiler**. The location of the C++ compiler to be used when building
libSBML with integrated package code.

**libSBML Source dir**. The location of the libSBML source tree. This
should be the top-level libSBML directory.

**Dependencies Source dir**. The location of the libSBML dependencies
source code. Note that particularly on Windows it is necessary for the
libSBML dependencies to be built with the same Compiler as that to be
used to build libSBML. Deviser Edit allows a user to specify the
location of the source code for the dependencies and offers an option to
build them if this should be necessary.

**CMake executable**. The location of the CMake executable. Deviser
creates the necessary CMake files to allow package code to be
integrated. This will be necessary if you intend to use Deviser Edit to
integrate and build your code. Note Deviser does not support any other
build system.

**SWIG executable**. The location of the SWIG executable. Since Deviser
uses a python interpreter to create code, the integration and testing
will create the Python binding of libSBML. SWIG is necessary for this.

**Python include dir**: The location of the python include files. This
is necessary to build and test the Python binding of libSBML.

**Python lib**. The location of the Python library files. This is
necessary to build and test the Python binding of libSBML.


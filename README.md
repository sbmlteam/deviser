# Deviser<img width="11%" align="right" src=".graphics/ICON_Deviser_512x512.png">


*Deviser* stands for *"Design Explorer and
Viewer for Iterative SBML Enhancement of Representations"*.  It is a code generator for defining and prototyping [SBML Level 3](http://sbml.org/Documents/Specifications#SBML_Level_3) packages and code for use with [libSBML](http://sbml.org/Software/libSBML/).


| &nbsp;&nbsp;&nbsp;⭐️ This is the repository for Deviser's code generation facility. The GUI is in a [separate repository](https://github.com/sbmlteam/QtDeviser). ⭐️&nbsp;&nbsp;&nbsp;|
|:-:|


_**Authors**_:      [Sarah M. Keating](http://www.ebi.ac.uk/about/people/sarah-keating) and [Frank T. Bergmann](http://www.cos.uni-heidelberg.de/index.php/f.bergmann?l=_e),
with contributions from [Brett Olivier](https://github.com/bgoli), 
[Lucian Smith](https://github.com/luciansmith) &amp; [Mike Hucka](https://github/mhucka)<br>
_**Repository**_:   https://github.com/sbmlteam/deviser<br>
_**Repository for GUI**_:   https://github.com/sbmlteam/QtDeviser<br>
_**Pivotal tracker**_: https://www.pivotaltracker.com/n/projects/977192<br>
_**License**_:      LGPL version 2.1 &ndash; see the file [LICENSE](LICENSE) for details

## Background ##

Computation modeling has become crucial to biological research, and [SBML](http://sbml.org) (the Systems Biology Markup Language) has become the de facto standard open format for exchanging models between software tools in systems biology.  SBML Level&nbsp;3 has a modular structure, with as a core augmented with optional packages that add syntax and features.  Development of new Level&nbsp;3 packages is ongoing.

[LibSBML](http://sbml.org/Software/libSBML) is a free, open-source programming library to help developers read, write, manipulate, translate, and validate SBML files and data streams in their software systems. It is written in C++ and provides language bindings for other programming languages.  Support for SBML Level&nbsp;3 can be added to [LibSBML](http://sbml.org/Software/libSBML) by integrating the package-specific code and building with the package enabled.

[Deviser](https://github.com/sbmlteam/deviser) facilitates the development of SBML Level&nbsp;3 packages by enabling the creation of basic specifications, UML diagrams and code for integration with [LibSBML](http://sbml.org/Software/libSBML).

Deviser is written in Python and is compatible with Python version 2.6 onwards.


## Using Deviser ##

### Deviser Edit GUI ###

The [Deviser Edit](https://github.com/sbmlteam/QtDeviser) tool allows you to quickly define an SBML Level&nbsp;3 package. It then provides the  following functionality

1.	Create and view a UML diagram.
2.	Generate the necessary libSBML code for the package.
3.	Generate TeX files and generate a PDF of a basic specification document for the package.
4.	Integrate and test the package with libSBML.

The Deviser Edit tool creates an XML description of the package that is used by the deviser code to generate the requested files. This XML description is exemplified in the [samples](deviser/samples) directory.

### Command Line Interface ###

There is command line version of the function that can be used to invoke Deviser on the XML file. This is the `deviser.py` file found in the generator directory.

    deviser.py [--generate][--latex] input-file.xml    

This program will use a Deviser XML file, and generate either a C++ 
libSBML extension for it, or generate a LaTeX scaffold for its 
specification. 

Full documentation is available in the [docs](deviser\docs) directory.


## Installation ##

The deviser release includes bundles/installer for each of the main operating systems.  

### Prerequisites

1. A C++ compiler must be installed if you wish to compile the libSBML code generated.
2. A pdflatex compiler must be installed if you wish to generate a PDF file from the TeX sources generated.

**NOTE**: These may already be available on your OS.

### Microsoft Windows OS

A windows installation executable which installs the Deviser Edit tool (`QtDeviser.exe`), all the necessary Deviser files. Additionally it includes a Python interpreter and the [sbmlpkgspec](https://github.com/sbmlteam/sbmlpkgspec) files for generating SBML Level&nbsp;3 Package specifications.

### Linux OS

A self-contained, binary installer is available that contains Deviser, DeviserEdit and the [sbmlpkgspec](https://github.com/sbmlteam/sbmlpkgspec) modules. After installation DeviserEdit can be run from either a desktop icon or by calling the `DeviserEdit.sh` script in the installation directory. Deviser samples can be found in the `deviser/samples` subdirectory.

### Mac OS X

A `.dmg` file is available containing the DeviserEdit Application that embeds the necessary Deviser and [sbmlpkgspec](https://github.com/sbmlteam/sbmlpkgspec) files in addition to *docs* and *samples* directories. 

### Source archives

The source archives contain the Deviser code that can be used via the command line.


## Other resources ##

Not all of the following are necessary as what is necessary depends on which operating system is being used and which Deviser functionality is required. These links are given as a quick reference.

* [libSBML source code](https://github.com/sbmlteam/libsbml 
* [libSBML dependency libraries for Windows users](https://github.com/sbmlteam/libSBML-dependencies)
* [SBML package specification template files](https://github.com/sbmlteam/sbmlpkgspec)


## Acknowledgments ##

The development of Deviser was supported in part by funding from the National Institute of General Medical Sciences (USA) under grant R01&nbsp;GM070923 (principal investigator: Michael Hucka).


## Copyright and license ##

Copyright (C) 2014-2018 jointly by the California Institute of Technology, Pasadena, CA, USA, EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK and the University of Heidelberg, Heidelberg, Germany

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and documentation provided hereunder is on an "as is" basis, and the California Institute of Technology has no obligations to provide maintenance, support, updates, enhancements or modifications.  In no event shall the California Institute of Technology be liable to any party for direct, indirect, special, incidental or consequential damages, including lost profits, arising out of the use of this software and its documentation, even if the California Institute of Technology has been advised of the possibility of such damage.  See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library in the file named "LICENSE" included with the software distribution.

<br>
<div align="center">
  <a href="https://www.nigms.nih.gov">
    <img height="100" src=".graphics/US-NIH-NIGMS-Logo.svg">
  </a>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <a href="https://www.caltech.edu">
    <img height="100" src=".graphics/caltech-round.png">
  </a>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <a href="https://www.ebi.ac.uk">
    <img height="102" src=".graphics/EMBL_logo.svg">
  </a>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <a href="https://www.uni-heidelberg.de">
    <img height="100" src=".graphics/University_of_Heidelberg.svg">
  </a>
</div>

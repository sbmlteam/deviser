# Deviser



*Deviser* stands for *"Design Explorer and
Viewer for Iterative SBML Enhancement of Representations"*. 


*Authors*:      [Sarah M. Keating](http://www.ebi.ac.uk/about/people/sarah-keating), and [Frank T. Bergmann](http://www.cos.uni-heidelberg.de/index.php/f.bergmann?l=_e)
with contributions from [Brett G. Olivier](http://teusinkbruggemanlab.nl/brett-olivier/), 
Lucian P. Smith and [Mike Hucka](http://www.cds.caltech.edu/~mhucka).

*License*:      This code is licensed under the LGPL version 2.1.  Please see the file [LICENSE.txt](https://raw.githubusercontent.com/sbmlteam/deviser/master/LICENSE.txt) for details.

*Repository*:   [https://github.com/sbmlteam/deviser](https://github.com/sbmlteam/deviser)


*Pivotal tracker*: [https://www.pivotaltracker.com/n/projects/977192](https://www.pivotaltracker.com/n/projects/977192)





## Background ##


Computation modeling has become a crucial aspect of biological research, and [SBML](http://sbml.org) (the Systems Biology Markup Language) has become the de facto standard open format for exchanging models between software tools in systems biology.

[LibSBML](http://sbml.org/Software/libSBML) is a free, open-source programming library to help you read, write, manipulate, translate, and validate SBML files and data streams. Support for SBML Level 3 packages can be added by integrating 
the package specific code and building with the package enabled.

 SBML Level 3 is being developed as a core with additional optional packages. Deviser facilitates the development of these packages by providing a means of creating a basic specification, UML diagrams and code for integration with libSBML.


Deviser is written in Python and is compatible with Python version 2.6 onwards.



## Using Deviser ##

### Deviser Edit GUI ###

The [Deviser Edit](https://github.com/sbmlteam/QtDeviser)  tool allows you to quickly define an SBML L3 package. It then provides the  following functionality

1.	Create and view a UML diagram.
2.	Generate the necessary libSBML code for the package.
3.	Generate TeX files and generate a pdf of a basic specification document for the package.
4.	Integrate and test the package with libSBML.

The Deviser Edit tool creates an XML description of the package that is used by the deviser code to generate the requested files. This XML description is exemplified in the [samples](deviser/samples) directory.

### Command Line Interface ###

There is command line version of the function that can be used to invoke the deviser functionality on the XML file. This is the deviser.py file found in the generator directory.

    deviser.py [--generate][--latex] input-file.xml    

This program will use a Deviser xml file, and generate either a C++ 
libSBML extension for it, or generate a LaTeX scaffold for its 
specification. 

Full documentation is available in the [docs](deviser\docs) directory.


## Installation ##

The deviser release includes bundles/installer for each of the main operating systems.  

### Prerequisites

1. A C++ compiler must be installed if you wish to compile the libSBML code generated.
2. A pdflatex compiler must be installed if you wish to generate a pdf from the TeX sources generated.

**NOTE**: These may already be available on your OS.

### Microsoft Windows OS

A windows installation executable which installs the Deviser Edit tool (QtDeviser.exe), all the necessary Deviser files. Additionally it includes a python interpreter and the sbmlpkgspec files for generating SBML L3 Package specifications.


### Linux OS




### Mac OS X

An dmg file is available containing the DeviserEdit Application that embeds the necessary Deviser and sbmlpkgspec files in addition to *docs* and *samples* directories. 

### Source archives

The source archives contain the Deviser code that can be used via the command line.


## Other resources ##

Not all of the following are necessary as what is necessary depends on which operating system is being used and which Deviser functionality is required. These links are given as a quick reference.

[libSBML source code](https://sourceforge.net/projects/sbml/files/libsbml/5.16.0/stable/libSBML-5.16.0-core-src.tar.gz/download) 

[libSBML dependency libraries for Windows users](https://github.com/sbmlteam/libSBML-dependencies)

[SBML package specification template files](https://sourceforge.net/projects/sbml/files/specifications/tex/sbmlpkgspec-1.6.0.tar.gz/download)





## Acknowledgments ##

We achnowledge funding for Deviser from the National Institutes of Health (USA) under
grant R01 GM070923.


## Copyright and license ##


Copyright (C) 2014-2018 jointly by the California Institute of Technology, Pasadena, CA, USA, EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK and the University of Heidelberg, Heidelberg, Germany

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and documentation provided hereunder is on an "as is" basis, and the California Institute of Technology has no obligations to provide maintenance, support, updates, enhancements or modifications.  In no event shall the California Institute of Technology be liable to any party for direct, indirect, special, incidental or consequential damages, including lost profits, arising out of the use of this software and its documentation, even if the California Institute of Technology has been advised of the possibility of such damage.  See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library in the file named "LICENCE.txt" included with the software distribution.

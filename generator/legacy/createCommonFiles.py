#!/usr/bin/env python
#
# @file    createCommonFiles.py
# @brief   creates the common files
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2014 by the California Institute of Technology
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

import sys, os
import fileHeaders



	
def createExtensionTypes(nameOfPackage, pkg, plugins, classes):
  nameOfClass = nameOfPackage + 'ExtensionTypes'
  codeName = nameOfClass + '.h'
  fileOut = open(codeName, 'w')
  fileHeaders.addFilename(fileOut, codeName, nameOfClass)
  fileHeaders.addLicence(fileOut)
  fileOut.write('#ifndef {0}_H\n'.format(nameOfClass))
  fileOut.write('#define {0}_H\n\n'.format(nameOfClass))
  fileOut.write('#include <sbml/packages/{0}/common/{0}fwd.h>\n\n'.format(pkg))
  fileOut.write('#include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(pkg, nameOfPackage))
  fileOut.write('#include <sbml/packages/{0}/extension/{1}SBMLDocumentPlugin.h>\n'.format(pkg, nameOfPackage))
  for i in range (0, len(plugins)):
    fileOut.write('#include <sbml/packages/{0}/extension/{1}{2}Plugin.h>\n'.format(pkg, nameOfPackage, plugins[i]['sbase']))
  fileOut.write('\n')
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg, classes[i]['name']))
  fileOut.write('\n#endif  /* {0}_H */\n\n'.format(nameOfClass))

def createFWD(pkg, classes):
  nameOfClass = pkg + 'fwd'
  codeName = nameOfClass + '.h'
  fileOut = open(codeName, 'w')
  fileHeaders.addFilename(fileOut, codeName, nameOfClass)
  fileHeaders.addLicence(fileOut)
  fileOut.write('#ifndef {0}_H\n'.format(nameOfClass))
  fileOut.write('#define {0}_H\n\n'.format(nameOfClass))
  fileOut.write('/**\n')
  fileOut.write(' * Forward declaration of all opaque C types.\n')
  fileOut.write(' *\n')
  fileOut.write(' * Declaring all types up-front avoids "redefinition of type Foo" compile\n')
  fileOut.write(' * errors and allows our combined C/C++ headers to depend minimally upon\n')
  fileOut.write(' * each other.  Put another way, the type definitions below serve the same\n')
  fileOut.write(' * purpose as "class Foo;" forward declarations in C++ code.\n')
  fileOut.write(' */\n\n')
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('#  define CLASS_OR_STRUCT class\n')
  fileOut.write('#else\n')
  fileOut.write('#  define CLASS_OR_STRUCT struct\n')
  fileOut.write('#endif  /* __cplusplus */	\n\n')
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n\n')
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('typedef CLASS_OR_STRUCT {0}    {0}_t;\n'.format(classes[i]['name']))
  fileOut.write('\nLIBSBML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#undef CLASS_OR_STRUCT\n\n')
  fileOut.write('\n#endif  /* {0}_H */\n\n'.format(nameOfClass))

def main(package):
  nameOfPackage = package['name']
  pkg = nameOfPackage.lower()
  plugins = package['plugins']
  classes = package['sbmlElements']
  createExtensionTypes(nameOfPackage, pkg, plugins, classes)
  createFWD(pkg, classes)

#!/usr/bin/env python
#
# @file   createCommonFiles.py
# @brief  Create the common src files files
# @author Sarah Keating
#

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

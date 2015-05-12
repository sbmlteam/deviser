__author__ = 'Sarah'

#!/usr/bin/python

import sys
import os
sys.path.append(os.path.dirname(__file__)  + "/../../base_files")
sys.path.append(os.path.dirname(__file__)  + "/../../code_files")
sys.path.append(os.path.dirname(__file__)  + "/../../parseXML")
sys.path.append(os.path.dirname(__file__)  + "/../../spec_files")
sys.path.append(os.path.dirname(__file__)  + "/../../util")
sys.path.append(os.path.dirname(__file__)  + "/../../validation")
sys.path.append(os.path.dirname(__file__)  + "/../..")
import TexValidationRulesFile
import TexBodySyntaxFile
import TexMacrosFile
from createPackageFromXml import *

def generateLatexFor(file):
  ob = parse_deviser_xml(file)
  ff = TexValidationRulesFile.TexValidationRulesFile(ob)
  ff.write_file()
  ff.close_file()
  body = TexBodySyntaxFile.TexBodySyntaxFile(ob)
  body.write_file()
  body.close_file()
  macros = TexMacrosFile.TexMacrosFile(ob)
  macros.write_file()
  macros.close_file()

def main(args):     
  if len(args) != 2:
    print ('Usage: generateLatex.py xmlfile')
  else:
    generateLatexFor(args[1]);

if __name__ == '__main__':
  main(sys.argv)  

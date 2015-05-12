#!/usr/bin/env python
#
# @file    createDirStruct.py
# @brief   creates the directory structure for the code
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

import re, os, sys, string

def createDir(name):
  if os.path.exists(name):
    print 'directory already exists - please use a different name'
    done = False
  else:
    os.mkdir(name)
    print 'creating dir {0}'.format(name)
    done =True
  return done

def createDirectories(pkgName):
    print 'creating directory structure for {0}'.format(pkgName)
    if createDir(pkgName) == False:
      exit
    else:
      thisDir = os.getcwd()
      os.chdir(pkgName)
      createDir('examples')
      createDir('src')
      os.chdir('src')
      createDir('bindings')
      createDir('sbml')
      os.chdir('bindings')
      createDir('csharp')
      createDir('java')
      createDir('javascript')
      createDir('perl')
      createDir('php')
      createDir('python')
      createDir('r')
      createDir('ruby')
      createDir('swig')
      os.chdir('../sbml')
      createDir('packages')
      os.chdir('packages')
      createDir(pkgName)
      os.chdir(pkgName)
      createDir('common')
      createDir('extension')
      createDir('sbml')
      createDir('validator')
      os.chdir('validator')
      createDir('constraints')
      os.chdir(thisDir)
    
def main(args):     
  if len(args) != 2:
    print 'Usage: createDirStruct.py name'
  else:
    name = args[1]
    createDirectories(name)

if __name__ == '__main__':
  main(sys.argv)  



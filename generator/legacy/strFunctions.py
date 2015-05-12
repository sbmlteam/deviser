#!/usr/bin/env python
#
# @file    strFunctions.py
# @brief   functions to adjust strings as necessary
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

import sys

def cleanStr(word):
  final = ''
  i = 0
  while i < len(word): 
    current = word[i]
    if current == '-':
      if i+1 < len(word) and word[i+1] != '-':
        final = final + word[i+1].upper()
        i = i+1
    else:
      final = final + word[i]
    i = i+1
  return final

def capp(word, plural=True):
  capWord = cap(word)
  if plural and word[len(word)-1] != 's':
    capWord = capWord + 's'
  return capWord

def cap(word):
  capWord = word[0].upper() + word[1:len(word)]
  capWord = cleanStr(capWord)
  return capWord
  
  
def lowerFirst(word):
  capWord = word[0].lower() + word[1:len(word)]
  return capWord

def getIndent(element):
  s1 = '{0}('.format(element)
  indent = ''
  for i in range(0, len(s1)):
    indent = indent + ' ';
  return indent;

def objAbbrev(element):
  abbrev = ''
  for i in range (0, len(element)):
    if element[i].isupper():
      abbrev = abbrev + element[i]
  return abbrev.lower()
    
def listOfName(name):
  if (name.endswith('nformation')):
    return 'listOf' + name
  elif (name.endswith('s')):
    return 'listOf' + name
  elif (name.endswith('x')):
    return 'listOf' + name + 'es'
  else:
    listOf = 'listOf' + name + 's'
  return listOf
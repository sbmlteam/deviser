#!/usr/bin/env python
#
# @file   strFunctions.py
# @brief  Create the directory structure for package code
# @author Sarah Keating
#

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
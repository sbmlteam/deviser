#!/usr/bin/env python
#
# @file   createExtensionFiles.py
# @brief  Create the extension src files
# @author Sarah Keating
#

import sys

import writeExtensionHeader
import writeExtensionCode
import writePluginHeader
import writePluginCode
import writeDocPluginHeader
import writeDocPluginCode

def main(package) :
  writeExtensionHeader.createHeader(package)
  writeExtensionCode.createCode(package)
  writeDocPluginHeader.createHeader(package)
  writeDocPluginCode.createCode(package)
  plugins = package['plugins']
  for i in range(0, len(plugins)):
    plugin = plugins[i]
    writePluginHeader.createHeader(package, plugin)
    writePluginCode.createCode(package, plugin)

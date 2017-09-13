.. _licensing:

Appendix D: Licensing the code produced
=======================================

The Deviser and DeviserEdit code is released under the GNU LESSER GENERAL 
PUBLIC LICENSE (LGPL) Version 2.1. A copy of this is included with the 
deviser code and is available `here <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html>`_.


.. Note::

   Code produced by Deviser must be released under the LGPL v2.1 license.



Currently the code produced will include mention of the LGPL license as well 
as the Copyright information for the current SBML Team. Deviser users may add 
their own Copyright information or indeed replace the existing Copyright 
providing a reference is made to Deviser.

At present the way to change what is produced at the top of each file involves 
adjusting the Deviser source code directly. In the file BaseFile.py located at 
deviser/generator/base_files in the 
deviser source tree the function **write_libsbml_licence(self)** produces the 
license and copyright information.

.. code-block:: Python

      def write_libsbml_licence(self):
          self.write_blank_comment_line()
          self.write_comment_line('<!-----------------------------------------'
                                  '---------------------------------')
          self.write_comment_line('This file is part of libSBML.  Please visit '
                                  'http://sbml.org for more information about '
                                  'SBML, and the latest version of libSBML.')
          self.write_blank_comment_line()
          self.write_comment_line('Copyright (C) 2013-2015 jointly by the '
                                  'following organizations:')
          self.write_comment_line('    1. California Institute of Technology, '
                                  'Pasadena, CA, USA')
          self.write_comment_line('    2. EMBL European Bioinformatics '
                                  'Institute (EMBL-EBI), Hinxton, UK')
          self.write_comment_line('    3. University of Heidelberg, Heidelberg, '
                                  'Germany')
          self.write_blank_comment_line()
          self.write_comment_line('Copyright (C) 2009-2013 jointly by the '
                                  'following organizations:')
          self.write_comment_line('    1. California Institute of Technology, '
                                  'Pasadena, CA, USA')
          self.write_comment_line('    2. EMBL European Bioinformatics '
                                  'Institute (EMBL-EBI), Hinxton, UK')
          self.write_blank_comment_line()
          self.write_comment_line('Copyright (C) 2006-2008 by the California '
                                  'Institute of Technology,')
          self.write_comment_line('    Pasadena, CA, USA ')
          self.write_blank_comment_line()
          self.write_comment_line('Copyright (C) 2002-2005 jointly by the '
                                  'following organizations:')
          self.write_comment_line('    1. California Institute of Technology, '
                                  'Pasadena, CA, USA')
          self.write_comment_line('    2. Japan Science and Technology Agency, '
                                  'Japan')
          self.write_blank_comment_line()
          self.write_comment_line('This library is free software; you can '
                                  'redistribute it and/or modify it under the '
                                  'terms of the GNU Lesser General Public '
                                  'License as published by the Free Software '
                                  'Foundation.  A copy of the license agreement'
                                  ' is provided in the file named "LICENSE.txt"'
                                  ' included with this software distribution '
                                  'and also available online as http://sbml.org'
                                  '/software/libsbml/license.html')
          self.write_comment_line('--------------------------------------------'
                                  '---------------------------- -->')



Users should remove or replace the copyright text as appropriate.


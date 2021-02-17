# Trying out pytest with Deviser cpp tests
# Matthew S. Gillman, UCL, 17th February 2021
import os
import sys
import pytest
# If we can restructure it ok, we might not need this...
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../tests')
import deviser
import test_functions
from util import global_variables as gv
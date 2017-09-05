#!/usr/bin/env python

import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from code_files import CppFiles, ExtensionFiles, ValidationFiles
from parseXML import ParseXML

from tests import test_functions


##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_new_cpp_header(filename, num):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    working_class = ob['baseElements'][num]
    os.chdir('./temp')
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../.')


def generate_extension_header(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, '', True)
    all_files.write_files()
    os.chdir('../.')


def generate_types_header(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, 'types', True)
    all_files.write_files()
    os.chdir('../.')


def generate_fwd_header(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    all_files.write_files()
    os.chdir('../.')


def generate_plugin_header(filename, num):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, '', True)
    all_files.write_plugin_files(num)
    os.chdir('../.')


def generate_error_header(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_error_header()
    all_files.write_error_table_header()
    os.chdir('../.')


def generate_validator(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_validator_files()
    os.chdir('../.')


def generate_constraints(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_constraints()
    os.chdir('../.')


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_code_headers(class_name):
    correct_file = '.\\test-code\\{0}.h'.format(class_name)
    temp_file = '.\\temp\\{0}.h'.format(class_name)
    return compare_files(correct_file, temp_file)


def compare_ext_headers(class_name):
    correct_file = '.\\test-extension\\{0}.h'.format(class_name)
    temp_file = '.\\temp\\{0}.h'.format(class_name)
    return compare_files(correct_file, temp_file)


def compare_code_impl(class_name):
    correct_file = '.\\test-code\\{0}.cpp'.format(class_name)
    temp_file = '.\\temp\\{0}.cpp'.format(class_name)
    return compare_files(correct_file, temp_file)


def compare_ext_impl(class_name, declared=False):
    if declared:
        correct_file = '.\\test-extension\\{0}Declared.cxx'.format(class_name)
        temp_file = '.\\temp\\{0}Declared.cxx'.format(class_name)
    else:
        correct_file = '.\\test-extension\\{0}.cpp'.format(class_name)
        temp_file = '.\\temp\\{0}.cpp'.format(class_name)
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions

def run_test(name, num, class_name, test_case, list_of):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_new_cpp_header(filename, num)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    if len(list_of) > 0:
        class_name = list_of
        fail += compare_code_headers(class_name)
        fail += compare_code_impl(class_name)
    print('')
    return fail


def run_ext_test(name, class_name, test_case, test):
    filename = test_functions.set_up_test(name, class_name, test_case)
    if test == 0:
        generate_extension_header(filename)
    elif test == 1:
        generate_types_header(filename)
    else:
        generate_fwd_header(filename)
    fail = compare_ext_headers(class_name)
    if test == 0:
        fail += compare_ext_impl(class_name)
    print('')
    return fail


def run_plug_test(name, class_name, test_case, num):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_plugin_header(filename, num)
    fail = compare_ext_headers(class_name)
    fail += compare_ext_impl(class_name)
    print('')
    return fail


def run_valid_test(name, class_name, test_case, is_ext=True):
    filename = test_functions.set_up_test(name, class_name, test_case)
    if is_ext:
        generate_error_header(filename)
        fail = compare_ext_headers(class_name)
        fail += compare_ext_headers('{0}Table'.format(class_name))
    else:
        generate_validator(filename)
        fail = compare_ext_headers(class_name)
        fail += compare_ext_impl(class_name)
    print('')
    return fail


def run_constraints_test(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_constraints(filename)
    fail = compare_ext_impl(class_name)
    fail += compare_ext_impl(class_name, declared=True)
    print('')
    return fail


#########################################################################
# Main function

def main():

    runall = True
    this_dir = os.path.dirname(os.path.abspath(__file__))
    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    if runall:
        # run the individual tests
        name = 'test_att'
        num = 1
        class_name = 'Unit'
        list_of = ''
        test_case = 'unit sid ref'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_att'
        num = 2
        class_name = 'MyLoTest'
        list_of = 'ListOfMyLoTests'
        test_case = 'attribute on ListOf'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_att'
        num = 0
        class_name = 'MyTestClass'
        list_of = ''
        test_case = 'all types of attributes'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_att'
        num = 3
        class_name = 'MyRequiredClass'
        list_of = ''
        test_case = 'all types attributes required'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_att'
        num = 4
        class_name = 'ArrayChild'
        list_of = ''
        test_case = 'child elements and arrays'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_att'
        num = 5
        class_name = 'Container'
        list_of = ''
        test_case = 'a listOf child that uses listOfFoo as the name'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_att'
        class_name = 'TestSBMLError'
        test_case = 'error enumeration '
        fail += run_valid_test(name, class_name, test_case)

        name = 'qual'
        num = 5
        class_name = 'FunctionTerm'
        list_of = 'ListOfFunctionTerms'
        test_case = 'an element on ListOf'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'qual'
        num = 3
        class_name = 'Output'
        list_of = 'ListOfOutputs'
        test_case = 'simple class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'qual'
        num = 1
        class_name = 'Transition'
        list_of = 'ListOfTransitions'
        test_case = 'class with child list of elements'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'qual'
        class_name = 'QualExtension'
        test_case = 'basic extension file'
        fail += run_ext_test(name, class_name, test_case, 0)

        name = 'qual'
        num = 0
        class_name = 'QualModelPlugin'
        test_case = 'basic plugin'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'qual'
        class_name = 'QualExtensionTypes'
        test_case = 'the types '
        fail += run_ext_test(name, class_name, test_case, 1)

        name = 'qual'
        class_name = 'qualfwd'
        test_case = 'forward declarations '
        fail += run_ext_test(name, class_name, test_case, 2)

        name = 'qual'
        num = 1
        class_name = 'QualSBMLDocumentPlugin'
        test_case = 'document plugin'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'qual'
        class_name = 'QualSBMLError'
        test_case = 'error enumeration '
        fail += run_valid_test(name, class_name, test_case)

        name = 'qual'
        class_name = 'QualConsistencyValidator'
        test_case = 'validator'
        fail += run_valid_test(name, class_name, test_case, False)

        name = 'qual'
        class_name = 'QualValidator'
        test_case = 'validator'
        fail += run_valid_test(name, class_name, test_case, False)

        name = 'distrib'
        num = 2
        class_name = 'UncertaintyOld'
        list_of = ''
        test_case = 'class with other child'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'distrib'
        class_name = 'DistribSBMLError'
        test_case = 'error enumeration '
        fail += run_valid_test(name, class_name, test_case)

        name = 'spatial'
        num = 7
        class_name = 'CoordinateComponent'
        list_of = 'ListOfCoordinateComponents'
        test_case = 'class with same child element diff name'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 15
        class_name = 'CSGeometry'
        list_of = ''
        test_case = 'abstract'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 17
        class_name = 'CSGNode'
        list_of = 'ListOfCSGNodes'
        test_case = 'abstract'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 16
        class_name = 'CSGObject'
        list_of = ''
        test_case = 'abstract children'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 33
        class_name = 'SpatialPoints'
        list_of = ''
        test_case = 'array type'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 8
        class_name = 'SampledFieldGeometry'
        list_of = ''
        test_case = 'non sbase base class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 9
        class_name = 'SampledField'
        list_of = ''
        test_case = 'additional code files'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 18
        class_name = 'CSGTransformation'
        list_of = ''
        test_case = 'abstract non base class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 3
        class_name = 'Boundary'
        list_of = ''
        test_case = 'overwrites element name'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 13
        class_name = 'ParametricGeometry'
        list_of = ''
        test_case = 'child element and child lo_element'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 12
        class_name = 'AnalyticVolume'
        list_of = 'ListOfAnalyticVolumes'
        test_case = 'class with math child'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 5
        class_name = 'GeometryDefinition'
        list_of = 'ListOfGeometryDefinitions'
        test_case = 'class with math child'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 31
        class_name = 'MixedGeometry'
        list_of = ''
        test_case = 'class with math child'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 25
        class_name = 'CSGSetOperator'
        list_of = ''
        test_case = 'contains list of that has abstracts that are abstract'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'spatial'
        num = 1
        class_name = 'SpatialCompartmentPlugin'
        test_case = 'plugin with child element'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'spatial'
        num = 3
        class_name = 'SpatialParameterPlugin'
        test_case = 'plugin with additional code'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'spatial'
        num = 4
        class_name = 'SpatialReactionPlugin'
        test_case = 'plugin only attributes'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'spatial'
        num = 5
        class_name = 'SpatialSBMLDocumentPlugin'
        test_case = 'include line over extends'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'spatial'
        class_name = 'SpatialConsistencyConstraints'
        test_case = 'constraints'
        fail += run_constraints_test(name, class_name, test_case)

        name = 'spatial'
        class_name = 'SpatialValidator'
        test_case = 'validator'
        fail += run_valid_test(name, class_name, test_case, False)

        name = 'groups'
        num = 1
        class_name = 'Member'
        list_of = 'ListOfMembers'
        test_case = 'list of with attribute'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'groups'
        num = 0
        class_name = 'GroupsModelPlugin'
        test_case = 'plugin with additional code'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'test_vers'
        num = 0
        class_name = 'ClassOne'
        list_of = ''
        test_case = 'multiple versions'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_vers'
        num = 2
        class_name = 'BBB'
        list_of = ''
        test_case = 'multiple versions same child lo'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_vers'
        num = 0
        class_name = 'VersModelPlugin'
        test_case = 'versions of plugins - attributes'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'test_vers'
        num = 1
        class_name = 'VersSpeciesPlugin'
        test_case = 'versions of plugins - elements'
        fail += run_plug_test(name, class_name, test_case, num)

        name = 'test_vers'
        class_name = 'VersExtension'
        test_case = 'multi version extension file'
        fail += run_ext_test(name, class_name, test_case, 0)

        name = 'fbc_v2'
        num = 5
        class_name = 'FbcAnd'
        list_of = ''
        test_case = 'inline_lo_element'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_child'
        num = 0
        class_name = 'MySEDClass'
        list_of = ''
        test_case = 'different language'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'base_class'
        num = 0
        class_name = 'MyBase'
        list_of = ''
        test_case = 'class with no given base class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'base_class'
        num = 1
        class_name = 'ClassTwo'
        list_of = 'ListOfClassTwos'
        test_case = 'class with lower case name'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'base_class'
        num = 2
        class_name = 'ClassThree'
        list_of = ''
        test_case = 'class with enum lower case name'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'base_class'
        class_name = 'TestExtension'
        test_case = 'default typecodes extension file'
        fail += run_ext_test(name, class_name, test_case, 0)

        name = 'unknown_type'
        num = 0
        class_name = 'UnknownType'
        list_of = ''
        test_case = 'class using an unknown attribute type'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_sidrefs'
        class_name = 'RefsSBMLError'
        test_case = 'sidref with multiple targets '
        fail += run_valid_test(name, class_name, test_case)

        name = 'test_sidrefs_1'
        class_name = 'RefsSBMLError'
        test_case = 'sidref with multiple targets - diff spacing'
        fail += run_valid_test(name, class_name, test_case)

        name = 'test_sidrefs_2'
        class_name = 'RefsSBMLError'
        test_case = 'sidref with multiple targets - diff spacing'
        fail += run_valid_test(name, class_name, test_case)

        name = 'test_sidrefs_3'
        class_name = 'RefsSBMLError'
        test_case = 'sidref with multiple targets - diff spacing'
        fail += run_valid_test(name, class_name, test_case)

        name = 'test_sidrefs_4'
        class_name = 'RefsSBMLError'
        test_case = 'sidref with multiple targets - diff spacing'
        fail += run_valid_test(name, class_name, test_case)

        name = 'test_lists'
        class_name = 'FooSBMLError'
        test_case = 'error enumeration '
        fail += run_valid_test(name, class_name, test_case)

        name = 'nasty_lists'
        num = 0
        class_name = 'Child'
        list_of = ''
        test_case = 'non uniform listOf name'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'nasty_lists'
        num = 2
        class_name = 'Parent'
        list_of = ''
        test_case = 'non uniform listOf name'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'nasty_lists_alt1'
        num = 2
        class_name = 'Parent'
        list_of = ''
        test_case = 'non uniform listOf name'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'lo_children'
        num = 1
        class_name = 'ContainerX'
        list_of = ''
        test_case = 'variants of lo child elements and differing api/xml names'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'xml_names'
        num = 0
        class_name = 'Fred'
        list_of = ''
        test_case = 'attribute xml names differ'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'xml_names'
        num = 1
        class_name = 'Other'
        list_of = ''
        test_case = 'element xml names differ'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'add_copyright'
        num = 0
        class_name = 'Copyright'
        list_of = ''
        test_case = 'additional copyright'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'core'
        num = 0
        class_name = 'Compartment'
        list_of = ''
        test_case = 'new attribute'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'core'
        num = 14
        class_name = 'ModifierSpeciesReference'
        list_of = ''
        test_case = 'new attribute'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'core'
        num = 22
        class_name = 'Event'
        list_of = ''
        test_case = 'new element functions'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 2
        class_name = 'Distribution'
        list_of = ''
        test_case = 'abstract class with multiple abstract children'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 0
        class_name = 'DrawFromDistribution'
        list_of = ''
        test_case = 'abstract class with multiple abstract children'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 6
        class_name = 'DiscreteUnivariateDistribution'
        list_of = ''
        test_case = 'abstract class with multiple abstract children'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 15
        class_name = 'BernoulliDistribution'
        list_of = ''
        test_case = 'concrete class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 14
        class_name = 'Category'
        list_of = 'ListOfCategories'
        test_case = 'concrete class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 13
        class_name = 'CategoricalDistribution'
        list_of = ''
        test_case = 'concrete class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 16
        class_name = 'BetaDistribution'
        list_of = ''
        test_case = 'concrete class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 23
        class_name = 'ExponentialDistribution'
        list_of = ''
        test_case = 'concrete class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 17
        class_name = 'BinomialDistribution'
        list_of = ''
        test_case = 'concrete class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'new_distrib'
        num = 21
        class_name = 'Uncertainty'
        list_of = ''
        test_case = 'concrete class'
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_core_vers'
        class_name = 'CoreversExtension'
        test_case = 'core version extension file'
        fail += run_ext_test(name, class_name, test_case, 0)

        name = 'test_core_vers_pkg'
        class_name = 'CoreversPkgExtension'
        test_case = 'core version and package version not 1 extension file'
        fail += run_ext_test(name, class_name, test_case, 0)

        name = 'test_core_vers_multipkg'
        num = 0
        class_name = 'ClassOneTwo'
        list_of = ''
        test_case = 'core version and package version not 1 '
        fail += run_test(name, num, class_name, test_case, list_of)

        name = 'test_core_vers_multipkg'
        class_name = 'CoreversMultiPkgExtension'
        test_case = 'multiple core version and package version not 1 extension file'
        fail += run_ext_test(name, class_name, test_case, 0)

        name = 'test_core_vers_multipkg'
        num = 0
        class_name = 'CoreversMultiPkgModelPlugin'
        test_case = 'versions of plugins - elements'
        fail += run_plug_test(name, class_name, test_case, num)
        # name = 'arrays'
        # class_name = 'ArraysExtensionTypes'
        # test_case = 'the types '
        # fail += run_ext_test(name, class_name, test_case, 1)
        #
        # name = 'arrays'
        # class_name = 'ArraysExtension'
        # test_case = 'basic extension file'
        # fail += run_ext_test(name, class_name, test_case, 0)
        #
        # name = 'arrays'
        # num = 1
        # class_name = 'Index'
        # list_of = 'ListOfIndices'
        # test_case = 'list of with attribute'
        # fail += run_test(name, num, class_name, test_case, list_of)
        #
        # name = 'arrays'
        # class_name = 'ArraysValidator'
        # test_case = 'validator'
        # fail += run_valid_test(name, class_name, test_case, False)
    else:

        name = 'test_att'
        num = 4
        class_name = 'ArrayChild'
        list_of = ''
        test_case = 'child elements and arrays'
        fail += run_test(name, num, class_name, test_case, list_of)

    test_functions.report('CPP', fail, fails, not_tested)
    return fail

if __name__ == '__main__':
    main()

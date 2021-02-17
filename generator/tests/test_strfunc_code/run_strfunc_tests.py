#!/usr/bin/env python
# Tests for deviser/util/strFunctions.py
# Matthew Gillman, UCL, December 2020
# I guess we'll need a copyright statement, etc., here?
import os
import sys


from tests import test_functions

from util import strFunctions as sf, global_variables as gv

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')


##############################################################################


def run_strfunc_test(func, input, expected_output, fails, **kwargs):
    """
    Run a single test case on a strFunc function, and check that
    the actual output returned is the same as that expected.

    :param func: the strFunc function under test
    :param input: input to function
    :param expected_output: what we expect the function to return. Can be None.
    :param fails: the list of failure information strings.
    :param **kwargs: any additional named arguments for the function
    :return: 0 on success, 1 on failure
    """
    actual_output = func(input, **kwargs)
    # We should maybe use test_functions.compare_return_codes() here,
    # although none of the other test files seem to use it!
    if actual_output == expected_output:
        return 0
    else:
        errormsg = "*** Error in strfunc test! "
        errormsg += "function:{0}, input:{1}, output:{2}, expected:{3}."\
            .format(func, input, actual_output, expected_output)
        fails.append(errormsg)
        return 1


def execute_tests(func, test_data, fails, **kwargs):
    """
    Execute a set of individual tests on a strFunc function.

    :param func: the function under test
    :param test_data: dictionary of test data
                      (keys=inputs, values=expected outputs)
    :param fails: the list of failure information strings.
    :param **kwargs: any named arguments for the function
    :return: number of failed tests for this set.

    TODO should we move this to test_functions.py? The test function to run
    one test (here, `run_str_func`) could be a new func2 argument above,
    to make this more generic.
    """
    counter = 0
    for (input, expected) in test_data.items():
        counter += run_strfunc_test(func, input, expected, fails, **kwargs)
    return counter


def swap_dictionary(old_dict):
    """
    Use the values of the old dictionary as keys for the new one,
    and the keys of the old dictionary as the values of the new one.

    :param old_dict: the old (i.e. input) dictionary
    :return: the newly-created dictionary

    TODO should we move this to test_functions.py?
    """
    new_dict = {}
    for (key, value) in old_dict.items():
        new_dict[value] = key
    return new_dict


def compare_dictionaries(input, expected, fails):
    """
    Are these two dictionaries the same?
    If no, find out at least one place where they are different.

    :param input: the first dictionary
    :param expected: what the first is expected to be
    :param fails: the list of failure cases' strings
    :return 0 on success, 1 on failure.

    TODO should we move this to test_functions.py?
    """
    if input == expected:
        return 0

    # Failure.
    errormsg = "*** Error in strfunc test! "
    fails.append(errormsg)
    check_keys(input, expected, fails)
    check_keys(expected, input, fails)
    return 1


def check_keys(first, second, fails):
    """
    Check two dictionaries. Only expected to be called if they
    are different in some way. Report if at least one key of first dict
    is missing from second. And for keys which are present in both,
    report if there is a difference in the values. Add details to
    fails list.

    NB This won't report more than one failure, e.g.
    if there are two (or more) keys in first missing from second,
    and/or different values in second, this will only report the first
    error it finds.

    :param first: the first dictionary
    :param second: the second dictionary
    :fails: the list of failure cases we are keeping
    :return: nothing

    TODO should we move this to test_functions.py?
    """
    first_keys = list(first.keys())
    for k in first_keys:
        if k not in second:
            msg = "Key {0} is in one dict but not in other".format(k)
            fails.append(msg)
            return
        if first[k] != second[k]:
            msg = "Key {0} has value {1} in one dict but value {2} in other". \
                format(k, first[k], second[k])
            fails.append(msg)
            return


def single_then_plural(name):
    singular = sf.singular(name)
    return sf.plural(singular)


def plural_then_single(name):
    plural = sf.plural(name)
    return sf.singular(plural)


def main():

    # NOTE: the test sets below are in the same order as the functions
    # appear in strFunctions.py. Please maintain that. Thanks.

    # Set up variables
    fails = []
    not_tested = []
    fail = 0

    ########################## Start of tests. ##############################

    # upper_first() tests
    fail += run_strfunc_test(sf.upper_first, 'cat', 'Cat', fails)
    # fail += run_strfunc_test(sf.upper_first, 'cat', 'CAT')  # A failure test
    data = {'cat': 'Cat', 'csgsomething': 'CSGsomething', 'csgcat': 'CSGcat',
            'cscat': 'Cscat', 'csgeometry': 'CSGeometry',
            'csGeometry': 'CSGeometry', 'a': 'A'}
    fail += execute_tests(sf.upper_first, data, fails)

    # lower_first() tests - it's virtually the exact opposite of upper_first()
    data2 = swap_dictionary(data)
    fail += execute_tests(sf.lower_first, data2, fails)

    # abbrev_name() tests
    data = {"thisIsATest": "iat", "CAT": "cat", "cat": "c", "c": "c", "C": "c"}
    fail += execute_tests(sf.abbrev_name, data, fails)

    # abbrev_lo_name() tests
    data = {"spaghetti": "", "ListOfFoo": "LOFoo", "ListOfFOO": "LOFOO"}
    fail += execute_tests(sf.abbrev_lo_name, data, fails)

    # list_of_name() tests
    gv.reset()
    data = {"FooParameter": "ListOfFooParameters"}
    fail += execute_tests(sf.list_of_name, data, fails, add_prefix=True)
    fail += execute_tests(sf.list_of_name, data, fails, add_prefix=False)
    # print(f"gv is package: {gv.is_package}, gv prefix: {gv.prefix}")
    gv.is_package = False
    fail += execute_tests(sf.list_of_name, data, fails, add_prefix=False)
    data = {"FooParameter": "SBMLListOfFooParameters"}
    fail += execute_tests(sf.list_of_name, data, fails, add_prefix=True)

    # lower_list_of_name_no_prefix() tests
    gv.reset()
    data = {"fox": "listOfFoxes", "cat": "listOfCats",
            "child": "listOfChildren"}
    fail += execute_tests(sf.lower_list_of_name_no_prefix, data, fails)
    gv.is_package = False
    fail += execute_tests(sf.lower_list_of_name_no_prefix, data, fails)

    # cap_list_of_name() tests
    gv.reset()
    data = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats"}
    fail += execute_tests(sf.cap_list_of_name, data, fails, add_prefix=False)
    fail += execute_tests(sf.cap_list_of_name, data, fails, add_prefix=True)
    gv.is_package = False
    fail += execute_tests(sf.cap_list_of_name, data, fails, add_prefix=False)
    data = {"FooParameter": "SBMLListOfFooParameters", "cat": "SBMLListOfCats"}
    fail += execute_tests(sf.cap_list_of_name, data, fails, add_prefix=True)

    # cap_list_of_name_no_prefix() tests
    gv.reset()
    data = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats",
            "SBMLFooParameter": "ListOfSBMLFooParameters"}
    fail += execute_tests(sf.cap_list_of_name_no_prefix, data, fails)
    gv.is_package = False
    # this gets wrongly dealt with by the remove prefix function
    #TODO sort
    data = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats",
            "SBMLFooParameter": "ListOfFooParameters"}
#    fail += execute_tests(sf.cap_list_of_name_no_prefix, data, fails)

    # plural_no_prefix() tests
    gv.reset()
    data = {"fox": "foxes", "child": "children", "SBMLchild": "SBMLchildren"}
    fail += execute_tests(sf.plural_no_prefix, data, fails)
    gv.is_package = False
    gv.prefix = "Rosie"
    data = {"RosieFox": "Foxes", "RosieChild": "Children", "RosieCat": "Cats",
            "Rosiefox": "Rosiefoxes"} # prefix only removed if capital after
    fail += execute_tests(sf.plural_no_prefix, data, fails)
    gv.is_package = True
    data = {"Rosiefox": "Rosiefoxes", "Rosiechild": "Rosiechildren",
            "RosieCat": "RosieCats"}
    fail += execute_tests(sf.plural_no_prefix, data, fails)

    # plural() tests
    data = {"cat": "cats", "dogs": "dogs", "child": "children",
            "disinformation": "disinformation", "fox": "foxes",
            "party": "parties", "cloud": "clouds", "something": "somethings",
            "apple": "apples"}
    fail += execute_tests(sf.plural, data, fails)

    # singular() tests
    data2 = swap_dictionary(data)
    data2['dogs'] = 'dog'  # Just need to tweak this one entry. Otherwise OK.
    fail += execute_tests(sf.singular, data2, fails)

    # single -> plural -> single
    data = {"cat": "cat", "dog": "dog", "child": "child",
            "disinformation": "disinformation", "fox": "fox",
            "party": "party", "cloud": "cloud", "something": "something",
            "apple": "apple"}
    fail += execute_tests(plural_then_single, data, fails)

    data = {"cats": "cats", "dogs": "dogs", "children": "children",
            "disinformation": "disinformation", "foxes": "foxes",
            "parties": "parties", "clouds": "clouds",
            "somethings": "somethings", "apples": "apples"}
    fail += execute_tests(single_then_plural, data, fails)

    # remove_prefix() tests - this is a complicated function to test!
    # tests removing a package prefix
    gv.reset()  # gv.prefix now "SBML"
    gv.is_package = True
    gv.package_prefix = 'Fbc'
    data = {"FbcType": "Type", "FluxObjective": "FluxObjective",
            "FbcSBMLDocument": "FbcSBMLDocument"}
    fail += execute_tests(sf.remove_prefix, data, fails)
    fail += execute_tests(sf.remove_prefix, data, fails, remove_package=True)

    doc_data = {"FbcSBMLDocument": "SBMLDocument"}
    fail += execute_tests(sf.remove_prefix, doc_data, fails,
                          remove_doc_prefix=True)

    gv.reset()  # gv.prefix now "SBML"
    gv.is_package = True
    gv.package_prefix = ''  # package prefix has not been specified
    fail += execute_tests(sf.remove_prefix, data, fails, prefix='Fbc')

    # no prefix to remove has been specified or explicitly told not to remove
    data = {"FbcType": "FbcType", "FluxObjective": "FluxObjective",
            "FbcSBMLDocument": "FbcSBMLDocument"}
    fail += execute_tests(sf.remove_prefix, data, fails, prefix='')
    fail += execute_tests(sf.remove_prefix, data, fails, prefix='Fbc',
                          remove_package=False)
    fail += execute_tests(sf.remove_prefix, data, fails,
                          remove_doc_prefix=True)
    fail += execute_tests(sf.remove_prefix, data, fails, prefix='',
                          remove_doc_prefix=True)
    fail += execute_tests(sf.remove_prefix, data, fails, prefix='Fbc',
                          remove_doc_prefix=False, remove_package=False)

    doc_data = {"FbcSBMLDocument": "SBMLDocument"}
    fail += execute_tests(sf.remove_prefix, doc_data, fails, prefix='Fbc',
                          remove_doc_prefix=True)

    gv.reset()  # gv.prefix now "SBML"
    gv.prefix="Rosie"
    gv.is_package = False

    data = {"RosieFbcType": "FbcType", "RosieDocument": "RosieDocument"}
    fail += execute_tests(sf.remove_prefix, data, fails, prefix='Rosie')

    data_doc = {"RosieFbcType": "FbcType", "RosieDocument": "Document"}
    fail += execute_tests(sf.remove_prefix, data_doc, fails, prefix='Rosie',
                          remove_doc_prefix=True)

    gv.reset()  # gv.prefix now "SBML"
    data = {}

    # is_prefixed_name_test
    data = {"RosieFox": True, "rosieFoo": True, "rosiefoo": False,
            "RosiFox": False, "RoSiEFoo": True, "RoSiEfoo": False}
    fail += execute_tests(sf.is_prefixed_name, data, fails, prefix='Rosie')

    # is_prefixed_document_class test
    data = {"RosieDocument": True, "rosieDocument": True,
            "rosiedocument": False, "RosiDocument": False,
            "RoSiEDocument": True, "RoSiEDocment": False}
    fail += execute_tests(sf.is_prefixed_document_class, data, fails,
                          prefix='Rosie')

    # get_indefinite() tests
    data = {"apple": "an", "biscuit": "a", "elephant": "an", "image": "an",
            "polar bear": "a", "orangutan": "an", "under secretary": "an",
            "zither": "a"}
    fail += execute_tests(sf.get_indefinite, data, fails)

    # standard_element_name() tests
    data = {"listOfFoxes,": "Fox", "ListOfApples": "Apple",
            "XMLNode*": "XMLNode", "Rosie,": "Rosie", "rosie,": "Rosie",
            "name_t": "Name", "Name": "Name", "name": "Name"}
    fail += execute_tests(sf.standard_element_name, data, fails)

    # get_library_suffix() tests
    data = {"library": "Rary", "libSBML": "Sbml", "cat": "Cat", "lib": ""}
    fail += execute_tests(sf.get_library_suffix, data, fails)

    # A varargs example - wrap_token
    fail += run_strfunc_test(sf.wrap_token, 'fred',
                             '\\token{cat:\\-fred}', fails, pkg='cat')
    fail += run_strfunc_test(sf.wrap_token, 'fred',
                             '\\token{fred}', fails)

    # wrap_type() tests - I don't really understand this one!

    # wrap_section() tests - or this one!

    # make_class() tests
    fail += run_strfunc_test(sf.make_class, 'Irenaeus', 'irenaeus-class', fails)
    fail += run_strfunc_test(sf.make_class, 'Irenaeus', 'extended-irenaeus-class',
                             fails, add_extended=True)

    # wrap_enum() tests
    fail += run_strfunc_test(sf.wrap_enum, 'cat', '\\primtype{cat}', fails)

    # get_sid_refs() tests 'cat': 'Cat', 'csgsomething': 'CSGsomething',
    data = {'': ['', 'SId'], 'cat': ['Cat', 'Cat'],
            'csgsomething': ['CSGsomething', 'CSGsomething'],
            'cat,dog': ["Cat or \Dog", "CatOrDog"]}
    fail += execute_tests(sf.get_sid_refs, data, fails)

    # get_element_name() tests
    attribute1 = {'something': 'something else'}
    attribute2 = {'type': 'element', 'element': 'ASTNode*', 'texname': 'tex'}
    attribute3 = {'isListOf': 'somethingrandom', 'name': 'SBMLFoo'}
    fail += run_strfunc_test(sf.get_element_name, attribute1, "FIX_ME", fails)
    fail += run_strfunc_test(sf.get_element_name, attribute2, "MathML math", fails)
    fail += run_strfunc_test(sf.get_element_name, attribute3, "\ListOfSBMLFoos", fails)

    # At the moment, the same tests are used for both get_element_name() and
    # get_element_name_no_prefix(). They are quite similar functions. Ideally
    # I guess we should add a test which gives a different result between them.
    # Otherwise there is little point in having both functions. TODO

    # get_element_name_no_prefix() tests
    fail += run_strfunc_test(sf.get_element_name_no_prefix, attribute1, "FIX_ME", fails)
    fail += run_strfunc_test(sf.get_element_name_no_prefix, attribute2, "MathML math", fails)
    fail += run_strfunc_test(sf.get_element_name_no_prefix, attribute3, "\ListOfSBMLFoos", fails)

    # replace_digits() tests
    fail += run_strfunc_test(sf.replace_digits, "John 3:16", "John Three:OneSix", fails)

    # replace_underscore() tests
    data = {"this_is_a_test": "this\_is\_a\_test", "cat": "cat", "_": "\_"}
    fail += execute_tests(sf.replace_underscore, data, fails)

    # remove_spaces() tests
    data = {"   hello   world  ": "helloworld", "dogfish": "dogfish"}
    fail += execute_tests(sf.remove_spaces, data, fails)

    # remove_hyphens() tests
    data = {"this-is-a-test": ["thisIsATest", True], "cat": ["cat", False],
            "cat-": ["cat", True], "-cat": ["Cat", True]}
    fail += execute_tests(sf.remove_hyphens, data, fails)

    # texify() tests
    fail += run_strfunc_test(sf.texify, "012_27 cat44_8 ",
                             "ZeroOneTwo\_TwoSevencatFourFour\_Eight", fails)

    # compare_no_case() tests
    fail += run_strfunc_test(sf.compare_no_case, "This iS a TEST", True, fails,
                             reference="this is a test")
    fail += run_strfunc_test(sf.compare_no_case, "This iS a bad TEST", False,
                             fails,
                             reference="this is a test")

    # get_class_from_plugin() tests
    fail += run_strfunc_test(sf.get_class_from_plugin, "CompModelPlugin",
                             "Model",
                             fails,
                             package="Comp")
    fail += run_strfunc_test(sf.get_class_from_plugin, "CompModelPlug",
                             "",
                             fails,
                             package="Comp")
    fail += run_strfunc_test(sf.get_class_from_plugin, "Plugin",
                             "",
                             fails,
                             package="Comp")

    # prefix_name() tests
    gv.reset()
    gv.prefix = "DABS"
    data = {"DABS": "DABS", "DABSCAT": "DABSCAT", "dabs": "DABSdabs",
            "SBase": "DABSBase", "XMLNode": "XMLNode",
            "XMLNodeAgain": "DABSXMLNodeAgain", "ASTNode": "ASTNode"}
    fail += execute_tests(sf.prefix_name, data, fails)

    # prefix_classes() tests
    # This func doesn't return anything at the moment. So we have to
    # compare "changing" dictionary with what we expect it to be once
    # it's changed.
    gv.reset()  # gv.prefix is now "SBML"
    changing_dict = {'name': 'Colin', 'baseClass': gv.baseClass}
    expected_dict = {'name': 'SBMLColin', 'baseClass': gv.baseClass,
                     'elementName': 'colin'}
    run_strfunc_test(sf.prefix_classes, changing_dict, None, fails)  # Do not consume return value
    fail += compare_dictionaries(changing_dict, expected_dict, fails)

    # Now a test of the same function, this time with a list of attribute dictionaries
    # as a value in `changing_dict` and `expected_dict`:
    attrib1_before = {'type': 'lo_element', 'element': 'Dabs'}
    attrib1_after = {'type': 'lo_element', 'element': 'SBMLDabs'}
    attrib2_before = {'type': 'inline_lo_element', 'element': 'ASTNode'}
    attrib2_after = {'type': 'inline_lo_element', 'element': 'ASTNode'}
    concrete_before = [{'element': 'test'}]
    concrete_after = [{'element': 'SBMLtest'}]
    attrib2_before['concrete'] = concrete_before
    attrib2_after['concrete'] = concrete_after
    attribs_before = [attrib1_before, attrib2_before]
    attribs_after = [attrib1_after, attrib2_after]
    changing_dict = {'name': 'Colin', 'baseClass': gv.baseClass,
                     'lo_class_name': 'Dabs', 'attribs': attribs_before}
    expected_dict = {'name': 'SBMLColin', 'baseClass': gv.baseClass,
                     'elementName': 'colin', 'lo_class_name': 'SBMLDabs', 'attribs': attribs_after}
    run_strfunc_test(sf.prefix_classes, changing_dict, None, fails)  # Do not consume return value
    fail += compare_dictionaries(changing_dict, expected_dict, fails)


    # is_camel_case() tests
    data = {'FooParameter': True, 'fooParameter': True, 'fooparameter': False,
            'Fooparameter': False}
    fail += execute_tests(sf.is_camel_case, data, fails)

    ####################### Tests completed. #########################

    test_functions.report('strfunc', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()

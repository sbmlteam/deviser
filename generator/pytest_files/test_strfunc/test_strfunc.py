# Matthew S. Gillman, UCL, 31st March 2021.
import os
import pytest

from ...tests import test_functions
from ...tests.test_strfunc_code import run_strfunc_tests as rst
from ...util import strFunctions as sf, global_variables as gv

# The following are used in test_one_thing()
attribute1 = {'something': 'something else'}
attribute2 = {'type': 'element', 'element': 'ASTNode*', 'texname': 'tex'}
attribute3 = {'isListOf': True, 'name': 'Foo'}
attribute4 = {'type': 'element', 'element': 'Unit', 'texname': 'Unit'}
attribute5 = {'type': 'lo_element', 'element': 'Unit', 'texname': 'Unit'}
attribute6 = {'type': 'double', 'element': 'Unit', 'texname': 'Unit'}
attribute7 = {'isListOf': False, 'name': 'Foo'}
attribute8 = {'type': 'lo_element', 'element': 'Unit', 'name': 'Unit',
              'listOfClassName': 'ListOfAnything'}
attribute9 = {'type': 'lo_element', 'element': 'Unit',
              'name': 'FooUnit', 'isListOf': True}
attribute10 = {'type': 'lo_element', 'element': 'Unit', 'name': 'Unit',
               'isListOf': True, 'listOfClassName': 'ListOfUnits'}

# Please try and keep functions in same order as in the strFunctions.py file
# for ease of reference (and to see what is missing).
@pytest.mark.parametrize('func, input, expected_output, kwargs, do_first', [
    (sf.upper_first, 'cat', 'Cat', {}, ''),

    (sf.wrap_token, 'fred', '\\token{cat:\\-fred}', {'pkg': 'cat'}, ''),
    (sf.wrap_token, 'fred', '\\token{fred}', {}, ''),

    # TODO add test(s) for wrap_type()

    # TODO add test(s) for wrap_section()

    (sf.make_class, 'Irenaeus', 'irenaeus-class', {}, ''),
    (sf.make_class, 'Irenaeus', 'extended-irenaeus-class',
        {'add_extended': 'True'}, ''),

    (sf.wrap_enum, 'cat', '\\primtype{cat}', {}, ''),

    # get_element_name() tests
    (sf.get_element_name, attribute1, "FIX_ME", {},
        'gv.reset(); gv.prefix = "Bar"; gv.is_package = False'),
    (sf.get_element_name, attribute2, "MathML math", {}, ''),
    (sf.get_element_name, attribute3, "\\BarListOfFoos", {}, ''),
    (sf.get_element_name, attribute4, "Unit", {}, ''),
    (sf.get_element_name, attribute5, "\\BarListOfUnits", {}, ''),
    # (sf.get_element_name, attribute5, "\\ListOfUnits", {'add_prefix_if_not_pkg': 'False'}, ''),
    # (sf.get_element_name, attribute5, "\\ListOfUnits", {'leave_pkg_prefix': 'False'}, ''),
    (sf.get_element_name, attribute6, "FIX_ME", {}, ''),
    (sf.get_element_name, attribute7, "\\Foo", {}, ''),
    (sf.get_element_name, attribute8, "\\BarListOfUnits", {}, ''),
    # (sf.get_element_name, attribute8, "\\ListOfAnything", {'leave_pkg_prefix': 'False'}, ''),
    (sf.get_element_name, attribute9, "\\ListOfFooUnits", {},
        'gv.reset(); gv.prefix = "Bar"; gv.is_package = True; gv.package_prefix = "Foo"'),
    (sf.get_element_name, attribute9, "\\ListOfFooUnits",
        {'add_prefix_if_not_pkg': 'False'}, ''),
    (sf.get_element_name, attribute10, "\\ListOfUnits", {}, ''),
    (sf.get_element_name, attribute10, "\\ListOfUnits", {'leave_pkg_prefix': 'False'}, ''),
    (sf.get_element_name, attribute10, "\\ListOfUnits", {'add_prefix_if_not_pkg': 'False'}, ''),


    (sf.replace_digits, "John 3:16", "John Three:OneSix", {}, ''),

    (sf.texify, "012_27 cat44_8 ", "ZeroOneTwo\\_TwoSevencatFourFour\\_Eight", {}, ''),

    (sf.compare_no_case, "This iS a TEST", True, {"reference": "this is a test"}, ''),
    (sf.compare_no_case, "This iS a bad TEST", False, {"reference": "this is a test"}, ''),

    (sf.get_class_from_plugin, "CompModelPlugin", "Model", {"package": "Comp"}, ''),
    (sf.get_class_from_plugin, "CompModelPlug", "", {"package": "Comp"}, ''),
    (sf.get_class_from_plugin, "Plugin", "", {"package": "Comp"}, ''),

])
def test_one_thing(func, input, expected_output, kwargs, do_first):
    """
    Run a single test case on a strFunc function, and check that
    the actual output returned is the same as that expected.

    :param func: the strFunc function under test
    :param input: input to function
    :param expected_output: what we expect the function to return. Can be None.
    :param kwargs: dictionary of keyword arguments, if any, for the function
           under test.
    :param do_first: string of command(s) (separated by semi-colons)
           to be executed before running the test.
           Example: do_first = 'ans = 2 + 2; print(ans)'
    """
    #if kwargs:
    #    actual_output = func(input, **kwargs)
    #else:
    #    actual_output = func(input)
    if do_first:
        exec(do_first)
    actual_output = func(input, **kwargs)
    assert actual_output == expected_output


# I am placing these here, rather than in the fixture, so they can be easily
# re-used where required (and reduce unnecessary typing!).
# Each key is an input, and the corresponding value is the expected output.
# NB Those dictionaries which are only used once I have (mainly?) placed
# in the fixture itself.
catdat = {'cat': 'Cat', 'csgsomething': 'CSGsomething', 'csgcat': 'CSGcat',
            'cscat': 'Cscat', 'csgeometry': 'CSGeometry',
            'csGeometry': 'CSGeometry', 'a': 'A'}
foodat = {"FooParameter": "ListOfFooParameters"}
foxcatchild = {"fox": "listOfFoxes", "cat": "listOfCats",
             "child": "listOfChildren"}
foocat = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats"}
foosbmlcat = {"FooParameter": "SBMLListOfFooParameters", "cat": "SBMLListOfCats"}
foolistcat = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats",
            "SBMLFooParameter": "ListOfSBMLFooParameters"}
foolistcat2 = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats",
               "SBMLFooParameter": "ListOfFooParameters"}
plurals = {"fox": "foxes", "child": "children", "SBMLchild": "SBMLchildren"}
rosieplurals = {"RosieFox": "Foxes", "RosieChild": "Children",
                "RosieCat": "Cats", "Rosiefox": "Rosiefoxes"}
rosieplurals2 = {"Rosiefox": "Rosiefoxes", "Rosiechild": "Rosiechildren",
                 "RosieCat": "RosieCats"}
lots_of_plurals = {"cat": "cats", "dogs": "dogs", "child": "children",
                   "disinformation": "disinformation", "fox": "foxes",
                   "party": "parties", "cloud": "clouds",
                   "something": "somethings", "apple": "apples"}
fbc = {"FbcType": "Type", "FluxObjective": "FluxObjective",
       "FbcSBMLDocument": "FbcSBMLDocument"}
prefix_data = {"FbcType": "FbcType", "FluxObjective": "FluxObjective",
               "FbcSBMLDocument": "FbcSBMLDocument"}


# Please try and keep functions in same order as in the strFunctions.py file
# for ease of reference (and to see what is missing).
@pytest.mark.parametrize('func, test_data, kwargs, do_first', [
    (sf.upper_first, catdat, {}, ''),
    (sf.lower_first, rst.swap_dictionary(catdat), {}, ''),

    (sf.abbrev_name, {"thisIsATest": "iat", "CAT": "cat", "cat": "c", "c": "c", "C": "c"}, {}, ''),
    (sf.abbrev_lo_name, {"spaghetti": "", "ListOfFoo": "LOFoo", "ListOfFOO": "LOFOO"}, {}, ''),

    (sf.list_of_name, foodat, {'add_prefix': True}, 'gv.reset()'),
    (sf.list_of_name, foodat, {'add_prefix': False}, ''),
    (sf.list_of_name, foodat, {'add_prefix': False}, 'gv.is_package = False'),
    (sf.list_of_name, {"FooParameter": "SBMLListOfFooParameters"}, {'add_prefix': True}, ''),

    (sf.lower_list_of_name_no_prefix, foxcatchild, {}, 'gv.reset()'),
    (sf.lower_list_of_name_no_prefix, foxcatchild, {}, 'gv.is_package = False'),

    (sf.cap_list_of_name, foocat, {'add_prefix': False}, 'gv.reset()'),
    (sf.cap_list_of_name, foocat, {'add_prefix': True}, ''),
    (sf.cap_list_of_name, foocat, {'add_prefix': False}, 'gv.is_package = False'),
    (sf.cap_list_of_name, foosbmlcat, {'add_prefix': True}, ''),

    (sf.cap_list_of_name_no_prefix, foolistcat, {}, 'gv.reset()'),
    # The next one this wrongly dealt with by the remove prefix function: TODO FIXIT
    # (sf.cap_list_of_name_no_prefix, foolistcat2, {}, 'gv.is_package = False'),

    (sf.plural_no_prefix, plurals, {}, 'gv.reset()'),
    (sf.plural_no_prefix, rosieplurals, {}, 'gv.is_package = False; gv.prefix = "Rosie"'),
    (sf.plural_no_prefix, rosieplurals2, {}, 'gv.is_package = True'),

    (sf.plural, lots_of_plurals, {}, ''),

    (sf.singular, rst.swap_dictionary(lots_of_plurals), {}, 'test_data["dogs"] = "dog"'),

    # plural_then_single and vice versa here.
    # Keys = Values (inputs = expected outputs)
    # Dictionary comprehension: data = {k: k for k in ['cat', 'dog', 'bike']}
    (rst.plural_then_single,
       {k: k for k in ["cat", "dog", "child", "disinformation", "fox",
                       "party", "cloud", "something", "apple"]}, {}, ''),
    (rst.single_then_plural,
       {k: k for k in ["cats", "dogs", "children", "disinformation", "foxes",
                       "parties", "clouds", "somethings", "apples"]}, {}, ''),


    # Lots of remove_prefix() tests - this is a complicated function to test!
    # tests removing a package prefix. gv.reset() sets gv.prefix to "SBML"
    (sf.remove_prefix, fbc, {},
            'gv.reset(); gv.is_package = True; gv.package_prefix = "Fbc"'),
    (sf.remove_prefix, fbc, {'remove_package': True}, ''),
    (sf.remove_prefix, {"FbcSBMLDocument": "SBMLDocument"},
         {'remove_doc_prefix': True}, ''),
    (sf.remove_prefix, fbc, {'prefix': 'Fbc'},
        'gv.reset(); gv.is_package = True; gv.package_prefix = ""'),
    # No prefix to remove has been specified or explicitly told not to remove:
    (sf.remove_prefix, prefix_data, {'prefix': ''}, ''),
    (sf.remove_prefix, prefix_data, {'prefix': 'Fbc', 'remove_package': False}, ''),
    (sf.remove_prefix, prefix_data, {'remove_doc_prefix': True}, ''),
    (sf.remove_prefix, prefix_data, {'prefix': '', 'remove_doc_prefix': True, }, ''),
    (sf.remove_prefix, prefix_data, {'prefix': 'Fbc', 'remove_doc_prefix': False, 'remove_package': False}, ''),
    (sf.remove_prefix, {"FbcSBMLDocument": "SBMLDocument"}, {'prefix': 'Fbc', 'remove_doc_prefix': True}, ''),
    (sf.remove_prefix, {"RosieFbcType": "FbcType", "RosieDocument": "RosieDocument"},
             {'prefix': 'Rosie'}, 'gv.reset(); gv.prefix = "Rosie"; gv.is_package = False'),
    (sf.remove_prefix, {"RosieFbcType": "FbcType", "RosieDocument": "Document"},
             {'prefix': 'Rosie', 'remove_doc_prefix': True}, ''),

    (sf.is_prefixed_name, {"RosieFox": True, "rosieFoo": True, "rosiefoo": False,
            "RosiFox": False, "RoSiEFoo": True, "RoSiEfoo": False},
            {'prefix': 'Rosie'}, 'gv.reset()'),  # gv.reset() means gv.prefix is now "SBML"

    (sf.is_prefixed_document_class,
        {"RosieDocument": True, "rosieDocument": True,
         "rosiedocument": False, "RosiDocument": False,
         "RoSiEDocument": True, "RoSiEDocment": False},
        {'prefix': 'Rosie'}, ''),

    (sf.get_indefinite,
        {"apple": "an", "biscuit": "a", "elephant": "an", "image": "an",
         "polar bear": "a", "orangutan": "an", "under secretary": "an",
         "zither": "a"}, {}, ''),

    (sf.standard_element_name,
        {"listOfFoxes,": "Fox", "ListOfApples": "Apple",
         "XMLNode*": "XMLNode", "Rosie,": "Rosie", "rosie,": "Rosie",
         "name_t": "Name", "Name": "Name", "name": "Name"}, {}, ''),

    (sf.get_library_suffix,
        {"library": "Rary", "libSBML": "Sbml", "cat": "Cat", "lib": ""},
        {}, ''),

    (sf.get_sid_refs,
        {'': ['', 'SId'], 'cat': ['Cat', 'Cat'],
         'csgsomething': ['CSGsomething', 'CSGsomething'],
         'cat,dog': ["Cat or \\Dog", "CatOrDog"]},
        {}, ''),

    (sf.replace_underscore,
        {"this_is_a_test": "this\\_is\\_a\\_test", "cat": "cat", "_": "\\_"},
        {}, ''),

    (sf.remove_spaces,
        {"   hello   world  ": "helloworld", "dogfish": "dogfish"},
        {}, ''),

    (sf.remove_hyphens,
        {"this-is-a-test": ["thisIsATest", True], "cat": ["cat", False],
         "cat-": ["cat", True], "-cat": ["Cat", True]},
        {}, ''),

    (sf.prefix_name,
        {"DABS": "DABS", "DABSCAT": "DABSCAT", "dabs": "DABSdabs",
         "SBase": "DABSBase", "XMLNode": "XMLNode",
         "XMLNodeAgain": "DABSXMLNodeAgain", "ASTNode": "ASTNode"},
        {}, 'gv.reset(); gv.prefix = "DABS"'),



    # TODO add tests for sf.prefix_classes - uses compare_dictionaries()


    (sf.is_camel_case,
        {'FooParameter': True, 'fooParameter': True, 'fooparameter': False,
         'Fooparameter': False},
        {}, ''),


])
def test_many_things(func, test_data, kwargs, do_first):
    """
    Execute a set of individual tests on a strFunc function.

    :param func: the function under test
    :param test_data: dictionary of test data
                      (keys=inputs, values=expected outputs)
    :param kwargs: dictionary of any named arguments for the function
    :param do_first: string of command(s) (separated by semi-colons)
           to be executed before running the test.
           Example: do_first = 'ans = 2 + 2; print(ans)'
    """
    if do_first:
        exec(do_first)
    for (input, expected) in test_data.items():
        actual_output = func(input, **kwargs)
        assert actual_output == expected


# TODO add tests which use compare_dictionaries()
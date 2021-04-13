# Matthew S. Gillman, UCL, 31st March 2021.
import os
import pytest

from ...tests import test_functions
from ...tests.test_strfunc_code import run_strfunc_tests as rst
from ...util import strFunctions as sf, global_variables as gv


# Please try and keep functions in same order as in the strFunctions.py file
# for ease of reference (and to see what is missing).
@pytest.mark.parametrize('func, input, expected_output, kwargs', [
    (sf.upper_first, 'cat', 'Cat', {}),
])
def test_one_thing(func, input, expected_output, kwargs):
    """
    Run a single test case on a strFunc function, and check that
    the actual output returned is the same as that expected.

    :param func: the strFunc function under test
    :param input: input to function
    :param expected_output: what we expect the function to return. Can be None.
    :param kwargs: dictionary of keyword arguments, if any, for the function
               under test.
    """
    #if kwargs:
    #    actual_output = func(input, **kwargs)
    #else:
    #    actual_output = func(input)
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


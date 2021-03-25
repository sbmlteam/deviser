To run all tests, you can execute the general run-tests.py program.

You need to go into its "grandfather" directory, ../.. (i.e. Deviser/deviser/),
and invoke this command:

    python -m generator.tests.run-tests

If you wish to execute a specific subset of tests, e.g. test_cpp_code/run_cpp_tests.py,
you can comment out all other test subdirs in run-tests.py, then run that. This is not
ideal, but is a result of the new relative import directives which have removed the
need for horrible lines such as

    sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')

etc.

This is all part of our move to using pytest to run our tests.

To run tests in this directory, you may need to copy

    Deviser/deviser/generator/pytest_files/test_xml_files/

into this current directory (Deviser/deviser/generator/tests/)




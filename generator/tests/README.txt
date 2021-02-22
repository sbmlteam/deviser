To run all tests, you can execute the general run-tests.py program. It should be
possible to run this wherever you are in the file system. 

If you wish to execute a specific subset of tests, e.g. test_cpp_code/run_cpp_tests.py,
you can either (a) comment out all other test subdirs in run-tests.py, then run that,
or (b) cd into the subdir concerned, e.g. test_cpp_code, and run the relevant script
therein, e.g. run_cpp_tests.py

If you try to run one of the subdir tests (such as run_cpp_tests.py) directly, from anywhere
other than the directory in which it is located, it will not be able to find the reference
and test-generated files for comparison, due to the file paths being wrong. Running the 
general run-tests.py does not have this problem, as it works out where it is located via a 
call:
    this_dir = os.path.dirname(os.path.abspath(__file__))


 Instructions for running pytest tests
=====================================

The following are the steps I took.

```
> pip3 uninstall pytest
> python3 -m venv cbl-env
> source cbl-env/bin/activate
> pip install pytest
> pytest
```

This will run all tests. Note that the default Python version is now 3.x.

You can also just run a subset of the tests, e.g.

```
> pytest test_cmake test_exit_codes 
```

It is still possible to run the old testing framework under Python 3. Refer to the README file therein for details.
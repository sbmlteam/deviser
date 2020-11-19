## Instructions for using Sphinx with the deviser code.
#### Matthew Gillman, 17th November 2020.

These are the steps to do everything from scratch.
In practice, once items such as `conf.py` are added to git, it will be simpler than this.
So please read to the end before you try running anything.

Check `sphinx-apidoc` is installed. [Installation instructions](https://www.sphinx-doc.org/en/master/usage/installation.html)

Run `sphinx-apidoc --help` for options  

[I originally tried running this in the top-level Deviser directory, to pick up the files such as FUNDING.txt, but it
didn't add them in. There is probably a way to do this - TODO add top-level files into Sphinx docs.]
 
Start in `Deviser/deviser` directory. 
So this next command will only pick up those files in `Deviser/deviser/generator` directory: 
 
`$ sphinx-apidoc -n -o sphinx-docs -e -M -F --ext-autodoc --ext-doctest --ext-coverage  
--ext-githubpages generator '*tests*'`  
 
The `–n` option means this is a dry-run, to see what will be produced. 
You can then remove the –n option when you want to begin.
Here, the output directory (for .rst files) is `Deviser/deviser/sphinx-docs`
We may not need all the extensions listed (run `sphinx-apidoc --help` for what they do.)
The `-e` option creates separate a HTML file for each module (`.py` file), rather than
one enormous one.
The trailing `'*tests*'` is an exclude option; it means we don't generate documentation
for files matching this pattern.

[It's possible a couple of options above may not be needed, perhaps the `-M` and `-F` ones?]
 
Now `cd` into `Deviser/deviser/sphinx-docs`.

There should be a file `conf.py` there, along with lots of `.rst` files with names like
`generator.validation.RNGSchemaFiles.rst`. 
 
Edit file `conf.py`: 
```
import sys 
sys.path.insert(0, '..') 
sys.path.insert(0, '../generator')
```
Give values for Authors, Copyright (in quotes)

### Changing to a nicer theme (optional step) 
The default theme for Sphinx is alabaster. That's OK, but we can get
nicer-looking documents with the sphinx_rtd_theme theme instead.

`$ pip install sphinx_rtd_theme` 

And in `conf.py` change line 
`html_theme = 'alabaster'` 
To  
`html_theme = 'sphinx_rtd_theme'` 
 
And add it into the extensions list in `conf.py` 
i.e.
``` 
extensions = [ 
    'sphinx.ext.autodoc', 
    'sphinx.ext.viewcode', 
    ...
    'sphinx_rtd_theme',   # Add this line.
]
```

And add `import sphinx_rtd_theme` near top of `conf.py`. 
 
[NB python2 doesn’t allow virtual environments (`python –m venv myenv`)
for local install of `sphinx-apidoc`, etc.] 


### Building the HTML pages.
 
Now in `deviser/sphinx-docs`, execute the command  
 
`make html BUILDDIR="../sphinx-html"`
 
Note the quotes. 
 
This will build the html docs and put them in `deviser/sphinx-html/html` 
 
[NB if the `'*tests*'` exclude option is *not* used, the build attempt will
encounter  circular import errors, as here:
```
reading sources... [100%] generator.tests.test_examples.run_examples_tests                                                               
WARNING: autodoc: failed to import module 'test_examples' from module 'generator.tests'; the following exception was raised: 
cannot import name 'run_tex_tests' from partially initialized module 'generator.tests.test_examples' (most likely due to a circular import) (../generator/tests/test_examples/__init__.py) 
WARNING: autodoc: failed to import module 'test_examples.run_examples_tests' from module 'generator.tests'; the following exception was raised: 
cannot import name 'run_tex_tests' from partially initialized module 'generator.tests.test_examples' (most likely due to a circular import) (../generator/tests/test_examples/__init__.py) 
```
I am just leaving this here for the sake of completeness.]

You can then start an HTTP server (via command `python -m http.server`) 
and navigate to the `index.html` file therein. 

We don't really want to add the `.rst` and `.html` files to git, as we can always
regenerate them.

### Re-building
If you make a change to the docs in your Python code, the relevant `.rst` and `.html` files
will need to be re-built. In this case the `-f` option will need to be added to the 
`sphinx-apidoc` command, to force it to overwrite the existing `.rst` file(s). And the
`make html` command will then need to be re-run, too.

### Building once a lot of the above is in git
The `.rst` and `.html` files should not be in git, as we can always regenerate them.
So you may find that the `sphinx-docs/conf.py` already exists. Edit if required and then
proceed to `sphinx-apidoc` and `make html` steps.

### Further enhancements
If you don't want to display fully-qualified domain names of classes,
e.g. you want to say "class C" rather than "class A.B.C", add the following
line to `conf.py`:
 `add_module_names = False`
Then the module name at the top of the page will still be in A.B format,
but the individual classes in that module (.py file) will appear in
the form "class C".
 
Another possible change is if you want to add more document types to the
Sphinx build. For example, you could add this to `conf.py`:
```
source_suffix = {
'.rst': 'restructuredtext',
'.txt': 'restructuredtext',
'.md': 'markdown',
}``` 
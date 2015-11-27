
Using Deviser
=============

The Deviser Edit tool allows you to specify the details of an SBML L3
Package. In addition it can be used to perform a number of tasks
directly. Some of these require additional software on your system and
Deviser Edit needs to be given the information about where to find
these. This is described in Section 1.3.

View UML diagrams.
------------------

Once you have specified at least one class you can click on the **Show
UML** button on the toolbar or select **Show UML** from the Tool menu.
Remember that this uses the yUML webservice and so will only work if you
have an internet connection.

The UML output will appear (Figure :num:`fig-yuml`). Note that each time this option
is selected a new diagram is generated from the definition; the more
complex the definition the longer it will take.

.. _fig-yuml:
.. figure:: ../screenshots/deviser-yuml.png

     The UML window

You will note that not all inheritance is determined. Deviser does not
try to infer inheritance of classes from outside this package
definition. However these can be added using the **Edit** window (Figure
:num:`fig-yuml-edit`).

.. _fig-yuml-edit:
.. figure:: ../screenshots/deviser-yuml-edit.png

     The yUML text representation of the diagram

The **Edit** tab allows access to the text format of the diagram which
can be edited and updated. Note the update applies to the UML diagram
only, not the defined package.

The **Update** button will update the diagram in line with any changes
that have been made to the text description on the Edit panel.

The **SaveAs** button allows the user to navigate to a location of their
choice and save the diagram in a graphic format. PNG, JPG, PDF, SVG and
yUML are all supported.

There is a selection box and two check boxes that allow the user to
change the format of the diagram. These are left for the user to
experiment with.

Generate libSBML package code.
------------------------------

Click on the ‘Generate’ button on the toolbar and the Generate window
(Figure :num:`fig-generate`) will appear.

The **Generate Package Code** button will then create the package code
and put it in a directory name ‘foo’ (i.e. the name of the package) in
the specified output directory. This code can then be archived and
expanded over the libSBML source tree.

.. _fig-generate:
.. figure:: ../screenshots/deviser-generate.png

     The Generate window

Generate basic specification documentation.
-------------------------------------------

In the Generate window there is a **LaTeX Generation** tab with two
further buttons.

The **Generate Latex** button will generate three TeX files.

-  body.tex describing each class and its attributes with their types
   and cardinalities.

-  apdx-validation.tex listing the validation rules.

-  macros.tex listing the classes and creating commands for
   cross-referencing

The **Compile TeX** button takes the generated TeX files, creates
another main.tex based on the sbmlpkgspec requirements and generates a
basic specification document as a pdf.

Integrate and test the package with libSBML.
--------------------------------------------

Click the **Integration and Testing** tab in the Generate window and a
further set of buttons are revealed (Figure :num:`fig-integrate`).

.. _fig-integrate:
.. figure:: ../screenshots/deviser-integrate.png

Figure Integration and Testing tab selected on the Generate window.

**Compile Dependencies** compiles the dependencies with the specified
C++ compiler to ensure that these are compatible with the libSBML build.

**Add Code to Source Dir** places the code generated for package foo
within the libSBML source tree.

**Remove Code from Source Dir** removes the code generated for package
foo from the libSBML source tree.

**Compile libSBML with package** enables package foo within the libSBML
build and runs the build.

**Run libSBML** **Python** **session** (Windows only) starts an
interactive python session with the package loaded to facilitate to
manual testing of the code.

Command line
------------

The command line function deviser.py can be invoked directly.

deviser.py [--generate][--latex] input-file.xml

This program takes as input a Deviser XML file and either

-  --generate (-g) generates the libSBML code for the package

    This generates the complete src package that can be zipped and then
    unzipped over an existing libSBML src tree.

-  --latex (-l) generates a LaTeX scaffold for its specification.

    This generates the adx-validation.tex, macros.tex and body.tex files
    which can then be integrated into a package pdf using the
    sbmlpkgspec files.

Generation of a pdf or integration with libSBML can then be done
manually.


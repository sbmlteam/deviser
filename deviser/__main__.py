import sys

from deviser.util import  generateCode, generateLatex, global_variables as gv

def generatePackageFor(filename):
    """This function generates a libSBML extension for the given filename

    From the manual:
    Deviser allows a user to define an SBML Level 3 (L3) package and produce
    libSBML code that can be integrated with the existing libSBML source tree
    to add libSBML support for the package.
    """
    generateCode.generate_code_for(filename, True)


def generateLaTeXFor(filename):
    """This function generates a LaTeX scaffold for the given filename

    From the manual:
    Deviser can also use the package description to create basic specification
    files for the package based on the LaTeX style SBMLPkgSpec for
    SBML Level 3 package documentation.
    """
    generateLatex.generateLatexFor(filename)


def run_generation(args):
    """Usage: deviser  [--generate | --latex ] input-filename output-dir

       This program will use a Deviser xml file, and generate either a C++
       libSBML extension for it, or generate a LaTeX scaffold for its
       specification.
    """

    # reset the global return code as this is a new call to deviser
    gv.code_returned = gv.return_codes['success']

    num_args = len(args)

    if num_args < 3 or  num_args > 4:
        gv.code_returned = gv.return_codes['incorrect number function arguments']
        print(run_generation.__doc__)


    if gv.code_returned == gv.return_codes['success']:

        operation = args[1].lower()
        filename = args[2]

        if operation == '--generate' or operation == '-g':
            generatePackageFor(filename)
        elif operation == '--latex' or operation == '-l':
            generateLaTeXFor(filename)
        else:
            gv.code_returned = gv.return_codes['invalid function arguments']
            print(run_generation.__doc__)

    return gv.code_returned


def main(args):
    return run_generation(args)

if __name__ == '__main__':
    if gv.code_returned == gv.return_codes['success']:
        try:
            main(sys.argv)
            sys.exit(gv.code_returned)
        except Exception as ex:
            print('\nAn exception was raised while running deviser: \"{}\"'.format(ex))
            sys.exit(gv.code_returned)
    else:
        sys.exit(gv.code_returned)

import sys

from deviser.util import global_variables as gv
from deviser import generateLaTeXFor, generatePackageFor


def main(args):
    """Usage: deviser  [--generate | --latex ] input-filename

       This program will use a Deviser xml file, and generate either a C++
       libSBML extension for it, or generate a LaTeX scaffold for its
       specification.
    """

    # reset the global return code as this is a new call to deviser
    gv.code_returned = gv.return_codes['success']

    if len(args) != 3:  # TODO: there could also be too many args (>3)!
        gv.code_returned = gv.return_codes['missing function argument']
        print(main.__doc__)

    if gv.code_returned == gv.return_codes['success']:

        operation = args[1].lower()
        filename = args[2]

        if operation == '--generate' or operation == '-g':
            generatePackageFor(filename)
        elif operation == '--latex' or operation == '-l':
            generateLaTeXFor(filename)
        else:
            gv.code_returned = gv.return_codes['invalid function arguments']
            print(main.__doc__)

    return gv.code_returned


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

#!/usr/bin/env python

from parseXML import createPackageFromXml
from code_files import CppFiles


def generate_cpp_header(filename, num):
    ob = createPackageFromXml.parse_deviser_xml(filename)
    working_class = ob['sbmlElements'][num]
    all_files = CppFiles.CppFiles(working_class)
    all_files.write_files()


# reads file containing expected sbml model and returns it as string
def read_file(path):
    filein = open(path, 'r')
    contents = filein.read()
    filein.close()
    return contents


def compare_files(infile, outfile):
    indata = read_file(infile)
    out = read_file(outfile)
    print (infile)
    assert indata.strip() == out.strip()


def main():
    filename = 'C:\Development\git\deviser\samples\qual.xml'

    generate_cpp_header(filename, 3)

    my_file = '.\\test-code\\Output.h'
    new_file = 'Output.h'

    compare_files(my_file, new_file)

    my_file = '.\\test-code\\ListOfOutputs.h'
    new_file = 'ListOfOutputs.h'

    compare_files(my_file, new_file)

    generate_cpp_header(filename, 1)

    my_file = '.\\test-code\\Transition.h'
    new_file = 'Transition.h'

    compare_files(my_file, new_file)

    my_file = '.\\test-code\\ListOfTransitions.h'
    new_file = 'ListOfTransitions.h'

    compare_files(my_file, new_file)

if __name__ == '__main__':
    main()

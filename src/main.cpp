// File: main.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#include "slicing_tree.hpp"

int main(int argc, char** argv)
{
    slicing_tree test;
    test.import_module_list("input_file.txt");
    test.display_module_list();
    test.create_tree("12H3H4H5H6H");
    test.display_tree();
    return 0;
}

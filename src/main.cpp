// File: main.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#include "slicing_tree.hpp"

int main(int argc, char** argv)
{
    slicing_tree test;
    test.import_module_list("input_file.txt");
    //test.display_module_list();
    test.create_tree("213546H7VHVa8V9HcVHgHibdHkVHfeHVHlHVjHVH");
    test.display_tree();
    test.display_tree_post_order();
    return 0;
}

// File: main.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#include "slicing_tree.hpp"

int main(int argc, char** argv)
{
    std::string NPEa = "12H3H4H5H6H7H8H9HaHbHcHdHeHfHgHiHjHkHlH";
    std::string NPEb = "12V3V4V5V6V7V8V9VaVbVcVdVeVfVgViVjVkVlV";
    std::string NPEc = "21356H7VHVa8V9HcVHgHibdHkVHfeHVlHVjHVH";
    std::string test_NPE = "12H3H4H5H6H";
    slicing_tree test1;
    test1.import_module_list("input_file.txt");
    test1.display_module_list();
    double cost = test1.cost(NPEc);
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "NPE: " << NPEc << std::endl;
    std::cout << "cost: " << cost << std::endl;
    test1.display_tree_dimensions();
    test1.display_tree();
    return 0;
}

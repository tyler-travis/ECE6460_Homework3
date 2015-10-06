// File: slicing_tree.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#include "slicing_tree.hpp"

slicing_tree::slicing_tree()
{
    root = 0;
}

void slicing_tree::create_tree(std::string _NPE)
{
    NPE = _NPE;
    root = new operator_node(_NPE[_NPE.size()-1]);
}

void slicing_tree::import_module_list(std::string input_file)
{
    std::ifstream fin(input_file.c_str());
    std::string temp_name;
    double temp_area;
    double temp_aspect_ratio;
    while(fin >> temp_name)
    {
        fin >> temp_area;
        fin >> temp_aspect_ratio;
        module_list.push_back(module(temp_name, temp_area, temp_aspect_ratio));
    }
}


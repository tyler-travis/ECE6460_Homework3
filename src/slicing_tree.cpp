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
    create_tree(root, _NPE, _NPE.size() - 1);
}

int slicing_tree::create_tree(node* current_node, std::string _NPE, int index)
{
    if(index == -1)
    {
        return -1;
    }
    if(NPE[index] == 'H')
    {
        current_node = new operator_node("H");
        index = create_tree(current_node->get_right(), _NPE, index-1);
        index = create_tree(current_node->get_left(), _NPE, index-1);
        return index;
    }
    else if(NPE[index] == 'V')
    {
        current_node = new operator_node("V");
        index = create_tree(current_node->get_right(), _NPE, index-1);
        index = create_tree(current_node->get_left(), _NPE, index-1);
        return index;
    }
    else
    {
        for(unsigned int i = 0; i < module_list.size(); ++i)
        {
            if(module_list[i].get_name() == std::string(1,_NPE[index]))
            {
                current_node = new operand_node(module_list[i].get_name(), module_list[i].get_area(), module_list[i].get_aspect_ratio());
                current_node->set_left(0);
                current_node->set_right(0);
                

                return index;
            }
        }
    }
    std::cout << "Something weird happened, make sure the moduels have the same name as in the NPE" << std::endl;
    return -1;
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

void slicing_tree::display_module_list()
{
    for(unsigned int i = 0; i < module_list.size(); ++i)
    {
        std::cout << module_list[i].get_name() << "\t"
            << module_list[i].get_area() << "\t"
            << module_list[i].get_aspect_ratio() << std::endl;
    }
}

void slicing_tree::display_tree()
{
    display_tree(root, 0);
}

void slicing_tree::display_tree(node* current_node, int space)
{
    if(current_node != 0)
    {
        if(current_node->get_right())
        {
            display_tree(current_node->get_right(), space+4);
        }
        for(int i = 0; i < space; ++i)
        {
            std::cout << " ";
        }
        std::cout << current_node->get_name() << std::endl;
        if(current_node->get_left())
        {
            display_tree(current_node->get_left(), space+4);
        }
    }
}

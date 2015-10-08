// File: slicing_tree.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#include "slicing_tree.hpp"

slicing_tree::slicing_tree()
{
    root = new node();
}

void slicing_tree::create_tree(std::string _NPE)
{
    NPE = _NPE;
    create_tree(root, _NPE, _NPE.size() - 1);
}

int slicing_tree::create_tree(node* current_node, std::string _NPE, int index)
{
    std::string name(1, _NPE[index]);
    //std::cout << "Current Position in NPE: " << index << std::endl;
    //std::cout << "Current Node to look at: " << name << std::endl << std::endl;
    if(name == "H" || name == "V")
    {
        *current_node = operator_node(name);
        if(root == 0)
        {
            root = current_node;
        }
        current_node->set_right(new node);
        current_node->set_left(new node);
        index = create_tree(current_node->get_right(), _NPE, index-1);
        current_node->get_right()->set_parent(current_node);
        index = create_tree(current_node->get_left(), _NPE, index-1);
        current_node->get_left()->set_parent(current_node);
        return index;
    }
    else
    {
        for(unsigned int i = 0; i < module_list.size(); ++i)
        {
            if(module_list[i].get_name() == name)
            {
                *current_node = operand_node(module_list[i].get_name(), 
                        module_list[i].get_aspect_ratio(), module_list[i].get_area());
                return index;
            }
        }
    }
    return 0;
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
    std::cout << "M O D U L E    L I S T" << std::endl;
    for(unsigned int i = 0; i < module_list.size(); ++i)
    {
        std::cout << module_list[i].get_name() << "\t"
            << module_list[i].get_area() << "\t"
            << module_list[i].get_aspect_ratio() << "\t"
            << sqrt(module_list[i].get_area()/module_list[i].get_aspect_ratio()) << " x "
            << sqrt(module_list[i].get_area()/module_list[i].get_aspect_ratio()) * module_list[i].get_aspect_ratio()
            << std::endl;
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

void slicing_tree::display_tree_post_order()
{
   display_tree_post_order(root); 
   std::cout << std::endl;
}

void slicing_tree::display_tree_post_order(node* current_node)
{
    if(current_node == 0)
    {
        return;
    }
    
    display_tree_post_order(current_node->get_left());
    display_tree_post_order(current_node->get_right());
    std::cout << current_node->get_name();
}

void slicing_tree::display_tree_dimensions()
{
    display_tree_dimensions(root);
}

void slicing_tree::display_tree_dimensions(node* current_node)
{
    if(current_node == 0)
    {
        return;
    }
    
    display_tree_dimensions(current_node->get_left());
    display_tree_dimensions(current_node->get_right());
    std::cout << current_node->get_name();
    std::cout << ": ";
    for(unsigned int i = 0; i < current_node->get_dimension_list().size(); ++i)
    {
        std::cout << "(" <<  current_node->get_dimension_list()[i].first << " x "
            << current_node->get_dimension_list()[i].second
            << "), ";
    }
    std::cout << std::endl << "------------------------------------------------------------------------------------------------" << std::endl;
}

double slicing_tree::cost(std::string _NPE)
{
    create_tree(_NPE);
    populate_dimension_lists();
    dimension_list root_list = root->get_dimension_list();
    double minimum_area = root_list[0].first * root_list[0].second;
    double area;
    for(unsigned int i = 0; i < root_list.size(); ++i)
    {
        area = root_list[i].first * root_list[i].second;
        if(area < minimum_area)
        {
            minimum_area = area;
        }
    }
    return area;
}

void slicing_tree::populate_dimension_lists()
{
    populate_dimension_lists(root);
}

dimension_list slicing_tree::populate_dimension_lists(node* current_node)
{
    if(current_node->get_name() != "V" && current_node->get_name() != "H")
    {
        return current_node->get_dimension_list();
    }
    else
    {
        double total_width, total_length;
        dimension_list current_dimension_list_right = populate_dimension_lists(current_node->get_right());
        dimension_list current_dimension_list_left = populate_dimension_lists(current_node->get_left());
        dimension_list current_dimension_list_final;
        if(current_node->get_name() == "V")
        {
            for(unsigned int i = 0; i < current_dimension_list_right.size(); ++i)
            {
                for(unsigned int j = 0; j < current_dimension_list_left.size(); ++j)
                {
                    total_width = current_dimension_list_right[i].first + current_dimension_list_left[j].first;
                    total_length = std::max(current_dimension_list_right[i].second, current_dimension_list_left[j].second);
                    current_dimension_list_final.push_back(std::pair<double, double>(total_width, total_length));
                }
            }
        }
        else
        {
            for(unsigned int i = 0; i < current_dimension_list_right.size(); ++i)
            {
                for(unsigned int j = 0; j < current_dimension_list_left.size(); ++j)
                {
                    total_length = current_dimension_list_right[i].second + current_dimension_list_left[j].second;
                    total_width = std::max(current_dimension_list_right[i].first, current_dimension_list_left[j].first);
                    current_dimension_list_final.push_back(std::pair<double, double>(total_width, total_length));
                }
            }
        }
        std::cout << "-----------------------------\n";
        std::cout << "Size: " << current_dimension_list_final.size() << std::endl;
        //std::cout << "Current Node: " << current_node->get_name() << std::endl;
        current_dimension_list_final = delete_maximums(current_dimension_list_final);
        std::cout << "Size: " << current_dimension_list_final.size() << std::endl;
        for(unsigned int i = 0; i < current_dimension_list_final.size(); ++i)
        {
            //std::cout << current_dimension_list_final[i].first << " x " << current_dimension_list_final[i].second << std::endl;
            current_node->set_dimension_list(current_dimension_list_final);
        }
        //std::cout << std::endl;
        return current_dimension_list_final;
    }
}

dimension_list slicing_tree::delete_maximums(dimension_list list)
{
    std::vector<unsigned int> indices_to_delete;
    for(unsigned int i = 0; i < list.size(); ++i)
    {
        for(unsigned int j = 0; j < list.size(); ++j)
        {
            if(i == j)
            {
                continue;
            }
            else if(list[i].first == list[j].first && list[i].second == list[j].second)
            {
                continue;
            }
            else
            {
                if(list[i].first <= list[j].first && list[i].second <= list[j].second)
                {
                    std::cout << "Deleting: " << list[j].first << " x " << list[j].second << std::endl;
                    indices_to_delete.push_back(j);
                }
            }
        }
    }
    std::sort(indices_to_delete.begin(), indices_to_delete.end());
    std::vector<unsigned int>::iterator it;
    it = std::unique(indices_to_delete.begin(), indices_to_delete.end());
    indices_to_delete.resize(std::distance(indices_to_delete.begin(), it));
    for(unsigned int i = 0; i < indices_to_delete.size(); ++i)
    {
        list.erase(list.begin() + indices_to_delete[i]-i);
    }
    return list;
}

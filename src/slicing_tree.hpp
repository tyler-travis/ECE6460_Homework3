// File: slicing_tree.hpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#ifndef SLICING_TREE_HPP
#define SLICING_TREE_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>

#include "module.hpp"
#include "node.hpp"
#include "operand_node.hpp"
#include "operator_node.hpp"


class slicing_tree
{
    private:
        node* root;
        std::vector<module> module_list;
        std::string NPE;

        int create_tree(node*, std::string, int);
        void display_tree(node*, int);
        void display_tree_post_order(node*);

    public:
        slicing_tree();
        void create_tree(std::string);
        void import_module_list(std::string);
        double cost(std::string);
        double cost();
        void display_module_list();
        void display_tree();
        void display_tree_post_order();
};

#endif

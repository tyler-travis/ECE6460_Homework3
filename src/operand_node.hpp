// File: operand_node.hpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#ifndef OPERAND_NODE_HPP
#define OPERAND_NODE_HPP

#include "node.hpp"
#include <string>

class operand_node: public node
{
    private:
        std::string name;
};

#endif

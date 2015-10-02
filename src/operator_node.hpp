// File: operator_node.hpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#ifndef OPERATOR_NODE_HPP
#define OPERATOR_NODE_HPP

#include "node.hpp"
#include <string>

class operator_node: public node
{
    private:
        std::string operators;
};

#endif


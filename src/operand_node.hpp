// File: operand_node.hpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#ifndef OPERAND_NODE_HPP
#define OPERAND_NODE_HPP

#include "node.hpp"
#include <string>
#include <cmath>

class operand_node: public node
{
    private:
        // name can be 1,2,3,...,9,a,b,c,...,x,y,z
        // not include h or v.
        std::string name;
        double aspect_ratio;
        double area;
        double length;
        double width;

    public:
        operand_node();
        operand_node(std::string, double, double);
};

#endif

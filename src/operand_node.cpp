// File: operand_node.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#include "operand_node.hpp"


operand_node::operand_node()
{
    aspect_ratio = 0;
    area = 0;
    length = 0;
    width = 0;
}

operand_node::operand_node(std::string _op, double _aspect_ratio, double _area)
{
    aspect_ratio = _aspect_ratio;
    area = _area;
    length = sqrt(area/aspect_ratio);
    width = aspect_ratio*length;
}


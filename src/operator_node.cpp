// File: operator_node.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#include "operator_node.hpp"


operator_node::operator_node()
    : node()
{

}
operator_node::operator_node(std::string _op)
    : node()
{
    name = _op;
}

void operator_node::set_dimension_list(std::vector<std::pair<double, double> > list)
{
    v_dimensions = list;
}

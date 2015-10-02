// File: node.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

node::node()
{
    p_right = nullptr;
    p_left = nullptr;
    p_parent = nullptr;
    v_dimensions = new std::vector<std::pair<double,double>>();
}

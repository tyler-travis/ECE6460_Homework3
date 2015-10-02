// File: node.cpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#include "node.hpp"

node::node()
{
    p_right = nullptr;
    p_left = nullptr;
    p_parent = nullptr;
    v_dimensions = new std::vector<std::pair<double,double>>();
}
// Set the left pointer
void set_left(node* _p_left)
{
    p_left = _p_left;
}

// Set the right pointer
void node::set_right(node* _p_right)
{
    p_right = _p_right
}

// Set the parent pointer
void node::set_parent(node* _p_parent)
{
    p_parent = _p_parent;
}

// Put a new dimension into the dimension array
void node::set_dimension(std::pair<double, double> _dimension)
{
    dimensions.push_back(_dimension);
}

// Get the left pointer
node* node::get_left()
{
    return p_left;
}

// Get the right pointer
node* node::get_right()
{
    return p_right;
}

// Get the parent pointer
node* node::get_parent()
{
    return p_parent;
}

// Get the dimension at a certain index
std::pair<double, double>> node::get_dimension(int _index)
{
    return dimensions[_index];
}

bool node::remove_dimension(int _index)
{
    if (_index > dimensions.size())
    {
        return false;
    }
    // Delete the element at the beginning + the index
    // Effectively like: dimensions.delete(_index);
    dimensions.erase(dimensions.begin() + _index);
    return true;
}


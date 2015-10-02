// File: node.hpp
// Author: Tyler Travis
// A#: A01519795
// Homework 3

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <pair>

class node
{
    protected:
        // Pointer to left child
        node* p_left;

        // Pointer to right child
        node* p_right;

        // Pointer to the parent
        node* p_parent;

        // vector for storing possible dimension orientations
        std::vector<std::pair<double, double>> v_dimensions;

    public:
        // Default constructor
        node();

        // Set the left pointer
        void set_left(node*);

        // Set the right pointer
        void set_right(node*);

        // Set the parent pointer
        void set_parent(node*);

        // Put a new dimension into the dimension array
        void set_dimension(std::pair<double, double>);

        // Get the left pointer
        node* get_left();

        // Get the right pointer
        node* get_right();

        // Get the parent pointer
        node* get_parent();

        // Get the dimension at a certain index
        std::pair<double, double>> get_dimension(int);
};

#endif

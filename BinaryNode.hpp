/*
Author: Grant Hughes
Created: Febuary 3rd, 2025
Program that builds the nodes for the tree
*/

#ifndef _BINARY_NODE_H
#define _BINARY_NODE_H

#include <iostream>
#include <vector>

class node_t
{
    public:
        node_t *_left;
        node_t *_right;
        int _charInString;
        std::vector<std::string> strings; // list to keep track of strings that have same char
        node_t(int numOfChar): _left(nullptr), _right(nullptr), _charInString(numOfChar) {}
};

#endif
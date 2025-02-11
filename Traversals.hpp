/*
Author: Grant Hughes
Created: Febuary 3rd, 2025
Program that builds the nodes for the tree
*/

#ifndef _TRAVERSALS_H_
#define _TRAVERSALS_H_

#include <iostream>
#include "BinaryNode.hpp"

class Traversals
{
    public:
        void traverseLevelOrder(node_t *node, const char[]); 
        void traversePreOrder(node_t *node, const char[]);
        void traversePostOrder(node_t *node, const char[]);
};

#endif
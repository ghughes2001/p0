/*
Author: Grant Hughes
Created: Febuary 3rd, 2025
Header file for traversing the tree
*/

#ifndef _TRAVERSALS_H_
#define _TRAVERSALS_H_

#include <iostream>
#include "BinaryNode.hpp"

class Traversals
{
    public:
        void traverseLevelOrder(node_t *node); 
        void traversePreOrder(node_t *node);
        void traversePostOrder(node_t *node);
};

#endif
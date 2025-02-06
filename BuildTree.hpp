/*
Author: Grant Hughes
Created: Febuary 3rd, 2025
Program that builds the binary tree class
*/

#ifndef _BUILD_TREE_H_
#define _BUILD_TREE_H_

#include <iostream>
#include "BinaryNode.hpp"
#include <fstream>

class BuildTree
{
    public: // accessible to other files
        node_t* buildTree(std::ifstream& file);
        node_t* insert(node_t *node, const std::string str, int strLength); //function to insert strings into tree
};

#endif
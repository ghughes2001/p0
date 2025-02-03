/*
Author: Grant Hughes
Created: Febuary 3rd, 2025
Program that builds the binary tree class
*/

#ifndef _BUILD_TREE_H_
#define _BUILD_TREE_H_

#include <iostream>
#include <BinaryNode.hpp>
#include <fstream>

class BuildTree
{
    node_t* buildTree(ifstream file);
    void insert(node_t *node, const std::string str, int strLength); //function to insert strings into tree
};

#endif
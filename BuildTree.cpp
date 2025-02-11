/*
Author: Grant Hughes
Created: Febuary 3rd, 2025
Program that builds the binary tree
*/

#include <iostream>
#include "BinaryNode.hpp"
#include "BuildTree.hpp"
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// function to take in file
node_t* BuildTree::buildTree(ifstream& file)
{
    // variables
    node_t* root = nullptr;
    string line;
    string word;

    // reading file based on white-space seperators
    // shiuld be already valid file
    while (getline(file, line))
    {
        istringstream seperatedLine(line);

        while (seperatedLine >> word)
        {
            int length = word.length(); // using length of strings to measure node placement in tree
            insert(root, word, length);
        }
    }
    return root;
}

// function that inseerts a node depeing on string size
node_t* BuildTree::insert(node_t *node, const string str, int strLength)
{
    if (node == nullptr)
    {
        node = new node_t(strLength);
        node->strings.push_back(str);
    }
    if (strLength < node->_charInString)
    {
        insert(node->_left, str, strLength); // insert on left side
    }
    if (strLength > node->_charInString)
    {
        insert(node->_right, str, strLength); // insert on right side
    }
    if (strLength == node->_charInString)
    {
        node->strings.push_back(str); // insert same string size
    }
    return node;
}
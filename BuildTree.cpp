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
            root = insert(root, word, length);
        }
    }
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
    } else {
        cout << "Tree built successfully!" << endl;
    }
    return root;
}

node_t* BuildTree::insert(node_t* node, const string str, int strLength)
{
    if (node == nullptr)
    {
        node = new node_t(strLength); // create a new node
        node->strings.push_back(str); // add string to the node
        return node; // return the new node to update the parent node's pointer
    }

    // If the current node's string length is greater, insert to the left
    if (strLength < node->_charInString)
    {
        node->_left = insert(node->_left, str, strLength); // recurse on left subtree
    }
    // If the current node's string length is less, insert to the right
    else if (strLength > node->_charInString)
    {
        node->_right = insert(node->_right, str, strLength); // recurse on right subtree
    }
    // If the current node's string length is equal, add the string to this node
    else
    {
        node->strings.push_back(str);
    }
    return node; // return the node to its parent
}
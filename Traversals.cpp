/*
Author: Grant Hughes
Created: Febuary 11rd, 2025
Program that traverses the binary tree
*/

#include <iostream>
#include "BinaryNode.hpp"
#include "BuildTree.hpp"
#include "Traversals.hpp"
#include <stack>

using namespace std;

void Traversals::traverseLevelOrder(node_t *node)
{
    // variables
    queue<node_t*> nodeQueue;

    if (node == nullptr) // checking if there is a root
        return;
    
    // there is node(s)
    nodeQueue.push(node);

    while (!nodeQueue.empty())
    {
        node_t *currentNode = nodeQueue.front();
        nodeQueue.pop(); // removing current node from queue

        cout << currentNode->_charInString << ": ";
        for (size_t i = 0; i < currentNode->strings.size(); i++)
        {
            cout << currentNode->strings[i] << " ";
        }
        cout << endl;

        // adding left and right nodes but left first in level order
        if (currentNode->_left)
            nodeQueue.push(currentNode->_left);
        if (currentNode->_right)
            nodeQueue.push(currentNode->_right);
    }
}

void Traversals::traversePreOrder(node_t *node)
{
    // variables
    stack<node_t*> nodeStack;

    if (node == nullptr) // checking if there is a root
        return;
    
    // there is node(s)
    nodeStack.push(node);

    while (!nodeStack.empty())
    {
        node_t *currentNode = nodeStack.top();
        nodeStack.pop(); // removing current node from stack

        cout << currentNode->_charInString << ": ";
        for (size_t i = 0; i < currentNode->strings.size(); i++)
        {
            cout << currentNode->strings[i] << " ";
        }
        cout << endl;

        // adding left and right nodes but right first in preorder
        if (currentNode->_right)
            nodeStack.push(currentNode->_right);
        if (currentNode->_left)
            nodeStack.push(currentNode->_left);
    }
}

void Traversals::traversePostOrder(node_t *node)
{
    // variables
    stack<node_t*> preOrderStack;
    stack<node_t*>  postOrderStack;

    if (node == nullptr) // checking if there is a root
        return;
    
    // there is node(s)
    preOrderStack.push(node);

    // getting nodes from tree
    while (!preOrderStack.empty())
    {
        node_t *currentNode = preOrderStack.top();
        preOrderStack.pop(); // removing current node from stack
        postOrderStack.push(currentNode);

        // access left/right nodes
        if (currentNode->_left)
            preOrderStack.push(currentNode->_left);
        if (currentNode->_right)
            preOrderStack.push(currentNode->_right);
    }
    // print the nodes in post order
    while (!postOrderStack.empty())
    {
        node_t *currentPostOrderNode = postOrderStack.top(); // getting first node
        postOrderStack.pop();

        cout << currentPostOrderNode->_charInString << ": ";
        for (size_t i = 0; i < currentPostOrderNode->strings.size(); i++)
        {
            cout << currentPostOrderNode->strings[i] << " ";
        }
        cout << endl;
    }
}
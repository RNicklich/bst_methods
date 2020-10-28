#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>

using namespace std;

class Node
{
private:
   int key;
   string val;
   Node* left;
   Node* right;
   friend class BinarySearchTree;   
};   


class BinarySearchTree
{
public:   
       BinarySearchTree();
       void insert(int key, string val); // Recursive
       void printInOrder() const; // Prints keys in-order. Recursive
       string find(int key) const; //Returns value if node is present, else return empty string. Iterative
       int findMin(int num) const;
       int findMax(int num) const;
       void findPredecessor(int key);
       int findSuccessor(int key);
       void simpleInsert(int key, string val);
private:
        Node* root;
        void insertHelper(Node* parent, Node* new_node);
        void printInOrderHelper(Node *n) const; //Helper for recursive implemenation of printInroder()
        int findMinHelper(Node *n) const;
        int findMaxHelper(Node *n) const;
};

#endif

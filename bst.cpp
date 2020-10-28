#include <iostream>
#include "bst.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{  
   root = nullptr;
}
   
void BinarySearchTree::insert(int key, string val) 
{  
   Node* new_node = new Node;
   new_node->key = key;
   new_node->val = val;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) { 
      root = new_node; 
   } else { 
      insertHelper(root, new_node); 
   }
}

void BinarySearchTree::insertHelper(Node* parent, Node* new_node) 
{  
   if (new_node->key < parent->key) {  
      if (parent->left == nullptr) { 
         parent->left = new_node; 
      }
      else { 
         insertHelper(parent->left, new_node); }
   }
   else if (new_node->key > parent->key) {  
      if (parent->right == nullptr) {
         parent->right = new_node; 
      }
      else { 
         insertHelper(parent->right, new_node);
      }
   }
}

string BinarySearchTree::find(int key) const {
   Node* current = root;

   while(current != nullptr){
      if(key < current->key){
         current = current->left;
      }
      else if(key > current->key){
         current = current->right;
      }
      else if(key == current->key){
         return current->val;
      }
   }   
   return "";
}

void BinarySearchTree::printInOrder() const {
	if (root == nullptr) {
		cout << endl;
	}
	printInOrderHelper(root);
	cout << endl;
}
   
void BinarySearchTree::printInOrderHelper(Node* n) const {
   Node* current = n;
   if(current == nullptr){
      return;
   }
   else{
      printInOrderHelper(current->left);
      cout << current->key << " ";
      printInOrderHelper(current->right);

      }
}
int BinarySearchTree::findMin(int num) const{
   Node* current = root;
   while(current-> key != num){
      if(num < current->key){
         current = current->left;
      }
      else if(num > current-> key){
         current = current->right;
      }
   }
   findMinHelper(current); 
   
}

int BinarySearchTree::findMax(int num) const{
   Node* current = root;
   while(current-> key != num){
      if(num < current->key){
         current = current->left;
      }
      else if(num > current-> key){
         current = current->right;
      }
   }
   findMaxHelper(current); 
   
}

int BinarySearchTree::findMinHelper(Node* n) const{
   Node* next = n;
   Node* previous = nullptr;
   while(next != nullptr){
      previous = next;
      next = next->left;
      }
   
   return previous->key;

   }

int BinarySearchTree::findMaxHelper(Node* n) const{
   Node* next = n;
   Node* previous = nullptr;
   while(next != nullptr){
      previous = next;
      next = next->right;
      }
   return previous->key;
}

// void BinarySearchTree::findPredecessor(int k){
//    Node* prev = root;
//    Node*current = root;
//    while(current-> key != k){
//       prev = current;
//       if(k < current->key){
//          current = current->left;
//       }
//       else if(k > current-> key){
//          current = current->right;
//       }
//    }
//    if(current != nullptr){

//    cout << "Previous key to " << k << " is: " << prev->key << endl;
//    }
//    else{
//       cout << "Node with key: " << k << " does not exist in the tree" << endl;

// }
// }

int BinarySearchTree::findSuccessor(int k){
   Node*current = root;
   int succ = current->key;
   if(current->right->left != nullptr){
      succ = current->right->left->key;
   }
   while(current->key != k){
      if(k < current->key){
         if(current->left->right != nullptr){
            succ = current->left->right->key;
         }
         else{
            succ = current->key
         }
          current = current->left;
      }
      else if( k > current->key){
         current = current->right;
         succ = current->right->key;
      }
   }

}

void BinarySearchTree::findPredecessor(int k){
   Node* par = nullptr;
   Node* pred = nullptr;
   Node* current = root;
   if(root->key == k){
      cout << "Predecessor of " << k << " is: " << findMax(root->left->key) << endl;
   }
   else{
   while(k != current->key){
      par = current;
      if(k < current->key){
         current = current->left;
      }
      else{
         current = current->right;
      }
   }
   if(current == par->right){
      pred = par;
      cout << "predecessor of K= " << pred->key << endl;
   }
   else if(current == par->left){
      findPredecessor(pred->key);
   }

   }
   }


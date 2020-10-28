#include <iostream>
#include "bst.h"

using namespace std;

// Tests the binary search tree class.

int main()
{  
   BinarySearchTree t;
   t.insert(5, "Boron");
   t.insert(3, "Lithium");
   t.insert(7, "Nitrogen");
   t.insert(2, "Helium");
   t.insert(4, "Berylium");
   t.insert(6, "Carbon");
   t.insert(8, "Oxygen");
   t.printInOrder(); // Prints the keys in order (will appear sorted)
   for(int i = 0; i < 10; i++){
   int ele = i;
   string val = t.find(ele);
   if (val == "" ) {
       cout << ele << " does not exist in tree" << endl;
   } else {
       cout << ele << " : " << val << endl;
   }
   }
   t.findMin(3);
   t.findMax(3);
   t.findPredecessor(6);
   //t.findSuccessor(6);
//    ele = 0;
//    val = t.find(ele);
//    if (val == "" ) {
//        cout << ele << " does not exist in tree" << endl;
//    } else {
//        cout << ele << " : " << val << endl;
//    }

    return 0;
}
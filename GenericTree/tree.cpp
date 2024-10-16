/********************************************************
You may assume that the following Node class has already
been defined for you previously:

*/

#include<iostream>

class Node {
public:
  Node *left, *right;
  Node() { left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

/*Implement the function "int count(Node *n)" below to return
an integer representing the number of nodes in the subtree
of Node n (including Node n itself).

*********************************************************/

int count(Node *n){

  //implement count() here.

    if (n == nullptr) {
        return 0;
    }
    
    //count the current node (1) and recursively count the left and right subtrees
    return 1 + count(n->left) + count(n->right);

}

int main() {
  Node *n = new Node(); // The root node of the tree (set left right to nullptr)
  n->left = new Node();
  n->right = new Node();
  n->right->left = new Node();
  n->right->right = new Node();
  n->right->right->right = new Node();

  // This should print a count of six nodes
  std::cout << count(n) << std::endl;

  // Deleting n is sufficient to delete the entire tree
  // because this will trigger the recursively-defined
  // destructor of the Node class.
  delete n;
  n = nullptr;

  return 0;
}
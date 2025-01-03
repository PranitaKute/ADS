//Creation of binary tree by manual allocation

#include <bits/stdc++.h>
using namespace std;
//declare node using class definition
class Node{
public:
    int data;   //stores value of the node
    Node *left, *right; //reference pointer to left & right child

    //method to initialize the node with a value
    Node(int a){    //when node obj is created, constructor is called
        data = a;
        left = right = nullptr;
    }
};
int main(){
    //create root for binary tree using dynamic allocation
    Node* root = new Node(5);
    //create left & right child nodes for root node
    root -> left = new Node(3);
    root -> right = new Node(8);
    return 0;
}

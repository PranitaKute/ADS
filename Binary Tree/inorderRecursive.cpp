//In-Order travering using recursion
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int a){
        data = a;
        left = right = nullptr;
    }
};

void inOrderTraversal(Node* root){
    if(root == NULL)
        return;

    Node* node = root;      //node is a pointer to an object of type Node

    inOrderTraversal(node -> left);

    cout<< node->data <<endl;

    inOrderTraversal(node -> right);
}

int main(){
    /*                  5
                    /       \
                3               8
               /
           10    2

    */
    Node* root = new Node(5);
    root -> left = new Node(3);
    root -> right = new Node(8);
    root -> left -> left = new Node(10);
    root -> left -> right = new Node(2);
    inOrderTraversal(root);
return 0;
}

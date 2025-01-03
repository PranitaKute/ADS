//Postorder Traversing using recursion
#include <bits/stdc++.h>
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

void postOrderTraversal(Node* root){
    if(root == NULL)
        return;

    Node* node = root;      //node is a pointer to an object of type Node

    postOrderTraversal(node -> left);

    postOrderTraversal(node -> right);

    cout<< node->data <<endl;
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
    postOrderTraversal(root);
return 0;
}



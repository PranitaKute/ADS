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

void preOrderTraversal(Node* root){
    if(root == NULL)
        return;

    cout<< root->data <<endl;

    preOrderTraversal(root -> left);

    preOrderTraversal(root -> right);
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
    preOrderTraversal(root);
return 0;
}

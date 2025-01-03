//Post-Order traversing using 2 stacks
/* Add nodes in stack 1, then pop top node & add the node in stack 2.
Check if the node has left right, if yess add those in stack 1 & repeat the process */

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

    stack<Node* > stack1, stack2;

    Node* node = root;
    stack1.push(node);

    while(!stack1.empty()){
        node = stack1.top();
        stack1.pop();
        stack2.push(node);


        //Push left child into stack 1 if exists
        if(node -> left){
            stack1.push(node -> left);
        }

        //Push right child into stack 1 if exists
        if(node -> right){
            stack1.push(node -> right);
        }
    }

    while(!stack2.empty()){
        Node* node = stack2.top();
        cout<<node -> data<<" ";
        stack2.pop();
    }
    cout<<endl;
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

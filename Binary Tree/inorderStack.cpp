//Inorder Traversing using stack
/* Insert root & check if left exists.If yes, traverse to extreme left
& then pop from stack, pop root & check if right exists. Traverse & print */

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

void inOrderTraversal(Node *root){
    if(root == NULL)
        return;

    stack<Node*> treeStack;
    Node* current = root;       //current is initialized to root node to start traversal


    //current is not NULL (indicating nodes to process in the left subtree).
    while(current != nullptr || !treeStack.empty()){        //The stack is not empty (indicating there are nodes pending to be processed).
        while(current!=nullptr){
            treeStack.push(current);
            current = current -> left;       //traverse to left subtree
        }
        current = treeStack.top();
        treeStack.pop();
        cout<<current -> data<<" ";
        current = current -> right;         //traverse to right subtree
    }
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
    cout<<"In-Order traversing..."<<endl;
    inOrderTraversal(root);
return 0;
}

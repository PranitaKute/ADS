//TBT Creation

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    bool rthreaded;

    Node(int a){
        data = a;
        left = right = NULL;
        rthreaded = false;
    }
};

Node* insert(Node* root, int value){    // insert a new node with the given value
    if(!root){
        return new Node(value);     //// Create a new node if the tree is empty
    }

    Node* parent = NULL;    // Parent of value to be inserted
    Node* current = root;   //traverse the tree starting from root

    while(current){
        parent = current;

        if(value < current -> data){    //traverse left subtree
            if(!current->left) break; //If current->left is nullptr, stop the traversal. The new node will be inserted here.
                current = current->left;
        }

        else{   //if value to insert is greater than or equal to the current node’s data
            if(!current -> right || current->rthreaded){
            //If current->right is nullptr or rthreaded == true, stop traversal. The new node will be inserted here.
                break;
            }
            current = current -> right;
        }
    }
    Node* newNode = new Node (value);

    if(value < parent->data){
        parent -> left = newNode;   //Attach the new node as the left child of the parent
        newNode -> right = parent;  //thread pointing to parent
        newNode -> rthreaded = true;    //set threaded as true
    }
    else{
        if(parent -> rthreaded){
            newNode->right = parent->right;     // Preserve the thread
            newNode -> rthreaded = true;
        }
        parent->right = newNode;
        parent->rthreaded = false; // Right child is no longer a thread
    }

    return root;

}

int main(){
    Node* root = nullptr;
    int value;

    cout << "Enter values to insert into the Threaded Binary Tree (0 to stop):" << endl;

    // Take input from the user
    while (true) {
        cin >> value;
        if (value == 0) break; // Stop if the user enters -1
        root = insert(root, value); // Insert the value into the tree
    }

    return 0;
}

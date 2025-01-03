/* Starting at the root, find the deepest and rightmost node in the binary tree and the node which we want to delete.
Replace the deepest rightmost node’s data with the node to be deleted.
Then delete the deepest rightmost node. */
#include <bits/stdc++.h>
using namespace std;

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

int getValidInput() {
    int val;
    while (true) {
        if (cin >> val) {
            return val;
        } else {
            cout << "Invalid Input! Enter only a number..." << endl;
            cout << "Enter the value for tree node (-1 for no node) = ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}


Node* createBinaryTree(){
    int data;
    cout<<"Enter data (-1 if no data) : "<<endl;
    cin>>data;
    if(data == -1)
        return nullptr;

    Node* newNode = new Node(data);
    cout<<"Enter left child : "<<endl;
    newNode -> left = createBinaryTree();

    cout<<"Enter right child : "<<endl;
    newNode -> right = createBinaryTree();

    return newNode;
}

void breadthFirstTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    cout << "Breadth First Traversal: ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}


int main(){
     Node* root = createBinaryTree();

    cout<<"Enter the value to delete from the tree: ";
    int val = getValidInput();
    root = deleteNode(root, val);

    cout << "Tree after deletion:" << endl;
    breadthFirstTraversal(root);

    return 0;

}

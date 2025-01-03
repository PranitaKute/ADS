//Preorder traversing using stack
/* 1. Push root of binary tree into the stack
2. Repeat while stack is not empty
i] Pop top element from stack & process it
ii] Push its right child & then left child because stack is LIFO
*/

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

//iterative process to print preorder traversal
void preOrderTraversal(Node *root){
    if(root == NULL)
        return;


    //create empty stack & push root
    stack<Node*> treeStack;
    treeStack.push(root);


//pop and print. push right child & then left child
//right child is pushed first so left child is processed first

    while(treeStack.empty() == false){
        Node* current = treeStack.top();
        treeStack.pop();
        cout<<current -> data<<" ";

        if(current -> right)
            treeStack.push(current -> right);
        if(current -> left)
            treeStack.push(current -> left);
    }
}

int main(){
/*                      5
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
    cout<<"Pre-Order traversing using Stack..."<<endl;
    preOrderTraversal(root);
    return 0;
}



/* Stack implementation
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    Node** arr;      // Pointer to array holding Node* elements
    int top;         // Index of the top element
    int capacity;    // Maximum capacity of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        arr = new Node*[size];
        capacity = size;
        top = -1; // Initially, the stack is empty
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(Node* node) {
        if (top == capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = node;
    }

    // Function to remove the top element from the stack
    Node* pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return nullptr;
        }
        return arr[top--];
    }

    // Function to return the top element without removing it
    Node* peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return nullptr;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

class Node {
public:
    int data;
    Node *left, *right;
    Node(int a) {
        data = a;
        left = right = nullptr;
    }
};

// Iterative process to print preorder traversal
void preOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    // Create an empty stack of sufficient size
    Stack stack(100); // Assuming a maximum of 100 nodes in the tree
    stack.push(root);

    // While the stack is not empty
    while (!stack.isEmpty()) {
        Node* current = stack.pop();
        cout << current->data << " "; // Process the current node

        // Push right child first so left child is processed first
        if (current->right)
            stack.push(current->right);
        if (current->left)
            stack.push(current->left);
    }
}

int main() {
                    5
                    /       \
                3               8
               / \
           10    2

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(10);
    root->left->right = new Node(2);

    cout << "Pre-Order Traversal using Custom Stack..." << endl;
    preOrderTraversal(root);

    return 0;
}

*/

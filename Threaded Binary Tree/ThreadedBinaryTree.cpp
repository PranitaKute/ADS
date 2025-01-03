#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node *left, *right;
    bool rthreaded;
    public:
    Node(int a){
        left = right = nullptr;
        data = a;
        rthreaded = false;
    }

    // Getter: A method that allows you to access the value of a private field
    //Setter: A method that allows you to modify the value of a private field
    int getValue() {
        return data;
    }

    void setValue(int a) {
        data = a;
    }

    // Getter and setter for left
    Node* getLeft() {
        return left;
    }

    void setLeft(Node* l) {
        left = l;
    }

    // Getter and setter for right
    Node* getRight() {
        return right;
    }

    void setRight(Node* r) {
        right = r;
    }

    bool isThreaded(){
        return rthreaded;
        }
    void setThreaded(bool threaded){
        rthreaded = threaded;
        }

};

Node* insert(Node* root, int value) {
    Node* newNode = new Node(value);

    if (!root) {
        // If the tree is empty, the new node becomes the root.
        return newNode;
    }

    Node* parent = NULL;
    Node* current = root;

    // Traverse the tree to find the insertion point
    while (current) {
        parent = current;
        if (!current->getLeft() || current->isThreaded()) {
            // If the current node has no left child or is threaded, break and insert here
            break;
        }
        current = current->getLeft();
    }

    // Insert the new node as the left child of the parent node
    parent->setLeft(newNode);
    newNode->setRight(parent);  // Set the thread pointing to the parent
    newNode->setThreaded(true);

    if (parent->getLeft() == NULL) {
        // If the parent has no left child, set the new node as its left child
        parent->setLeft(newNode);
    } else {
        // Update parent's threading
        parent->setThreaded(false);
    }

    // Update threading in the parent node if necessary
    if (parent->isThreaded()) {
        newNode->setRight(parent->getRight());  // Preserve the right thread of the parent
        newNode->setThreaded(true);
    } else {
        parent->setThreaded(false);
    }

    return root;
}

void inorder(Node* root) {
    Node* current = root;

    while (current && current->getLeft()) {  // traverse to the leftmost node
        current = current->getLeft();
    }

    while (current) {   // Traverse the tree using threads
        cout << current -> getValue() << " ";
        if (current -> isThreaded()) {
            current = current->getRight(); // Use the thread
        } else {
            // Move to the leftmost node in the right subtree
            current = current->getRight();
            while (current && current->getLeft()) {
                current = current->getLeft();
            }
        }
    }
}

int main(){
    Node* root = nullptr;
    int value, choice;

    while (true) {
        cout << "\nSelect:\n";
        cout << "1. Insert a node\n";
        cout << "2. Display in-order traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        // Validate choice input
        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 3: ";
        }

        switch (choice) {
        case 1:
            cout << "Enter a value to insert: ";
            // Validate value input
            while (!(cin >> value)) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter valid input: ";
            }
            root = insert(root, value);
            cout << "Value inserted successfully.\n";
            break;

        case 2:
            cout << "In-order traversal of the Threaded Binary Tree:\n";
            inorder(root);
            break;

        case 3:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}


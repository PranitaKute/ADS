//TBST Creation, inorder & deletion
#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;
    bool rthreaded;
public:
    Node(int a){
        data = a;
        left = right = NULL;
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

Node* insert(Node* root, int value){    // insert a new node with the given value
    if(!root){
        return new Node(value);     //Create a new node if the tree is empty
    }

    Node* parent = NULL;    // Parent of value to be inserted
    Node* current = root;   //traverse the tree starting from root

    while(current){
        parent = current;

        if(value < current -> getValue()){    //traverse left subtree
            if(!current->getLeft()) break; //If current->left is nullptr, stop the traversal. The new node will be inserted here.
                current = current->getLeft();
        }

        else{   //if value to insert is greater than or equal to the current node’s data
            if(!current -> getRight() || current->isThreaded()){
            //If current->right is nullptr or rthreaded == true, stop traversal. The new node will be inserted here.
                break;
            }
            current = current -> getRight();
        }
    }
    Node* newNode = new Node (value);

    if(value < parent->getValue()){
        parent -> setLeft(newNode);   //Attach the new node as the left child of the parent
        newNode -> setRight(parent);  //thread pointing to parent
        newNode -> setThreaded(true);    //set threaded as true
    }
    else{
        if(parent -> isThreaded()){
            newNode->setRight(parent->getRight());     // Preserve the thread
            newNode -> setThreaded(true);
        }
        parent->setRight(newNode);
        parent->setThreaded(false); // Right child is no longer a thread
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

Node* deleteNode(Node* root, int value){
    // Locate the node to be deleted and its parent
    Node* parent = NULL;
    Node* current = root;

    while (current && current->getValue() != value) {
        parent = current;   //Update parent as you move through the tree.
        if (value < current->getValue()) {
            current = current->getLeft();
        } else if (!current->isThreaded()) {
            current = current->getRight();
        } else {
            break; // Node not found
        }
    }
    //if node doesn't exist in tree
    if (!current || current->getValue() != value) {
    cout << "Node with value " << value << " not found.\n";
    return root;
    }

    //Node to be deleted is leaf
    if(!current -> getLeft() && (current -> isThreaded() || !current -> getRight())){
        //In this specific code block, parent being NULL indicates that
        //the node to be deleted is the root node because there is no parent node in this case.
        if(!parent){
            // Deleting the root node
            delete current;
            return NULL;
        }
        if (parent->getLeft() == current) {
            parent->setLeft(NULL);
        } else {
            if (parent->isThreaded()) {
                parent->setThreaded(true);
                parent->setRight(current->getRight());
            } else {
                parent->setRight(NULL);
            }
        }
        delete current;
        return root;
    }

    // Node to be deleted has one child
    if (current->getLeft() && (!current->getRight() || current->isThreaded())) {
        Node* child = current->getLeft();
        if (!parent) {
            delete current;
            return child; // If deleting root, the child becomes the new root
        }
        if (parent->getLeft() == current) {
            parent->setLeft(child);
        } else {
            parent->setRight(child);
        }
        Node* rightmost = child;
        while (rightmost->getRight() && !rightmost->isThreaded()) {
            rightmost = rightmost->getRight();
        }
        rightmost->setRight(current->getRight());
        rightmost->setThreaded(current->isThreaded());
        delete current;
        return root;
    }

    //Node to be deleted has two children
    Node* successorParent = current;    //point to the node that is to be deleted
    Node* successor = current->getRight();  //set to point to the right child of the current node
    while (successor->getLeft()) {  //traverse to the leftmost child of the successor
        successorParent = successor;
        successor = successor->getLeft();
        //Moves successor to its left child to continue searching for the leftmost node
    }
    current->setValue(successor->getValue());
    //replaces the value of current with its in-order successor's value,
    //preparing to delete the original successor node.

    if (successorParent->getLeft() == successor) {
        successorParent->setLeft(successor->getRight());
        //If successor is the left child, its right child (if any) becomes the left child of successorParent,
        //removing successor from the tree.
    } else {
        successorParent->setRight(successor->getRight());
        //Sets the right child of successorParent to successor's right child.
        successorParent->setThreaded(successor->isThreaded());
        //If successor was threaded, then successorParent will maintain that threading link.
    }
    delete successor;
    return root;
}

int main(){
    Node* root = nullptr;
    int value, choice;

    while (true) {
        cout << "\nSelect:\n";
        cout << "1. Insert a node\n";
        cout << "2. Display in-order traversal\n";
        cout << "3. Delete Node \n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        // Validate choice input
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4: ";
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
            cout << "Enter value to delete:\n";
            cin>>value;
            deleteNode(root, value);
            break;

        case 4:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

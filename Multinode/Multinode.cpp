//Assignment 1: Multinode Tree
//multinode tree
#include <utility>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* center;
    Node* right;
    // Constructor
public:
    Node(int value) {
        data = value;
        left = nullptr;
        center = nullptr;
        right = nullptr;
    }
    // Getter: A method that allows you to access the value of a private field
    // Setter: A method that allows you to modify the value of a private field
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
    //Getter and setter for centre
    Node* getCenter() {
        return center;
    }
    void setCenter(Node* c){
        center = c;
    }

    // Getter and setter for right
    Node* getRight() {
        return right;
    }
    void setRight(Node* r) {
        right = r;
    }
};
class Stack {
private:
    int top;    // Index of the top element in the stack

    Node* arr[100];   // Array to store stack elements, with a capacity of 100 elements

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        top = -1;
    }

    // Function to add an element x to the top of the stack
    void push(Node* x)
    {
        // If stack is full print "Stack overflow" and return
        if (top >= 99) {
            cout << "Stack overflow" << endl;
            return;
        }
        // Add element to the top of the stack and increment top
        arr[++top] = x;
    }

    Node* pop()   // Function to remove the top element from the stack
    {
        // If the stack is empty, print "Stack underflow" and return 0
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return nullptr;
        }
        // Remove the top element from the stack and decrement top
        return arr[top--];
    }

    // Function to return the top element of the stack
    Node* peek()
    {
        // If the stack is empty, print "Stack is empty" and return 0
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return nullptr;
        }
        // Return the top element of the stack
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        // Return true if the stack is empty (i.e., top is -1)
        return (top < 0);
    }
};
// Class for MultiNodeTree: manages the tree structure and provides operations for insertion & traversal.
class MultiNodeTree {
public:
    Node* root;
    // Constructor
    MultiNodeTree() {
        root = nullptr;
    }
    // Insert method: Inserts a new node at the first available position
    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        // Use level-order traversal to find the first empty position
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->getLeft() == nullptr) {
                current->setLeft(newNode);
                return;
            } else {
                q.push(current->getLeft());
            }

            if (current->getCenter() == nullptr) {
                current->setCenter(newNode);
                return;
            } else {
                q.push(current->getCenter());
            }

            if (current->getRight() == nullptr) {
                current->setRight(newNode);
                return;
            } else {
                q.push(current->getRight());
            }
        }
    }

    //Iterative Preorder Traversal (Root -> Left -> Center -> Right)
    void preorder() {
        if (root == nullptr)
            return;

        Stack s;
        s.push(root);

        while (!s.isEmpty()) {
            Node* current = s.peek();
            s.pop();
            cout << current->getValue() << " ";

            // Push children in reverse order to maintain preorder sequence
            if (current->getRight())
                s.push(current->getRight());
            if (current->getCenter())
                s.push(current->getCenter());
            if (current->getLeft())
                s.push(current->getLeft());
        }
    }

    //Inorder Traversal (Left -> Root -> Center -> Right)
    void inorderTraversal(Node* current) {
        if (current == nullptr)
            return;

        // Left -> Root -> Center -> Right
        inorderTraversal(current->getLeft());
        cout << current->getValue() << " ";
        inorderTraversal(current->getCenter());
        inorderTraversal(current->getRight());
    }

    //Postorder Traversal (Left -> Center -> Right -> Root)
    void postorderTraversal(Node* current) {
        if (current == nullptr)
            return;

        // Left -> Center -> Right -> Root
        postorderTraversal(current->getLeft());
        postorderTraversal(current->getCenter());
        postorderTraversal(current->getRight());
        cout << current->getValue() << " ";
    }

     // Helper to call the recursive functions
    void inorder() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }

};

int main() {
    MultiNodeTree tree;
    int root, choice;

    cout << "Enter the root node data: ";
    cin >> root;
    tree.insert(root);

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Preorder Traversal\n";
        cout << "3. Display Inorder Traversal\n";
        cout << "4. Display Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Enter the data of the new node: ";
            cin >> data;
            tree.insert(data);
            break;
        }
        case 2:
            cout << "Preorder Traversal: ";
            tree.preorder();
            cout << endl;
            break;
        case 3:
            cout<< "Inorder Traversal: ";
            tree.inorder();
            cout<<endl;
            break;
        case 4:
            cout<< "Postorder Traversal: ";
            tree.postorder();
            cout<<endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}



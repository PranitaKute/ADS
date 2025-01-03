//Creation of binary tree using recursion
#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;   //value stored in node
    Node *left, *right;
public:
    Node(int a){
        data = a;   //initializes data with value a
        left = right = nullptr;
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

};

// Function to validate user input
int validInput() {
    int data;
    while (true) {
        cout << "Enter data (-1 if no data): ";
        cin >> data;

        if (cin.fail()) { // If input is invalid
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input! Please enter an integer.\n";
        } else {
            return data; // Return the valid integer input
        }
    }
}

// Function to create binary tree
Node* createBinaryTree() {
    int data = validInput(); // Get validated input

    if (data == -1)
        return nullptr;

    Node* newNode = new Node(data);

    cout<<"Enter left child : "<<endl;
    newNode -> setLeft(createBinaryTree());

    cout<<"Enter right child : "<<endl;
    newNode -> setRight(createBinaryTree());

    return newNode;
}

/*
            1
        /       \
    2              3
null  null    null   null
*/
int main(){
    Node* root = createBinaryTree();
    return 0;
}

// Nodes are dynamically allocated in memory & connected to each other using pointers

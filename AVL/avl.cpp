//AVL Tree
#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    int height;
    Node *left;
    Node *right;
    public:
    Node(int a){
        data = a;
        left = right = nullptr;
        height = 1;
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

    // Getter and setter for right
    Node* getRight() {
        return right;
    }

    void setRight(Node* r) {
        right = r;
    }

    // Getter and setter for height
    int getHeight(){
        return height;
    }

    void setHeight(int h){
        height = h;
    }

};

int height(Node *N){
    if(N == nullptr){   //If the node is nullptr, its height is 0
        return 0;       //This handles the scenario where we reach beyond a leaf node
    }
    return N -> getHeight();       // node exists, it retrieves the stored height using the getHeight() method
}

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
            return 0;
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
            return 0;
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


//check valid input
int validInput(){
    int data;
    while(true){
        cout << "Enter data (-1 for no node): ";
        cin >> data;
        if(cin.fail()){
            //if input is invalid
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input! \n";

            /*if(cin.fail()):
            This checks if the last input operation on cin failed. This can happen if the user enters data of the wrong type (e.g., entering a letter when an integer is expected). The fail() function returns true if the last input operation failed.
            cin.clear();:

            If the input operation failed, this line resets the state of cin. It clears the error flags that were set, allowing the program to attempt input again.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');:

            This line is used to discard the invalid input from the input buffer.
            numeric_limits<streamsize>::max() specifies the maximum number of characters to ignore. This effectively means "ignore everything left in the input buffer."
            The '\n' indicates that it will stop ignoring characters once it reaches a newline character (which typically signifies the end of the current input line). This prevents the program from entering an infinite loop by continuously trying to read the same invalid input.
            cout << "Invalid input! \n";:

            Finally, this line outputs a message to inform the user that their input was invalid. */
        }
        else{
            return data;
        }
    }
}
//Find balance factor
int balanceFactor(Node* N){
    if(N == nullptr){
        return 0;
    }
    //difference between the heights of the left and right subtrees
    return height(N -> getLeft()) - height(N -> getRight());
}

Node *rotateRight(Node *y) {
    Node *x = y-> getLeft();
    Node *P2 = x->getRight();

    //rotation
    x->setRight(y);
    y->setLeft(P2);

    // Update height
    y->setHeight(1 + max(height(y -> getLeft()), height(y -> getRight())));
    x->setHeight(1 + max(height(x -> getLeft()), height(x -> getRight())));

    // Return new root
    return x;
}

Node *rotateLeft (Node *x){
    Node *y = x -> getRight();
    Node *P2 = y -> getLeft();

    //rotation
    y -> setLeft(x);
    x -> setRight(P2);

    //Update heights
    x -> setHeight(1 + max(height(x -> getLeft()),height(x -> getRight())));
    y -> setHeight(1 + max(height(y -> getLeft()),height(y -> getRight())));

    //return new root
    return y;
}

//insertion in avl
Node* insertNode(Node* node, int data){
    if(node == NULL)
        return new Node(data);

    if(data < node -> getValue())
         node->setLeft(insertNode(node->getLeft(), data));

    else if(data > node -> getValue())
         node->setRight(insertNode(node->getRight(), data));

    else
        return node;    //duplicate

    node -> setHeight(1 + max(height(node -> getLeft()), height(node -> getRight())));  //1 + height of its tallest subtree
    //maximum height between the left and right subtrees of node & ( 1 + )add current node itself

    int bal = balanceFactor(node);

     // Left Left unbalanced
    if (bal > 1 && data < node -> getLeft()-> getValue())
        return rotateRight(node);

    // Right Right unbalanced
    if (bal < -1 && data > node -> getRight()-> getValue())
        return rotateLeft(node);

    // Left Right unbalanced
    if (bal > 1 && data > node -> getLeft()-> getValue()) {
        node -> setLeft(rotateLeft(node -> getLeft()));
        return rotateRight(node);
    }
     // Right Left unbalanced
    if (bal < -1 && data < node -> getRight()->getValue()) {
        node -> setRight(rotateRight(node->getRight()));
        return rotateLeft(node);
    }

    return node;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) return;

    Stack s;
    Node* current = root;

    while (!s.isEmpty() || current != nullptr) {
        // Traverse to the leftmost node
        while (current != nullptr) {
            s.push(current);
            current = current->getLeft();
        }

        // Process the top node in the stack
        current = s.peek();
        s.pop();
        cout << current->getValue() << " ";

        // Traverse the right subtree
        current = current->getRight();
    }
}

int main() {
    Node* root = nullptr;

    //cout << "AVL Tree Implementation\n";
    while (true) {
        int choice, data;
        cout << "\n 1. Insert\n 2. Print In-order\n 3. Exit\n Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                data = validInput();
                root = insertNode(root, data);
                break;
            case 2:
                cout << "In-order Traversal: ";
                inOrderTraversal(root);
                cout << endl;
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}

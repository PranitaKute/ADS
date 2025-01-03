//Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

class Node {
    int value;
    Node* left;
    Node* right;

public:
    Node(int a) {
        value = a;
        left = right = nullptr;
    }


    // Getter: A method that allows you to access the value of a private field
    // Setter: A method that allows you to modify the value of a private field
    int getValue() {
        return value;
    }

    void setValue(int a) {
        value = a;
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

// creation of binary search tree (input from user)
Node* insert(Node* node, int value) {
//don't insert the values which are multiples of 6
    if(value % 6 == 0) {
        cout <<"Cannot insert multiples of 6 \n";
        return node;
    }

    // If tree is empty, return a new node
    if (node == NULL){
        return new Node(value);     //A new node is created when the current position in the tree is NULL
    }
    // If key is already present in the tree, return the current node without making any changes.
    // This effectively skips the insertion of duplicate values.
    if (node->getValue() == value){
        return node;
    }
    // If the value to be inserted is greater
    //insert it in the right side
    if (node->getValue() < value) {
        node->setRight(insert(node->getRight(), value));                //why called insert function? value vs address
    }
    // If the value to be inserted is smaller
    //insert it in the left side
    else{
        node->setLeft(insert(node->getLeft(), value));
    }
    return node;
}


/*Start at the root and go as far left as possible, pushing nodes onto the stack.
When there are no more left nodes, process the top node of the stack and move to its right subtree.
Repeat until the stack is empty and all nodes are processed.*/
void inOrderTraversal(Node *root) {
    if (!root){ // If the tree is empty, return
        cout<<"Root is NULL \n";
        return;
    }

    Stack nodeStack;
    Node *current = root;

    while (current != nullptr || !nodeStack.isEmpty()) {
        // Traverse to the leftmost node
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->getLeft();
        }

        // Current is now null, process the top node
        current = nodeStack.peek();
        nodeStack.pop();

        cout << current->getValue() << " "; // Process the node

        // Move to the right subtree
        current = current->getRight();
    }
}

/*Initialize a stack and push the root node onto it.
While the stack is not empty:
Pop the top node from the stack and process it.
Push the right child (if exists) onto the stack.
Push the left child (if exists) onto the stack.
Continue until the stack is empty.*/
void preorder(Node *root){
    if (root == NULL)
    {
        cout<<"Root is NULL \n";
        return;
    }
    Stack st;
    st.push(root);
    while (!st.isEmpty()){   //stack is not empty
        Node *current = st.peek();
        st.pop();

        if (current->getRight() != NULL)
        {
            st.push(current->getRight());
        }
        if (current->getLeft() != NULL)
        {
            st.push(current->getLeft());
        }

        cout << current->getValue() << " ";
    }
}

/* st1 helps us traverse the tree in a pre-order manner.
st2 stores nodes in reverse post-order, and after popping from st2, we get the correct post-order sequence. */
void postorder(Node *root) {
    if (root == NULL){
            cout<<"Root is NULL \n";
            return;
    }
    Stack st1, st2;
    st1.push(root);

    while (!st1.isEmpty()) {
        Node* node = st1.peek();
        st1.pop();
        st2.push(node);  // Push node into second stack

        // Push left and right children into the first stack
        if (node->getLeft())
            st1.push(node->getLeft());
        if (node->getRight())
            st1.push(node->getRight());
    }

    // The second stack will contain nodes in sequence of postorder
    while (!st2.isEmpty()) {
        cout << st2.peek()->getValue() << " ";
        st2.pop();
    }
}

void breadthFirstTraversal(Node* root) {
    if (root == nullptr){
            cout<<"Root is NULL \n";
        return;
    }

    // Create an empty queue
    queue<Node*> q;

    // insert Root
    q.push(root);

    while (!q.empty()) {

        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->getValue() << " ";
        q.pop();

        // Enqueue left child
        if (node->getLeft() != nullptr)
            q.push(node->getLeft());

        // Enqueue right child
        if (node->getRight() != nullptr)
            q.push(node->getRight());
    }
}
int main(){
    Node* root = nullptr;
    int data;

    cout << "Enter the values to create a binary search tree (-1 to stop)\n";

    while (true) {
        data = validInput();  // check valid input

        if (data == -1){  // Stop taking input
            break;
        }
        root = insert(root, data);  // Insert value into the tree
    }

    // For example, print the root node's data after the tree is created
    if (root != nullptr) {
        cout << "Root node->value: " << root->getValue() << endl;
    }

    cout<< "\n Inorder traversing : \n";
    inOrderTraversal(root);

    cout<< "\n Preorder traversing : \n";
    preorder(root);

    cout<< "\n Postorder traversing : \n";
    postorder(root);

    cout<< "\n Breadth First Traversal: \n";
    breadthFirstTraversal(root);
    return 0;
}

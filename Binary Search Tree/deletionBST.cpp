//Deletion in binary Search tree
#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node *left, *right;

public:
    Node(int a){
        data = a;
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

Node* insert(Node* node, int value) {
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
    if (node->getValue() < value){
        node->setRight(insert(node->getRight(), value));               //why called insert function? value vs address
    }
    // If the value to be inserted is smaller
    //insert it in the left side
    else{
        node->setLeft(insert(node->getLeft(), value));
    }
    return node;
}

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

Node* findMin(Node* root) {
    while (root && root->getLeft()) {    //root is not nullptr & left child of the current root exists
        root = root->getLeft();
    }
    return root;
}

Node* deleteNode(Node* root, int value, bool* deleted) { //value == value to be deleted
    if (!root)      //it means the tree is empty or the key was not found.
        return NULL;

    if (value < root->getValue()) {
        root->setLeft(deleteNode(root->getLeft(), value, deleted));
    } else if (value > root->getValue()) {
        root->setRight(deleteNode(root->getRight(), value, deleted));
    } else {        //the key matches the root->data
        *deleted = true;
        if (!root->getLeft() && !root->getRight()) {      //Node is leaf
            delete root;
            return NULL;
        }
        if (!root->getLeft()) {  //if the node has only right child, replace node with right child
            Node* temp = root->getRight();
            delete root;
            return temp;
        }
        if (!root->getRight()) { //if the node has only left child, replace node with left child
            Node* temp = root->getLeft();
            delete root;
            return temp;
        }

        //When deleting a node with two children, we need to replace it with a value that: Is larger than all the values in the left subtree.
        //Is smaller than all the values in the right subtree.
        Node* temp = findMin(root->getRight());
        root->setValue(temp->getValue());
        root->setRight(deleteNode(root->getRight(), temp->getValue(), deleted));
        //This recursively deletes the node with the smallest value (temp) from the right subtree.
    }
    return root;
}
void inOrderTraversal(Node* root) {
    if (!root) return;
    inOrderTraversal(root->getLeft());
    cout << root->getValue() << " ";
    inOrderTraversal(root->getRight());
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

    cout << "Enter the node to be deleted: ";
    int dvalue = validInput();

    bool deleted = false;
    root = deleteNode(root, dvalue, &deleted);

    if(deleted){
        cout<<"Value deleted successfully!"<<endl;
    }
    else{
        cout<<"Value to be deleted not found!"<<endl;
    }

    cout << "Remaining nodes in the Binary Search Tree (in-order): ";
    inOrderTraversal(root);
    cout << endl;


    return 0;
}

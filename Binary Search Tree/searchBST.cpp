//Searching a node in BST
/*First compare the value to be searched with the root. If it equals, the search is done.
If its smaller than the root, traverse to left subtree because in BST all elements in left are smaller
and all elements in right subtree are larger. Repeat this steps until no more traversal possible. */
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

Node* searchBST(Node* root, int value){  //value = node to be searched
    if(root == NULL || root -> getValue() == value)

        return root;

    if(value < root -> getValue())
        return searchBST(root -> getLeft(), value);

    if(value > root -> getValue())
        return searchBST(root -> getRight(), value);
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

    cout<<"Enter the value to be searched : ";
    int svalue;
    cin>>svalue;
    if (searchBST(root, svalue)){
        cout<< "Value to be searched Found! \n";
    }
    else{
        cout<<"Value to be searched Not Found \n";
    }
    return 0;
}

#include <iostream>
#include <limits>
using namespace std;
class Node {
private:
    int data;
    Node* left;
    Node* right;
public:
    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
    int getData() const { return data; }
    void setData(int value) { data = value; }

    Node* getLeft() const { return left; }
    void setLeft(Node* node) { left = node; }

    Node* getRight() const { return right; }
    void setRight(Node* node) { right = node; }
};
class Stack {
private:
    class StackNode {
    public:
        Node* data;
        StackNode* next;
        StackNode(Node* node) : data(node), next(nullptr) {}
    };
    StackNode* top;
public:
    Stack() : top(nullptr) {}
    void push(Node* node) {
        StackNode* newNode = new StackNode(node);
        newNode->next = top;
        top = newNode;
    }
    Node* pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return nullptr;
        }
        StackNode* temp = top;
        Node* node = top->data;
        top = top->next;
        delete temp;
        return node;
    }
    Node* peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return nullptr;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
class Queue {
private:
    struct QueueNode {
        Node* data;
        QueueNode* next;
    };
    QueueNode* frontNode;
    QueueNode* rearNode;
public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}
    void push(Node* value) {
        QueueNode* newNode = new QueueNode{value, nullptr};
        if (rearNode != nullptr) {
            rearNode->next = newNode;
        } else {
            frontNode = newNode;
        }
        rearNode = newNode;
    }
    void pop() {
        if (!isEmpty()) {
            QueueNode* temp = frontNode;
            frontNode = frontNode->next;
            if (!frontNode) {
                rearNode = nullptr;
            }
            delete temp;
        }
    }
    Node* front() {
        if (frontNode != nullptr) {
            return frontNode->data;
        } else {
            return nullptr;
        }
    }
    bool isEmpty() {
        return frontNode == nullptr;
    }
};
void inorderTraversal(Node* root) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }
    Node* last = root;
    Stack s;
    s.push(root);
    while(!s.isEmpty()){
        Node* current = s.peek();
        s.pop();
        if(current->getLeft() && current->getLeft()!=last && current->getRight()!=last){
            s.push(current);
            s.push(current->getLeft());
        }
        else if(current->getRight() && current->getRight()!=last){
            cout<<current->getData()<<" ";
            s.push(current);
            s.push(current->getRight());
        }
        else if(current->getRight()==nullptr){
            cout<<current->getData()<<" ";
        }
        last = current;
    }
}
void preorderTraversal(Node* root) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }
    Node* last = root;
    Stack s;
    s.push(root);
    while(!s.isEmpty()){
        Node* current = s.peek();
        s.pop();
        if(current->getLeft() && current->getLeft()!=last && current->getRight()!=last){
            cout<<current->getData()<<" ";
            s.push(current);
            s.push(current->getLeft());
        }
        else if(current->getRight() && current->getRight()!=last){
            if(current->getLeft()==nullptr) cout<<current->getData()<<" ";
            s.push(current);
            s.push(current->getRight());
        }
        else if(current->getLeft()==nullptr && current->getRight()==nullptr){
            cout<<current->getData()<<" ";
        }
        last = current;
    }
}

void postorderTraversal(Node* root) {
    if (!root) {+
        cout << "Tree is empty.\n";
        return;
    }
    Node* last = root;
    Stack s;
    s.push(root);
    while(!s.isEmpty()){
        Node* current = s.peek();
        s.pop();
        if(current->getLeft() && current->getLeft()!=last && current->getRight()!=last){
            s.push(current);
            s.push(current->getLeft());
        }
        else if(current->getRight() && current->getRight()!=last){
            s.push(current);
            s.push(current->getRight());
        }
        else{
            cout<<current->getData()<<" ";
        }
        last = current;
    }
}
void addNode(Node*& root, int location, int parentData, int newData) {
    Node* newNode = new Node(newData);
    if (location == 0) {
        if (!root) {
            root = newNode;
        } else {
            cout << "Root node already exists!" << endl;
            delete newNode;
        }
        return;
    }
    Stack s;
    s.push(root);
    Node* parent = nullptr;
    while (!s.isEmpty())
    {
        Node* current = s.pop();

        if (current->getData() == parentData) {
            parent = current;
            break;
        }
        if (current->getRight()) s.push(current->getRight());
        if (current->getLeft()) s.push(current->getLeft());
    }
    if (!parent) {
        cout << "Parent node not found!" << endl;
        delete newNode;
        return;
    }
    if (location == 1) {
        if (!parent->getLeft())
        {
            parent->setLeft(newNode);
        }
        else
        {
            cout << "Left child already exists!" << endl;
            delete newNode;
        }
    }
    else if (location == 2)
    {
        if (!parent->getRight())
        {
            parent->setRight(newNode);
        }
        else
        {
            cout << "Right child already exists!" << endl;
            delete newNode;
        }
    }
    else
    {
        cout << "Invalid location!" << endl;
        delete newNode;
    }
}
// Delete node function
void deleteNode(Node*& root, int value) {
    if (!root) {
        cout << "Tree is empty. Nothing to delete.\n";
        return;
    }
    Node* nodeToDelete = nullptr;
    Node* bottomParent = nullptr;
    Node* bottomNode = nullptr;
    // Locate the node to delete and bottom-most node
    Queue q;
    q.push(root);
    while (!q.isEmpty()) {
        Node* current = q.front();
        q.pop();
        if (current->getData() == value) {
            nodeToDelete = current;
        }
        if (current->getLeft()) {
            bottomParent = current;
            bottomNode = current->getLeft();
            q.push(current->getLeft());
        }
        if (current->getRight()) {
            bottomParent = current;
            bottomNode = current->getRight();
            q.push(current->getRight());
        }
    }
    if (!nodeToDelete) {
        cout << "Node with value " << value << " not found in the tree.\n";
        return;
    }
    if (bottomNode) {
        nodeToDelete->setData(bottomNode->getData());
        if (bottomParent->getRight() == bottomNode) {
            bottomParent->setRight(nullptr);
        } else {
            bottomParent->setLeft(nullptr);
        }
        delete bottomNode;
        cout << "Node " << value << " deleted successfully.\n";
    } else {
        // Only root exists
        delete root;
        root = nullptr;
        cout << "Node " << value << " deleted. The tree is now empty.\n";
    }
}
int main() {
    Node* root = nullptr;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Node\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Delete Node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }
        switch (choice) {
            case 1: {
                int location, parentData, newData;
                if (root == nullptr) {
                    cout << "Enter root node data: ";
                    cin >> newData;
                    root = new Node(newData);
                } else {
                    cout << "Enter location (1 for left, 2 for right): ";
                    cin >> location;
                    cout << "Enter parent node data: ";
                    cin >> parentData;
                    cout << "Enter new node data: ";
                    cin >> newData;
                    addNode(root, location, parentData, newData);
                }
                break;
            }
            case 2:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 5: {
                if (!root) {
                    cout << "Tree is empty. Cannot delete any node.\n";
                } else {
                    int value;
                    cout << "Enter the value of the node to delete: ";
                    cin >> value;
                    deleteNode(root, value);
                }
                break;
            }
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);
}

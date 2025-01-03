//Breadth first traversal in Binary tree

#include <bits/stdc++.h>
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

int validInput(){
    int data;
    while (true){
        cout<<"Enter data (-1 if no data) : "<<endl;
        cin>>data;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid Input!"<<endl;
        }
        else{
            return data;
        }
    }
}

Node* insertion(){
    int data = validInput();

    if(data == -1)
        return nullptr;

    Node* newNode = new Node(data);
    cout<<"Enter left child : "<<endl;
    newNode -> left = insertion();

    cout<<"Enter right child : "<<endl;
    newNode -> right = insertion();

    return newNode;
}
void breadthFirstTraversal(Node* root) {
    if (!root)
        return;

    queue<Node*> q;
    q.push(root);

    cout << "Breadth First Traversal: ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
    cout << endl;
}

int main(){

    Node* root = insertion();

    breadthFirstTraversal(root);
    return 0;
}

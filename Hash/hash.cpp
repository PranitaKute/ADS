#include <iostream>
#include <limits> // For numeric limits
#define TABLE_SIZE 10
using namespace std;

class Node {
private:
    int val;
    Node* next;
public:
    Node(int v) {
        val = v;
        next = NULL;
    }
    int getValue() {
        return val;
    }

    void setValue(int a) {
        val = a;
    }

    // Getter and setter next pointer
    Node* getNext() {
        return next;
    }

    void setNext(Node* n) {
        next = n;
    }
};

class Hash {
    Node* tbl[TABLE_SIZE];  //Array of pointers to store chains

public:
    Hash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            tbl[i] = NULL;  //initialize all bucket to null
        }
    }

    int hashFn(int key) {
        return key % TABLE_SIZE;    //Returns the bucket index for a given key
    }

    void insert(int key) {
        int index = hashFn(key);      //find appropriate bucket
        Node* newNode = new Node(key);  //create new node
        if (tbl[index] == NULL) {       //if bucket is empty, insert new node
            tbl[index] = newNode;
        } else {
            Node* tmp = tbl[index];     //Traverse the chain in the bucket
            while (tmp->getNext() != NULL) {
                tmp = tmp->getNext();
            }
            tmp->setNext(newNode);     //Add the new node at the end of the chain
        }
    }

    void show() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "\nIndex: " << i << " : ";  //prints bucket index
            Node* tmp = tbl[i];
            while (tmp != NULL) {       //traverse the chain
                cout << tmp->getValue() << " -> ";
                tmp = tmp->getNext();
            }
            cout << "NULL";
        }
        cout << endl;
    }
};

int getValidInt() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer: ";
        } else {
            return num; // Valid input
        }
    }
}

int main() {
    Hash ht;
    int choice;
    do {
        cout << "Enter 1: For Insert\n";
        cout << "Enter 2: For Display\n";
        cout << "Enter 3: For Exit\n";
        choice = getValidInt(); // Get a validated integer input

        switch (choice) {
        case 1: {
            cout << "\nEnter a number: ";
            int num = getValidInt(); // Call the validated input function
            ht.insert(num);
            break;
        }
        case 2:
            ht.show();
            break;
        case 3:
            break;
        default:
            cout << "\nInvalid choice! Please select a valid option.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}

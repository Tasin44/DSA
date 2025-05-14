

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

int main() {
    vector<int> arr = {2, 5, 8, 7};

    // Creating a new Node with data from arr[0] and next pointer as nullptr
    Node* y = new Node(arr[0], nullptr);

    // Printing the pointer to the Node (memory address)
    cout << y << endl;

    // Optional: Clean up memory to avoid memory leaks
    delete y;

    return 0;
}





///2 without using struct

#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    // Constructor with two parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with one parameter
    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    // Getter methods to access private members
    int getData() {
        return data;
    }

    Node* getNext() {
        return next;
    }
};

int main() {
    vector<int> arr = {2, 5, 8, 7};

    // Creating a Node dynamically
    Node* yPtr = new Node(arr[0], nullptr);
    cout << yPtr->getData() << endl;  // Accessing data using getter

    // Creating a Node object
    Node y = Node(arr[0], nullptr);
    cout << y.getData() << endl;  // Accessing data using getter
    cout << y.getNext() << endl;  // Accessing next using getter

    // Clean up memory
    delete yPtr;

    return 0;
}





///3 without using getmethod


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;      // Make data public
    Node* next;    // Make next public

    // Constructor with two parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with one parameter
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int main() {
    vector<int> arr = {2, 5, 8, 7};

    // Creating a Node dynamically
    Node* yPtr = new Node(arr[0], nullptr);
    cout << yPtr->data << endl;  // Accessing data directly

    // Creating a Node object
    Node y = Node(arr[0], nullptr);
    cout << y.data << endl;  // Accessing data directly
    cout << y.next << endl;  // Accessing next directly

    // Clean up memory
    delete yPtr;

    return 0;
}














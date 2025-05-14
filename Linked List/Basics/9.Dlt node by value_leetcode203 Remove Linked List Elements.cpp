


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor with one parameter
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array to a linked list
Node* convet_arr_to_llist(vector<int> arr) {
    if (arr.empty()) return nullptr; // Handle empty array case

    Node* head = new Node{arr[0]};
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Function to print the linked list
void print(Node* head) {

    if(head==NULL)
    cout<<"We can't remove the tail";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to remove the tail of the linked list
Node* removeElements(Node* head, int val) {
        // Handle the case where the head itself needs to be removed

        /*
        jodi first node(means head) tai desired element hoy like [1,2,3] ,val=1
        or all the elements head er equal hoy means same hoy like [7,7,7,7] val =7
        */
        while (head != NULL && head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // If the list becomes empty after removing nodes equal to `val`
        if (head == NULL) return head;

        // Remove nodes with the given value after the head
        Node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == val) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            } else {
                temp = temp->next;
            }
        }

        return head;
}

int main() {
    vector<int> arr ={2, 5, 8, 7};

    Node* head = convet_arr_to_llist(arr);

    cout << "Original list: ";
    print(head);  // Print the original list

    head = removeElements(head,7);

    cout << "After removing the element: ";
    print(head);  // Print the updated list

    return 0;
}





class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

    /*
    //First whille loop Handle the case where the head itself needs to be removed.
    If first node(means head) is the desired element like [1,2,3] ,
    desired deleted val=1 or all the elements of the list == head
    like [7,7,7,7],desired deleted val =7
    */
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // If the list becomes empty after removing nodes equal to `val`
        if (head == NULL) return head;

        // Remove nodes with the given value after the head
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {

            if (temp->next->val == val) {

        ListNode* nodeToDelete = temp->next; // nodeToDelete points to the node containing 2
        temp->next = temp->next->next;//'temp->next' now skips node '2' and points directly to node '3'
        delete nodeToDelete;// Deletes the node containing '2'

            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};

//Time complexity: O(number of elements in the list)

/*
1.
delete temp: deallocates the memory for the whole ListNode object, which includes:

The integer value "val" stored in the node.
The pointer->next that points to the next node in the list.

So, delete temp; deletes the entire node: both its val and next pointer,
along with any other member variables that might be part of the node structure.
The memory for these elements is freed, and that memory can be reused for other purposes.


2.
ListNode* temp = head;
here only current head->val or
both head->val and head->next assigned ?

It you are assigning temp to point to the same node that head points to,
including both val and next.


3.
why I'm storing here ListNode* nodeToDelete = temp->next;
instead of  ListNode* nodeToDelete = temp->next->val;

Understanding the Difference

(i)ListNode* nodeToDelete = temp->next;

This statement assigns nodeToDelete to point to the next node (temp->next) in the linked list.
It captures the entire node object, including both its val (the value stored in the node)
and its next (the pointer to the next node).

This is useful when you want to perform operations like deleting the node or
updating the linked list structure.


(ii)ListNode* nodeToDelete = temp->next->val;

This statement is incorrect because temp->next->val is of type int (or whatever type val is), not ListNode*.
You can't assign an integer value to a pointer of type ListNode*.

val only represents the value stored in the node, not the node itself.
If you store temp->next->val, you're only storing the value,
which doesn't allow you to modify the linked list structure.




*/























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
Node* removekthnode(Node* head, int k) {
    if (head == NULL) return NULL;
    /*head ==null means no element present in the list
    */
     Node* temp=head; //making a copy of head, because we don't want to change the orginal head

    if(k==1)
    {
      head= head->next;
      free(temp);
      return head;
    }


    int cnt=0;

    Node* prev=NULL;

    while(temp!=NULL)
    {
       cnt++;

       if(cnt==k)
       {
          prev->next=prev->next->next;
          free(temp);
          break;

       }
       prev=temp;
       temp=temp->next;

    }

    return head;//This function will be returning a new head of the linked-list,
}

int main() {
    vector<int> arr ={2, 5, 8, 7};

    Node* head = convet_arr_to_llist(arr);

    cout << "Original list: ";
    print(head);  // Print the original list

    head = removekthnode(head,3);

    cout << "After removing Kth element: ";
    print(head);  // Print the updated list

    return 0;
}

//Time complexity: O(k)













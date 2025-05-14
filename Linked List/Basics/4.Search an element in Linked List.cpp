


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


Node* convet_arr_to_llist(vector<int> arr)
{
    Node* head = new Node{arr[0]};
    Node* mover = head;

    for(int i=1;i<arr.size();i++)
    {
      Node* temp = new Node(arr[i]);
      mover->next = temp;
      mover = temp;
      //mover =mover->next;
    }

   return head;
}

bool check_if_present(Node* head, int val)
{

    Node* temp=head;
    while(temp)
    {
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
}

int main() {
    vector<int> arr = {2, 5, 8, 7, 18, 20 };

    Node* head = convet_arr_to_llist(arr);

    cout<<check_if_present(head,50)<<endl;
    cout<<check_if_present(head,5)<<endl;
    return 0;
}


/*
we can't return the entire linked list,we can return the head, so head means we need pointer to the head.


mover=temp
mover =mover->next; all are same
*/



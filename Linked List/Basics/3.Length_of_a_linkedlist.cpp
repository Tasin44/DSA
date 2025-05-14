

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
int length_of_llist(Node* head)
{
    int cnt=0;
    Node* temp=head;
    while(temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int main() {
    vector<int> arr = {2, 5, 8, 7, 18, 20 };

    Node* head = convet_arr_to_llist(arr);

    cout<<length_of_llist(head)<<endl;
    return 0;
}


/*
we can't return the entire linked list,we can return the head, so head means we need pointer to the head.


mover=temp
mover =mover->next; all are same
*/























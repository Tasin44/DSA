#include <bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{

    int data;
    Node *next;

};

Node *create_node(int item, Node *next)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    if (new_node==NULL)
    {
        cout<<"Error! Couldn't create a new node  "<<endl;
        exit(1);
    }
    new_node->data = item;
    new_node->next =next;

    return new_node;
}

Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item,head);
    return new_node;
}



int main()
{
   Node *n;
   n=create_node(10,NULL);
   cout<<"Data "<< (n->data) <<endl;

    Node *nnew;
   //for(int i=2;i<=8;i+=2)
   //{
     nnew=prepend(n , 2);

  // }


   //for(int i=0;i<5;i++)
   //{
     cout<<"New Data "<< (nnew->data) <<endl;
   //}

   //

}









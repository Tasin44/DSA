
//problem
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

void append(Node *node, int item)
{
    Node *new_node = create_node(item,node->next);

    node->next = new_node;

}



int main()
{
     Node *new2;

     append(NULL, 50);
     //cout<<"new Data "<< (new2->data) <<endl;
}









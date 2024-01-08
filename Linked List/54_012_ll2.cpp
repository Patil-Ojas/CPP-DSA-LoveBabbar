// without data changing
#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void insert3000(Node* &temp, Node* &nodetoinsert)
{
    nodetoinsert->next = temp;
    nodetoinsert = temp;
}

Node* sortList(Node *head)
{
    Node* head0 = new Node(-1);
    Node* head1 = new Node(-1);
    Node* head2 = new Node(-1);

    Node* tail0 = head0;
    Node* tail1 = head1;
    Node* tail2 = head2;

    Node* temp = head;   

    while (temp!=NULL)
    {
        if (temp->data == 0)
            insert3000(temp, head0);
        else if (temp->data == 1)
            insert3000(temp, head1);
        else if (temp->data == 2)
            insert3000(temp, head2);
        
        temp = temp->next;
    }

    // to merge the 3 created LL's
    // skip the dummy nodes
    tail0 = tail0->next;
    tail1 = tail1->next;
    tail2 = tail2->next;

    if (head1 != NULL)
    {
        head0->next = tail1;
    }
    else
    {
        head0->next = tail2;
    }
    head1->next = tail2;
    head2->next = NULL;
    // forgot to delete
    head = tail0;

    return head;
}
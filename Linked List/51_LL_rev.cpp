// I may wanna commit die
// alright top 12% maybe not...
#include <iostream>


// Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

 int getLength(Node*& head)
 {
    Node* temp=head;
    int cnt=0;
    
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
 }

 Node* kReverse(Node* head, int k) {
     
    if (head == NULL)
        return NULL;

    int leng = getLength(head);
    if (leng < k)
        return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* fwd = NULL;

    int count = 0;

    while (curr!=NULL and count<k)
    {   
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        count++;
    }


    if (fwd!=NULL)
    {
        head->next = kReverse(fwd, k);
    }

    return prev;
}
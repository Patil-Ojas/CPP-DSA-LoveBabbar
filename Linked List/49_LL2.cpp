
// Following is the class structure of the Node class:
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

Node *findMiddle(Node *head) {
    // Write your code here

    int leng = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        // to optimize the code even further
        if (temp->next != NULL)
        {   
            leng = leng + 2;
            temp = temp->next->next;
        }
        else
        {
            leng++;
            temp = temp->next;
        }
    }

    Node* middle = NULL;
    leng = (leng)/2 +1;
    
    while (leng!=0)
    {
        middle = head;
        head = head->next;
        leng--;
    }
    return middle;
}

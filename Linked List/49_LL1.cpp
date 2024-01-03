#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    int start = 0;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *fwd = NULL;

    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}
#include <iostream>
#include <map>
using namespace std;

class Node {
    public :
    int data;
    Node *next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// proud

Node *removeLoop(Node *head) {
    Node* prev = NULL;
    Node* temp = head;

    map<Node* , bool>visited;

    while(temp!=NULL and temp->next!= NULL)
    {
        if (visited[temp])
        {
            prev->next = NULL;
            break;
        }

        visited[temp] = true;
        prev = temp;
        temp = temp->next;
    }

    return head;
}
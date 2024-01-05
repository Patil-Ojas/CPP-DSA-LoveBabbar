#include <iostream>
#include <map>
using namespace std;

//  doesnt deal with ffloyd thing
     
class Node{
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }   
};

bool isCircular(Node* head)
{
    Node* temp = head;
    map <Node*, bool> visited;
    int start_ele = head->data;

    if (head == NULL)
    {
        return true;
    }

    while (temp!=NULL)
    {
        if (visited[temp]==true)
        {
            return true;
        }
        else
        {
            visited[temp] = true;
            temp = temp->next;
        }
    }

    return false;
}

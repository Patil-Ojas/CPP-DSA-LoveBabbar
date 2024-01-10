#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


class Solution
{
    public:
    void insertatTail(Node* &anshead, Node* &anstail, int val)
    {
        Node* temp = new Node(val);
        if (anshead==NULL)
        {
            anstail = temp;
            anshead = temp;
            anstail->next = NULL;
            return;
        }
        else
        {
            anstail->next = temp;
            anstail = temp;
            return;
        }
    }
    
    Node* getSumLL(Node* first, Node* second)
    {
        Node* anshead = NULL;
        Node* anstail = NULL;
        int carry = 0;
        
        while (first!=NULL and second!=NULL)
        {
            int sum = first->data + second->data + carry;
            int digit = sum%10;
            
            insertatTail(anshead, anstail, digit);
            carry = sum/10;
            
            first = first->next;
            second = second->next;
        }
        
        while (first!=NULL)
        {
            int sum = first->data + carry;
            int digit = sum%10;
            
            insertatTail(anshead, anstail, digit);
            carry = sum/10;
            
            first = first->next;
        }
        
        while (second!=NULL)
        {
            int sum = second->data + carry;
            int digit = sum%10;
            
            insertatTail(anshead, anstail, digit);
            carry = sum/10;
            
            second = second->next;
        }
        
        while (carry!=0)
        {
            int digit = carry%10;
            
            insertatTail(anshead, anstail, digit);
            carry = digit/10;
        }
        
        return anshead;
    }
    
    Node* revLL(Node* temp)
    {
        Node* prev = NULL;
        Node* curr = temp;
        Node* fwd = NULL;
        
        while (curr!=NULL)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = revLL(first);
        second = revLL(second);
        
        Node* ans = getSumLL(first, second);
        ans = revLL(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
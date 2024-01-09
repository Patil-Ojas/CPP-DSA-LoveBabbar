//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


class Solution{
  public:
    bool checkPalin(vector<int> arr)
    {
        int s = 0;
        int e = arr.size()-1;
        
        while (s<=e)
        {
            if (arr[s] != arr[e])
                return false;
            
            s++;
            e--;
        }
        return true;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        
        while (head!=NULL)
        {
            arr.push_back(head->data);
            head = head->next;
        }
        
        // cout<<arr.size()<<endl;
        
        if (arr.size()==1)
            return 1;
        
        return checkPalin(arr);
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
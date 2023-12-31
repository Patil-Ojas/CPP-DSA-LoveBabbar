
#include <iostream> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;

        while (temp!=NULL and temp->next!=NULL)
        {
            if (temp->next->val==temp->val)
            {
                temp->next=temp->next->next;
                // what a beautiful continue use
                continue;
            }
            temp=temp->next;
        }
        return head;
    }
};

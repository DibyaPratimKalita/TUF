/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return NULL;
        ListNode* slow = head, *fast = head, *prev=NULL;

        while(fast && fast->next){
            prev = slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next = prev->next->next;

        return head;
    }
};
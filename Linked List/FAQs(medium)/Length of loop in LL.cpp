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
    int findLength(ListNode* fast, ListNode* slow){
        int count =1;
        fast=fast->next;

        while(fast != slow){
            count++;
            fast=fast->next;
        }

        return count;
    }
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head , *fast= head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                return findLength(fast, slow);
            }
        }

        return 0;
    }
};
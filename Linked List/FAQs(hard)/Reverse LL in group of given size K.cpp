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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count =0;

        ListNode* curr= head;

        while(count < k){
            if(curr == NULL){
                return head;
            }
            curr = curr->next;
            count++;
        }

        ListNode* newNext = reverseKGroup(curr, k);

        count =0;
        curr = head;
        ListNode* fut = head;

        while(count < k){
            fut = curr->next;
            curr->next = newNext;

            newNext= curr;
            curr = fut;
            count++;
        }

        return newNext;

    }
};
/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
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
    ListNode* deleteKthNode(ListNode* &head, int k) {
        if(k==1){
            ListNode* todelete=head;
            head=head->next;
            delete todelete;
            return head;
        }
        ListNode* temp=head;
        int count=2;
        while(count!=k){
            temp=temp->next;
            count++;
        }
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;  // Free memory
        
        return head;
    }
};
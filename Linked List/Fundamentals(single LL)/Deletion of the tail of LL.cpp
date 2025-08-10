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
    ListNode* deleteTail(ListNode* &head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL;

        ListNode* prev=head;
        ListNode* curr=head->next;

        while(curr->next!=NULL){
            curr=curr->next;
            prev=prev->next;
        }
        delete curr;
        prev->next=NULL;

        return head;
    }
};

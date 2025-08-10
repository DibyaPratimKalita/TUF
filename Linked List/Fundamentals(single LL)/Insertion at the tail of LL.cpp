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
    ListNode* insertAtTail(ListNode* &head, int X) {
        
        ListNode* last=new ListNode(X);
        ListNode* temp=head;

        if(head==NULL) {
            head=last;
            return head;
        }
        
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=last;

        return head;
    }
};
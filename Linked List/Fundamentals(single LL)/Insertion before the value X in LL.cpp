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
    ListNode* insertBeforeX(ListNode* &head, int X, int val) {
        ListNode* fresh=new ListNode(val);
        if(head==NULL){
            head=fresh;
            return head;
        }
        if(head->val==X){
            fresh->next=head;
            head=fresh;
            return head;
        }

        ListNode* temp=head;

        while(temp->next!=NULL && temp->next->val!=X){
            temp=temp->next;
        }
        if(temp->next==NULL) return head;

        fresh->next=temp->next;
        temp->next=fresh;

        return head;
    }
};

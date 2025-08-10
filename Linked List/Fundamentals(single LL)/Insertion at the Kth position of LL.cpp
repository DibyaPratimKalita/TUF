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
    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
        ListNode* fresh=new ListNode(X);
        ListNode* temp=head;
        if(head==NULL){
            head=fresh;
            return head;
        }

        if(K==1){
            fresh->next=head;
            head=fresh;
            return head;
        }
        int count=2;
        while(temp->next!=NULL && count!=K){
            temp=temp->next;
            count++;
        }
        fresh->next=temp->next;
        temp->next=fresh;
        
        return head;

    }
};
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* oddPointer = head;
        ListNode* evenPointer = head->next;
        ListNode* evenHead = head->next;

        while(evenPointer && evenPointer->next){
            oddPointer->next = oddPointer->next->next;
            evenPointer->next = evenPointer->next->next;
            oddPointer= oddPointer->next;
            evenPointer = evenPointer->next;
        }

        oddPointer->next = evenHead;
        return head;
    }
};
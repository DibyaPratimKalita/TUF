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
    ListNode* deleteNodeWithValueX(ListNode*& head, int X) {
        if (head == NULL) return NULL;
        if (head->val == X) {
            ListNode* todelete = head;
            head = head->next;
            delete todelete;
            return head;
        }
        ListNode* temp = head;
        
        while (temp->next != NULL && temp->next->val != X) {
            temp=temp->next;       
        }
        
        // If X was not found, return original list
        if (temp->next == NULL) return head;

        // Delete the node with value X
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;  // Free memory

        return head;
    }
};
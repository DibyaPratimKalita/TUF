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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head;
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        if(k == 0) return head;

        int size = 0;
        ListNode* prevTail = NULL;
        while (tail) {
            size++;
            prevTail = tail;
            tail = tail->next;
        }
        k = k % size;
        if(k == 0) return head;
        int stepsBeforeK = size - k - 1;
        ListNode* curr = head;
        for (int i = 0; i < stepsBeforeK; i++) {
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = NULL;

        prevTail->next = head;

        return newHead;
    }
};
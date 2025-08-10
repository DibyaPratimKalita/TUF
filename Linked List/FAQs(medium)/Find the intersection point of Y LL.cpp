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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0, sizeB = 0;
        ListNode *currA = headA, *currB = headB;

        while (currA) {
            sizeA++;
            currA = currA->next;
        }
        while (currB) {
            sizeB++;
            currB = currB->next;
        }
        // take them to the same starting point
        currA = headA, currB = headB;
        while (sizeA != sizeB) {
            if (sizeA > sizeB) {
                currA = currA->next;
                sizeA--;
            } else {
                currB = currB->next;
                sizeB--;
            }
        }

        while(currA != currB){
            currA=currA->next;
            currB=currB->next;
        }

        return currA;
    }
};
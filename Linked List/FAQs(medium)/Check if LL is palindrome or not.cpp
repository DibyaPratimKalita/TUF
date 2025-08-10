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
    ListNode* findMiddle(ListNode* head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *fut = NULL;

        while (curr) {
            fut = curr->next;

            curr->next = prev;

            prev = curr;
            curr = fut;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* middle = findMiddle(head);
        ListNode* revHead = reverse(middle);

        while (revHead) {
            if (head->val != revHead->val) {
                return false;
            }
            head = head->next;
            revHead = revHead->next;
        }

        return true;
    }
};
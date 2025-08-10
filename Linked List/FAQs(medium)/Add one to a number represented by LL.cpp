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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* addOne(ListNode* head) {
        // Step 1: Reverse the list
        head = reverse(head);

        // Step 2: Add one to the reversed list
        ListNode* curr = head;
        int carry = 1;

        while (curr) {
            /*Sum the current node's value
            and the carry*/
            int sum = curr->val + carry;
            // Update carry
            carry = sum / 10;
            // Update the node's value
            curr->val = sum % 10;

            /*If no carry left
            break the loop*/
            if (carry == 0) {
                break;
            }

            // If at end and carry is still left, add new node
            if (curr->next == NULL && carry) {
                curr->next = new ListNode(carry);
                break;
            }
            curr = curr->next;
        }
        
        head = reverse(head);
        return head;
    }
};

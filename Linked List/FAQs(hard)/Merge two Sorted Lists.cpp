// Definition of singly linked list:
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };

class Solution {
   public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                ListNode *temp = new ListNode(list1->val);
                curr->next = temp;
                curr = curr->next;
                list1 = list1->next;
            } else {
                ListNode *temp = new ListNode(list2->val);
                curr->next = temp;
                curr = curr->next;
                list2 = list2->next;
            }
        }

        while (list1) {
            ListNode *temp = new ListNode(list1->val);
            curr->next = temp;
            curr = curr->next;
            list1 = list1->next;
        }

        while(list2){
            ListNode *temp = new ListNode(list2->val);
            curr->next = temp;
            curr = curr->next;
            list2 = list2->next;
        }

        return dummy->next;
    }
};
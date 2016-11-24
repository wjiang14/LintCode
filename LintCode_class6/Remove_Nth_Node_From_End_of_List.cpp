// Remove Nth Node From End of List

// Given a linked list, remove the nth node from the end of list and return its head.
// Example
// Given linked list: 1->2->3->4->5->null, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5->null.

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        for (int i = 0; i < n; i++) {
            if (fast->next) {
                fast = fast->next;
            }
        }
        
        ListNode* slow = dummy;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* curr = slow->next;
        slow->next = curr->next;
        return dummy->next;
        
        // ListNode *res = new ListNode(0);
        // res->next = head;
        // ListNode *tmp = res;
        // for (int i = 0; i < n; i++) {
        //     head = head->next;
        // }
        // while (head != NULL) {
        //     head = head->next;
        //     tmp = tmp->next;
        // }
        // tmp->next = tmp->next->next;
        // return res->next;
    }
};



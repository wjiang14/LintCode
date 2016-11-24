// Reverse Linked List II
// Reverse a linked list from position m to n.

// Example
// Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        
        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        
        ListNode* pm = pre->next;
        for (int i = m; i < n; i++) {
            ListNode* n = pm->next;
            pm->next = n->next;
            n->next = pre->next;
            pre->next = n;
        }
        return dummy.next;
    }
};

Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example
Given 1->4->3->2->5->2->null and x = 3,
return 1->2->2->4->3->5->null.

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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        // ListNode* dummy = new ListNode(0);
        // dummy->next =  head;
        ListNode dummy1;
        ListNode dummy2;
        ListNode* p1 = &dummy1;
        ListNode* p2 = &dummy2;
        ListNode* p =  head;
        
        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            }
            else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = dummy2.next;
        p2->next = NULL;
        head = dummy1.next;
        return head;
    }
    
};



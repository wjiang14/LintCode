// Remove Duplicates from Sorted List II

// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// Example
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        bool duplicate = false;
        
        while(cur) {
            if(cur->next && cur->val==cur->next->val) {
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
                duplicate = true;
            }
            else if(duplicate) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
                duplicate = false;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};
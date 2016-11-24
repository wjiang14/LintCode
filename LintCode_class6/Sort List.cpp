// Sort List
// Sort a linked list in O(n log n) time using constant space complexity.
// Example
// Given 1->3->2->null, sort it to 1->2->3->null.

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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) {
             return head;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next->next;
            slow = slow -> next;
        }
        
        ListNode* mid = slow -> next;
        slow -> next = NULL;
        
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(mid);
        
        ListNode* sorted = merge(list1 , list2);
        return sorted;
    }
    
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            }
            else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left) {
            p->next = left;
        }
        if (right) {
            p->next = right;
        }
        return dummy.next;
    }
};
   


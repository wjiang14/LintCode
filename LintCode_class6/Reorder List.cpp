// Reorder List
// Given a singly linked list L: L0 → L1 → … → Ln-1 → Ln
// reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

// Example
// Given 1->2->3->4->null, reorder it to 1->4->2->3->null.

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
     * @return: void
     */
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        //divide list into two parts
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        
        // reverse second linked list
        ListNode* p = fast->next;
        fast->next = NULL;
        while (p) {
            ListNode* r = p->next;
            p->next = fast;
            fast = p;
            p = r;
        }
        
        //shuffle
        slow = head;
        while (slow) {
            if (fast) {
                ListNode* next1List = slow->next;
                slow->next = fast;
                ListNode* next2List = fast->next;
                fast->next = next1List;
                slow = next1List;
                fast = next2List;
            }
            else {
                break;
            }
        }
        
        //insert 2nd list into 1nd list
        // while(slow){
        //     if(fast){
        //         ListNode* n = slow->next;
        //         slow->next = fast;
        //         ListNode* nn = fast->next;
        //         fast->next = n;
        //         slow = n;
        //         fast = nn;
        //     }
        //     else 
        //         break;
        // }
    }
};



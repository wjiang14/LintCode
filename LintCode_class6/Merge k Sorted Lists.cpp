// Merge k Sorted Lists

// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.

// Example
// Given lists:

// [
//   2->4->null,
//   null,
//   -1->null
// ],
// return -1->2->4->null.

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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    struct compNode {
        bool operator()(ListNode *p, ListNode *q) const {
            return p->val>q->val;
        }  
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
        ListNode *dummy = new ListNode(0), *tail = dummy;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i]) pq.push(lists[i]);
        }
        while (!pq.empty()) {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if(tail->next) pq.push(tail->next);
        }
        tail->next = NULL;
        return dummy->next;
    }
};



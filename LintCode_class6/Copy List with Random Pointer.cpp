// Copy List with Random Pointer

// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (!head) {
            return NULL;
        }
        
        RandomListNode dummy(0);
        RandomListNode* n = &dummy;
        RandomListNode* h = head;
        unordered_map<RandomListNode*, RandomListNode*> map;
        
        while (h) {
            RandomListNode* node = new RandomListNode(h->label);
            n->next = node;
            n = node;
            
            node->random = h->random;
            map[h] = node;
            h = h->next;
        }
        
        h = dummy.next;
        while (h) {
            if (h->random) {
                h->random = map[h->random];
            }
            h = h->next;
        }
        return dummy.next;
    }
};
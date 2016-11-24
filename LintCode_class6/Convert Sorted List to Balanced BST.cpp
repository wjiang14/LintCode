// Convert Sorted List to Balanced BST
// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

// Example
//                2
// 1->2->3  =>   / \
//              1   3

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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if (!head) {
            return NULL;
        }
        ListNode* p = head;
        int len = 1;
        while (p->next) {
            len++;
            p = p->next;
        }
        return sortedList2BST(head, 0, len - 1);
    }
    
    TreeNode* sortedList2BST(ListNode*& head, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* leftChild = sortedList2BST(head, start, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        TreeNode* rightChild = sortedList2BST(head, mid + 1, end);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
};



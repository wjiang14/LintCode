/**
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
     * @param root the root of binary tree.
     * @return an integer
     */
    int maxPathSum2(TreeNode *root) {
        // Write your code here
        if (!root) {
            return INT_MIN;
        }
        int left = maxPathSum2(root->left);
        int right = maxPathSum2(root->right);
        
        return root->val + max(0, max(left, right));
    }
};
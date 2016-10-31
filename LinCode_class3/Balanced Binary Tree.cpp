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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return balancedHeight(root) >= 0;
    }
    
    int balancedHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = balancedHeight(root -> left);
        int right = balancedHeight(root -> right);
        
        if(left < 0 || right < 0 || abs(left - right) > 1){
            return -1; // not balanced tree
        }
        
        return max(left, right) + 1;
    }
};
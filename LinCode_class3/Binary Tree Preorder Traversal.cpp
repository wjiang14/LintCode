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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        preOrder(root, result);
        return result;
    }
    
    void preOrder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
};

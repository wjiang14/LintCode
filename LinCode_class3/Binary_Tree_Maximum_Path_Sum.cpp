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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int maxSum = INT_MIN;
        int ps1 = findMaxSum(root, maxSum);
        return maxSum;
    }
    // bottom up method
    // key method of this problem is classification of subproblems (ps1, ps2),
    // find the max one of these two
    int findMaxSum(TreeNode* root, int& maxSum) {
        if (!root) {
            return 0;
        }
        int left = 0, right = 0;
        if (root->left) {
            left = max(findMaxSum(root->left, maxSum), 0); //大于0
        }
        if (root->right) {
            right = max(findMaxSum(root->right, maxSum), 0);
        }
        int ps1 = max(left, right) + root->val; //第一种路径
        int ps2 = left + right + root->val; //2nd path
        maxSum = max(maxSum, max(ps1, ps2));
        return ps1;
    }
};
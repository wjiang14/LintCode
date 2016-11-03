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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int> preorder, vector<int> inorder, int lp, int rp, int li, int ri) {
        if (lp > rp || li > ri) {
            return NULL;
        }
        TreeNode* root =  new TreeNode(preorder[lp]);
        auto p = find(inorder.begin() + li, inorder.begin() + ri, preorder[lp]);
        int pos = p - inorder.begin() - li;
        
        root->left = build(preorder, inorder, lp + 1, lp + pos, li, li + pos - 1);
        root->right = build(preorder, inorder, lp + pos + 1, rp, li + pos + 1, ri);
        return root;
    }
};
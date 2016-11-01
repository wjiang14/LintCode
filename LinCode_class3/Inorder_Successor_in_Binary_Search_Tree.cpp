/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /* 利用bst性质，左子树小于root，root小于右子树，判断p是或否有有儿子，如果有，继任者是右子树的最左一个。如果没有必须从root向下找(因为没有父节点)。*/
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // write your code here
        if (!root) {
            return NULL;
        }
        if (p->right) {
            return theMostLeft(p->right);
        }
        TreeNode* successor = nullptr;
        while (root) {
            if (root->val > p->val) {
                successor = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return successor;
    }
    
    TreeNode* theMostLeft(TreeNode* node) {
        if (!node) {
            return node;
        }
        while (node->left) {
            node = node->left;
        }
        return node;
    }
    
};
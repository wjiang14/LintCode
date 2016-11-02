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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
private:
    stack<TreeNode*> s;
    void pushAll(TreeNode* root) {
        for (; root != NULL; s.push(root), root = root->left);
    }
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        pushAll(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !s.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode* node = s.top();
        s.pop();
        pushAll(node->right);
        return node;
    }
    
};
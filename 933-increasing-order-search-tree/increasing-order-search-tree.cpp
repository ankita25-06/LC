/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* curr;

    void inorder(TreeNode* node){
        if(!node) return;

        inorder(node->left);

        node->left = nullptr;
        curr->right = node;
        curr = node;

        inorder(node->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        curr = dummy;

        inorder(root);
        TreeNode* result = dummy->right;

        delete dummy;
        return result;
    }
};
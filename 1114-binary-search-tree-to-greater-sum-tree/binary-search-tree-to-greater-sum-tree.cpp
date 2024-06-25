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
public:
    int BstToGst ( TreeNode* root, int p = 0) {
        if(root->right) root->val += BstToGst(root->right,p)-p;
        root->val += p;
        return root->left?BstToGst(root->left,root->val):root->val;
    }

    TreeNode* bstToGst(TreeNode* root) {
        BstToGst(root);
        return root;
    }
};
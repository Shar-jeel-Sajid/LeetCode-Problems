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

    void compensate(TreeNode*root,int val,bool a = false) {
        if(root->left) compensate(root->left,val);
        if(root->right) compensate(root->right,val,true);
        if(a) root->val += val;
    }

    TreeNode* bstToGst(TreeNode* root) {
        BstToGst(root);
        // if(root->left)
            // compensate(root->left,root->val);
        return root;
    }
};
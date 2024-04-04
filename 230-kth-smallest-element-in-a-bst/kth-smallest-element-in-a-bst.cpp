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
    int position(TreeNode* root) {
        return root ? 1 + position(root->left) + position(root->right): 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        int pos = 1 + position(root->left);
        if(pos == k)
            return root->val;
        if(pos > k)
            return kthSmallest(root->left , k);
        return kthSmallest(root->right , k - pos);
    }
};
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
    bool isLeaf(TreeNode* node) {
        return !(node->left || node->right);
    }

    int sumNumbers(TreeNode* root,int k = 0) {
        int val = k*10 + root->val;
        if(isLeaf(root))
            return val;
        int sum = 0;
        if(root->left)
            sum += sumNumbers(root->left,val);
        if(root->right)
            sum += sumNumbers(root->right,val);
        return sum;
    }
};
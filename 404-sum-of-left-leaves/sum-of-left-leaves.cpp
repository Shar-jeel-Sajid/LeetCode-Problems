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

    int sumOfLeftLeaves(TreeNode* root) {
        if(isLeaf(root))
            return 0;
        int sum = 0;
        if(root->left) {
            if(isLeaf(root->left))
                sum  = root->left->val;
            else
                sum = sumOfLeftLeaves(root->left);
        }
        if(root->right) {
            if(!isLeaf(root->right))
                sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};
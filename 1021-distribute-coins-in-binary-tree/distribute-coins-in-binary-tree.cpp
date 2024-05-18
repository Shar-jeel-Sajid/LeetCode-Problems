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
int moves = 0;
class Solution {
public:
    int moves = 0;
    int distributeCoins(TreeNode* root,bool ishead = true) {
       if(!root) return 0;
        int coins = root->val;
        coins += distributeCoins(root->left,false);
        coins += distributeCoins(root->right,false);
        moves += abs(coins-1);
        if(ishead)
            return moves;
        return coins-1;
    }
};
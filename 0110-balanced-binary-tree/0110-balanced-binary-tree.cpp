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
    int solve(TreeNode* root){
        if(!root) return 0;

        int left_height = solve(root->left);
        if(left_height == -1){
            return -1;
        }

        int right_height = solve(root->right);
        if(right_height == -1){
            return -1;
        }

        if(abs(left_height - right_height) > 1){
            return -1;
        }

        return 1 + max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};
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
    string str = "";

    void DFS(TreeNode* root){
        if(!root){
            return;
        }

        // D
        str += to_string(root->val);
        if(!root->left && !root->right){
            return;
        }

        // L
        str += '(';
        DFS(root->left);
        str += ')';

        // R
        if(root->right) str += '(';
        DFS(root->right);
        if(root->right) str += ')';
    }

    string tree2str(TreeNode* root) {
        DFS(root);
        return str;
    }
};
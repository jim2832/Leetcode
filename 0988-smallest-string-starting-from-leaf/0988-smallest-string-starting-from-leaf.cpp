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
    string result = "{";

    void DFS(TreeNode* root, string str){
        if(!root) return;

        str = char('a' + root->val) + str;

        // leaf
        if(!root->left && !root->right){
            result = min(result, str);
        }

        DFS(root->left, str);
        DFS(root->right, str);
    }

    string smallestFromLeaf(TreeNode* root) {
        DFS(root, "");
        return result;
    }
};
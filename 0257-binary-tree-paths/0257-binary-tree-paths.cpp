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
    void search(TreeNode* root, vector<string> &result, string str){
        if(root->left == NULL && root->right == NULL){
            result.push_back(str);
            return;
        }

        if(root->left){
            search(root->left, result, str + "->" + to_string(root->left->val));
        }
        if(root->right){
            search(root->right, result, str + "->" + to_string(root->right->val));
        }
    }

public:
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL){
            return result;
        }

        search(root, result, to_string(root->val));

        return result;
    }
};
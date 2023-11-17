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
    void inorder(TreeNode* root, vector<int>& path){
        if(!root) return;
        inorder(root->left, path);
        path.push_back(root->val);
        inorder(root->right, path);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> path;
        inorder(root, path);
        
        int min = INT_MAX;
        for(int i=1; i<path.size(); i++){
            if(min > path[i] - path[i-1]){
                min = path[i] - path[i-1];
            }
        }

        return min;
    }
};
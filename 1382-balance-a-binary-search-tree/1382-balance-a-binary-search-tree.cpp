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

// [1,2,3,4]

class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*> &vec){
        if(!root){
            return;
        }
        inorder(root->left, vec);
        vec.push_back(root);
        inorder(root->right, vec);
    }

    TreeNode* build(vector<TreeNode*> &vec, int left, int right){
        if(left > right){
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        vec[mid]->left = build(vec, left, mid-1);
        vec[mid]->right = build(vec, mid+1, right);
        
        return vec[mid];
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> path;
        inorder(root, path);
        return build(path, 0, path.size()-1);
    }
};
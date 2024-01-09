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
    void DFS(TreeNode* root, vector<int> &leaves){
        if(!root){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            leaves.push_back(root->val);
        }
        DFS(root->left, leaves);
        DFS(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2;
        DFS(root1, tree1);
        DFS(root2, tree2);
        if(tree1.size() != tree2.size()){
            return false;
        }
        for(int i=0; i<tree1.size(); i++){
            if(tree1[i] != tree2[i]){
                return false;
            }
        }

        return true;
    }
};
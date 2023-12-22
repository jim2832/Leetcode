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
    int result = -INT_MAX;

    void DFS(TreeNode* root, vector<TreeNode*> &parents){
        if(!root){
            return;
        }

        // update the maximum different
        for(auto &node:parents){
            result = max(result, abs(root->val - node->val));
        }

        // add the current node into parent vector
        parents.push_back(root);

        // DFS the left and right tree
        DFS(root->left, parents);
        DFS(root->right, parents);

        // backtracking
        parents.pop_back();
    }

    int maxAncestorDiff(TreeNode* root) {
        vector<TreeNode*> temp;
        DFS(root, temp);

        return result;
    }
};
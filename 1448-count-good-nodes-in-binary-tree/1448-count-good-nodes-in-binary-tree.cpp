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
    int count = 0;

    void goodNodes(TreeNode* root, int current_max){
        if(!root){
            return;
        }
        if(root->val >= current_max){
            count++;
        }
        current_max = max(root->val, current_max);

        goodNodes(root->left, current_max);
        goodNodes(root->right, current_max);
    }

    int goodNodes(TreeNode* root) {
        goodNodes(root, root->val);
        return count;
    }
};
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
    void reverseOddLevels(TreeNode* root1, TreeNode* root2, int depth) {
        if(!root1 || !root2){
            return;
        }
        if(depth % 2 == 1){
            swap(root1->val, root2->val);
        }
        reverseOddLevels(root1->left, root2->right, depth+1);
        reverseOddLevels(root1->right, root2->left, depth+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseOddLevels(root->left, root->right, 1);
        return root;
    }
};
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
    int sum = 0;

    void in_order_traverse(TreeNode* root, int low, int high){
        if (root == nullptr)
        return;

        in_order_traverse(root->left, low, high);
        if(root->val <= high && root->val >= low){
            sum += root->val;
        }
        in_order_traverse(root->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        in_order_traverse(root, low, high);

        return sum;
    }
};
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

    // return the subtree sum of root
    int traverse(TreeNode* root, int &subtree_count){
        if(root == nullptr){
            return 0;
        }
        subtree_count++;
        return root->val + traverse(root->left, subtree_count) + traverse(root->right, subtree_count);
    }

    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int subtree_count = 0;
        int subtree_sum = traverse(root, subtree_count);

        if(root->val == subtree_sum/subtree_count){
            count++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);

        return count;
    }
};
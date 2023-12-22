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

    void traverse(TreeNode* root, TreeNode* parent, TreeNode* grandparent) {
        if(root != nullptr){
            // Process the current node
            if(grandparent && grandparent->val % 2 == 0){
                sum += root->val;
            }

            // Recursively traverse the left and right subtrees
            // 現在點的父親會變成下個點的祖父，而這個點本身會變成父親
            traverse(root->left, root, parent);
            traverse(root->right, root, parent);
        }
    }

    int sumEvenGrandparent(TreeNode* root) {
        traverse(root, nullptr, nullptr);
        return sum;
    }
};
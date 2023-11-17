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
    bool the_same(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr){
            return true;
        }
        if(root1 == nullptr || root2 == nullptr){ //其中一個為空但另一個不為空
            return false;
        }
        return (root1->val == root2->val) && the_same(root1->left, root2->right) && the_same(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return the_same(root->left, root->right);
    }
};
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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int post_start, int post_end){
        if(in_start > in_end || post_start > post_end){
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[post_end]);

        int inorder_root_index;
        for(int i=in_start; i<=in_end; i++){
            if(inorder[i] == root->val){
                inorder_root_index = i;
            }
        }

        int left_size = inorder_root_index - in_start;
        int right_size = in_end - inorder_root_index;

        root->left = build(inorder, postorder, in_start, inorder_root_index-1, post_start, post_start + left_size - 1);
        root->right = build(inorder, postorder, inorder_root_index+1, in_end, post_end - right_size, post_end - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
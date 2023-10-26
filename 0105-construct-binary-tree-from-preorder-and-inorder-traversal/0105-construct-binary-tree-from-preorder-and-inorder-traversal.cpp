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
    int preorder_index = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preorder_index]);
        preorder_index++;

        int index;
        for(int i=start; i<=end; i++){
            if(inorder[i] == root->val){
                index = i;
                break;
            }
        }

        root->left = build(preorder, inorder, start, index-1);
        root->right = build(preorder, inorder, index+1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};
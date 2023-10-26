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
    int pre_index = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int start, int end) {
        if(start > end || pre_index >= preorder.size()){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_index]);
        pre_index++;

        if(start == end || pre_index >= preorder.size())
            return root;

        int post_root_index;
        for(int i=start; i<=end; i++){
            if(postorder[i] == preorder[pre_index]){
                post_root_index = i;
            }
        }

        root->left = constructFromPrePost(preorder, postorder, start, post_root_index);
        root->right = constructFromPrePost(preorder, postorder, post_root_index+1, end-1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return constructFromPrePost(preorder, postorder, 0, preorder.size()-1);
    }
};
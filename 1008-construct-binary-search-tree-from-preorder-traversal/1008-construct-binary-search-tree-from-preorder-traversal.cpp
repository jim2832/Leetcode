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
    TreeNode* bstFromPreorder(vector<int>& preorder, int start, int end){
        if(start > end){
            return nullptr;
        }

        // build the root
        TreeNode* root = new TreeNode(preorder[start]);

        // find the index of the root
        int root_index = start;
        for(int i=start+1; i<=end; i++){
            if(preorder[i] < root->val){
                root_index = i;
            }
            else
                break;
        }

        root->left = bstFromPreorder(preorder, start+1, root_index);
        root->right = bstFromPreorder(preorder, root_index+1, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder){
        return bstFromPreorder(preorder, 0, preorder.size()-1);
    }
};
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end){
        int max = -INT_MAX;
        int index;

        if(start > end)
            return nullptr;
        
        // find the maximum
        for(int i=start; i<=end; i++){
            if(max < nums[i]){
                max = nums[i];
                index = i;
            }
        }

        TreeNode* root = new TreeNode(max);
        root->left = constructMaximumBinaryTree(nums, start, index-1);
        root->right = constructMaximumBinaryTree(nums, index+1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size()-1);
    }
};
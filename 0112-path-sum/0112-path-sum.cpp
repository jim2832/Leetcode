class Solution {
    public:
        bool root_to_leaf_sum(TreeNode* root, int targetSum, int sum){
            if(root == nullptr){
                return false;
            }
            //終止條件
            if(root->left == nullptr && root->right == nullptr){
                sum += root->val;
                if(sum == targetSum){
                    return true;
                }
            }
            return root_to_leaf_sum(root->left, targetSum, sum + root->val) || root_to_leaf_sum(root->right, targetSum, sum + root->val);
        }

        bool hasPathSum(TreeNode* root, int targetSum) {
            int sum = 0;
            return root_to_leaf_sum(root, targetSum, sum);
        }
};
class Solution {
    public:
        bool result;

        int check_balance(TreeNode* root){
            if(root == nullptr){
                return 0;
            }
            if(!result){
                return 0;
            }
            int left_sub_tree = check_balance(root->left); //往左子樹走訪
            int right_sub_tree = check_balance(root->right); //往右子樹走訪
            if(abs(left_sub_tree - right_sub_tree) > 1){
                result = false;
            }
            return 1 + max(left_sub_tree, right_sub_tree);
        }

        bool isBalanced(TreeNode* root) {
            result = true;
            int temp = check_balance(root);
            return result;
        }
};
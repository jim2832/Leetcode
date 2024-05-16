class Solution {
public:
    TreeNode* bstToGst(TreeNode* root, int& num){
        if(!root) return nullptr;

        bstToGst(root->right, num);
        root->val += num;
        num = root->val;
        bstToGst(root->left, num);
        
        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int num = 0;
        bstToGst(root, num);
        return root;
    }
};
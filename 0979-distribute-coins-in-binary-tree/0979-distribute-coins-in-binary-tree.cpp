class Solution {
public:
    int result = 0;

    int DFS(TreeNode* root){
        if(!root) return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        result += abs(left) + abs(right);
        return root->val + left + right - 1;
    }

    int distributeCoins(TreeNode* root) {
        DFS(root);
        return result;
    }
};
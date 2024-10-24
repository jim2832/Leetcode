class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2 || root1->val != root2->val) return false;

        bool tree1_left, tree1_right, tree2_left, tree2_right;
        tree1_left = flipEquiv(root1->left, root2->left);
        tree1_right = flipEquiv(root1->right, root2->right);
        tree2_left = flipEquiv(root1->left, root2->right);
        tree2_right = flipEquiv(root1->right, root2->left);

        return (tree1_left && tree1_right) || (tree2_left && tree2_right);
    }
};
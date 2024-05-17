class Solution {
public:
    bool isLeaf(TreeNode* root){
        return !(root->left) && !(root->right);
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if(isLeaf(root) && root->val == target) return nullptr;

        return root;
    }
};
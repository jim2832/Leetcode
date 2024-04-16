class Solution {
public:
    void DFS(TreeNode* root, int val, int depth, int level){
        if(!root) return;
        if(level < depth - 1){
            DFS(root->left, val, depth, level+1);
            DFS(root->right, val, depth, level+1);
        }
        else{
            // the left child of root
            TreeNode* node = root->left;
            root->left = new TreeNode(val);
            root->left->left = node;

            // the right child of root
            node = root->right;
            root->right = new TreeNode(val);
            root->right->right = node;
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // exception
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        DFS(root, val, depth, 1);
        return root;
    }
};
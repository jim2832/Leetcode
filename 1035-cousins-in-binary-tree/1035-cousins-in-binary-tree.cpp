class Solution {
public:
    int x_par, x_dep, y_par, y_dep;

    void DFS(TreeNode* root, int &x, int &y, int depth, int parent){
        if(!root) return;

        if(root->val == x){
            x_dep = depth;
            x_par = parent;
        }
        if(root->val == y){
            y_dep = depth;
            y_par = parent;
        }

        DFS(root->left, x, y, depth+1, root->val);
        DFS(root->right, x, y, depth+1, root->val);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        DFS(root, x, y, 0, root->val);
        return x_dep == y_dep && x_par != y_par;
    }
};
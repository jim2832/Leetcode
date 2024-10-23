class Solution{
public:
    vector<int> depth_sums;

    void BFS(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth_sums.push_back(sum);
        }
    }

    void DFS(TreeNode* root, int depth, int parent_sum){
        if(!root) return;

        if(depth == 0) root->val = 0;
        else root->val = depth_sums[depth] - parent_sum;

        int child_sum = 0;
        if(root->left) child_sum += root->left->val;
        if(root->right) child_sum += root->right->val;

        DFS(root->left, depth + 1, child_sum);
        DFS(root->right, depth + 1, child_sum);
    }

    TreeNode* replaceValueInTree(TreeNode* root){
        BFS(root);
        DFS(root, 0, 0);
        return root;
    }
};

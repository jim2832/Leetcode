class Solution {
public:
    unordered_map<int, int> left, right, heights;

    int cal_height(TreeNode* root) {
        if(!root) return 0;

        int left_height = cal_height(root->left);
        int right_height = cal_height(root->right);
        
        left[root->val] = left_height;
        right[root->val] = right_height;
        
        return max(left_height, right_height) + 1;
    }

    void DFS(TreeNode* root, int maxi, int depth) {
        if(!root) return;

        heights[root->val] = maxi;

        int left_max = max(maxi, depth + right[root->val]);
        int right_max = max(maxi, depth + left[root->val]);
        
        DFS(root->left, left_max, depth + 1);
        DFS(root->right, right_max, depth + 1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        cal_height(root);
        DFS(root->left, right[root->val], 1);
        DFS(root->right, left[root->val], 1);
        
        vector<int> ans;
        for(auto &query : queries){
            ans.push_back(heights[query]);
        }
        
        return ans;
    }
};

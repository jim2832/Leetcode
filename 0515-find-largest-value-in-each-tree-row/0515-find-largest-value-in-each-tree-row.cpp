class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int current_max = INT_MIN;
            while(n--){
                auto current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                current_max = max(current_max, current->val);
            }
            result.push_back(current_max);
        }

        return result;
    }
};
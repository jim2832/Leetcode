class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int maxi = INT_MIN;
            int n = q.size();
            while(n--){
                auto current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                maxi = max(maxi, current->val);
            }
            result.push_back(maxi);
        }

        return result;
    }
};
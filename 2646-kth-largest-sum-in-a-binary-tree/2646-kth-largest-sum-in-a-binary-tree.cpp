class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return -1;

        vector<long long> sums;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            long long sum = 0;
            for(int i=0; i<n; i++){
                auto current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                sum += current->val;
            }
            sums.push_back(sum);
        }

        sort(sums.begin(), sums.end(), greater<long long>());

        return sums.size() < k ? -1 :sums[k-1];
    }
};
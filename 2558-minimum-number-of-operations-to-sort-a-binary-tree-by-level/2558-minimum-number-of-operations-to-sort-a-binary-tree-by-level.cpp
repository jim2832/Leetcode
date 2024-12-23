class Solution {
public:
    int minimumSwaps(vector<int>& vec) {
        int n = vec.size();
        vector<pair<int, int>> paired(n);
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++) {
            paired[i] = {vec[i], i};
        }

        sort(paired.begin(), paired.end());

        int swaps = 0;

        for(int i=0; i<n; i++) {
            if(visited[i] || paired[i].second == i) continue;

            int cycle_length = 0;
            int j = i;
            while(!visited[j]) {
                visited[j] = true;
                j = paired[j].second;
                cycle_length++;
            }

            if(cycle_length > 1) {
                swaps += (cycle_length - 1);
            }
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        if(!root) return 0;

        int count = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> cur;
            while(n--){
                auto current = q.front();
                q.pop();
                cur.push_back(current->val);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            count += minimumSwaps(cur);
        }

        return count;
    }
};
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> result, idxs;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            idxs.push_back(pq.top().second);
            pq.pop();
        }

        sort(idxs.begin(), idxs.end());

        for(auto &idx : idxs){
            result.push_back(nums[idx]);
        }

        return result;
    }
};
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> idxs, result;
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<nums.size(); i++){
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
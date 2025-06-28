class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_set<int> us;
        int n = nums.size();
        vector<int> result;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            auto temp = pq.top();
            pq.pop();
            us.insert(temp.second);
        }

        for(int i = 0; i < n ; i++){
            if(us.count(i)){
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};
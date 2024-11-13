class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long result = 0;
        
        for(int i=0; i<nums.size(); i++){
            int l = lower - nums[i];
            int u = upper - nums[i];
            auto it = lower_bound(nums.begin()+i+1, nums.end(), l);
            auto gt = upper_bound(nums.begin()+i+1, nums.end(), u);
            result += gt - it;
        }

        return result;
    }
};
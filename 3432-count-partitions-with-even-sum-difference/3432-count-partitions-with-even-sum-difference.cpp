class Solution {
public:
    int countPartitions(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        for(int i = 0; i < n - 1; i++){
            left += nums[i];
            right -= nums[i];
            if((left - right) % 2 == 0){
                seen.insert(left - right);
            }
        }

        return seen.size();
    }
};
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL), prefix_sum = 0;
        int count = 0;
        
        for(int i=0; i<nums.size()-1; i++){
            prefix_sum += nums[i];
            sum -= nums[i];
            if(prefix_sum >= sum) count++;
        }

        return count;
    }
};
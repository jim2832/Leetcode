class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0, prefix_sum = 0;
        int count = 0;

        for(auto &num : nums) sum += num;
        
        for(int i=0; i<nums.size()-1; i++){
            prefix_sum += nums[i];
            sum -= nums[i];
            if(prefix_sum >= sum) count++;
        }

        return count;
    }
};
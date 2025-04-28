class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int n = nums.size();
        long long sum = 0, result = 0;

        for(int start = 0, end = 0; end < n; end++){
            sum += nums[end];

            while(sum > goal){
                sum -= nums[start++];
            }

            result += end - start + 1;
        }

        return result;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};
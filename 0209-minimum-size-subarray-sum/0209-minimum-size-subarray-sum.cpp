class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX; // result
        int sum = 0, windowStart = 0;

        for(int windowEnd=0; windowEnd<nums.size(); windowEnd++){
            sum += nums[windowEnd];

            // if the sum >= target, then reduce the window size
            while(sum >= target){
                len = min(len, windowEnd - windowStart + 1);
                sum -= nums[windowStart];
                windowStart++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};
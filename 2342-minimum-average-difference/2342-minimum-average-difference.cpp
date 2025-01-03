class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL), prefixSum = 0;
        int n = nums.size(), minDiff = INT_MAX, result = 0;

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];
            long long leftAvg = prefixSum / (i + 1);
            long long rightAvg = (i < n - 1) ? (totalSum - prefixSum) / (n - i - 1) : 0;

            int diff = abs(leftAvg - rightAvg);
            if(diff < minDiff){
                minDiff = diff;
                result = i;
            }
        }

        return result;
    }
};

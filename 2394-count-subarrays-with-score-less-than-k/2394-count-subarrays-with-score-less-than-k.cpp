class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum = 0, count = 0;

        for(int start = 0, end = 0; end < n; end++){
            sum += nums[end];

            while(sum * (end - start + 1) >= k){
                sum -= nums[start];
                start++;
            }

            count += end - start + 1;
        }

        return count;
    }
};
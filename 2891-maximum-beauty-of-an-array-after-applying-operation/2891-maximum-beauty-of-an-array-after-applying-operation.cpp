class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), start = 0, ans = INT_MIN;

        for(int end = 0; end < n; end++){
            while(nums[end] - nums[start] > 2 * k) start++;
            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;

        sort(nums.begin(), nums.end());

        int max = -INT_MAX;
        for(int i=0; i<n-1; i++){
            int diff = abs(nums[i] - nums[i+1]);
            max = diff > max ? diff : max;
        }

        return max;
    }
};
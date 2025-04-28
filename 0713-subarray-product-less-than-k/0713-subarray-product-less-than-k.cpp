class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int prod = 1, count = 0;

        for(int start = 0, end = 0; end < n; end++){
            prod *= nums[end];

            while(prod >= k){
                prod /= nums[start++];
            }

            count += end - start + 1;
        }

        return count;
    }
};
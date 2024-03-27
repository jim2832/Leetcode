class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1){
            return 0;
        }

        int n = nums.size();
        int start = 0;
        int product = 1;
        int count = 0;

        for(int end=0; end<n; end++){
            product *= nums[end];

            // decrease the window size
            while(product >= k){
                product /= nums[start];
                start++;
            }

            count += end - start + 1;
        }

        return count;
    }
};
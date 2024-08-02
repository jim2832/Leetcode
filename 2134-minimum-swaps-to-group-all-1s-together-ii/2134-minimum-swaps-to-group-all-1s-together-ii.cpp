class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // count the number of 1s
        int one_count = 0;
        for(auto &num : nums){
            if(num == 1) one_count++;
        }

        // expand the vevtor to avoid circular array
        for(int i=0; i<one_count; i++){
            nums.push_back(nums[i]);
        }

        // count the zeros of origin window
        int zero_count = 0;
        for(int i=0; i<one_count; i++){
            if(nums[i] == 0) zero_count++;
        }

        // sliding window
        int window_start = 0, window_end = one_count - 1;
        int n = nums.size(), ans = zero_count;
        while(window_end < n - 1){
            if(nums[window_start++] == 0) zero_count--;
            if(nums[++window_end] == 0) zero_count++;

            ans = min(ans, zero_count);
        }
        
        return ans;
    }
};
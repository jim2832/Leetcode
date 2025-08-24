class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0, max_len = 0;
        
        for(int start = 0, end = 0; end < nums.size(); end++){
            if(nums[end] == 0){
                zero++;
            }

            while(zero > 1){
                if(nums[start] == 0){
                    zero--;
                }
                start++;
            }

            max_len = max(max_len, end - start);
        }

        return max_len;
    }
};
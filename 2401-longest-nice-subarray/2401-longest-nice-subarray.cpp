class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int max_size = 0;
        int num = 0;

        for(int end=0; end<n; end++){
            // restore the 1 bit record
            while((num & nums[end]) != 0){
                num ^= nums[start];
                start++;
            }

            // record the position of 1 bit
            num |= nums[end];

            // update the maximal size
            max_size = max(max_size, end - start + 1);
        }

        return max_size;
    }
};
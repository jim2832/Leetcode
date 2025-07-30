class Solution{
public:
    int longestSubarray(vector<int>& nums){
        int target = *max_element(nums.begin(), nums.end());
        int max_len = 0;
        int cur_len = 0;

        for(int num : nums){
            if(num == target){
                cur_len++;
                max_len = max(max_len, cur_len);
            }
            else{
                cur_len = 0;
            }
        }

        return max_len;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int max_ele = *max_element(nums.begin(), nums.end());
        int max_freq = 0;
        long long result = 0;

        for(int start = 0, end = 0; end < n; end++){
            if(nums[end] == max_ele){
                max_freq++;
            }

            while(max_freq >= k){
                if(nums[start++] == max_ele){
                    max_freq--;
                }
            }

            result += start;
        }

        return result;
    }
};
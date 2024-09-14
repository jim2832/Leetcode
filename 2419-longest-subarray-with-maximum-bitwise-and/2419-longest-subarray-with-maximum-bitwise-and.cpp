class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        int result = INT_MIN;
        int i = 0;
        int n = nums.size();
        
        for(auto &num : nums){
            maxi = max(maxi, num);
        }

        while(i < n){
            int temp = 0;
            while(i < n && nums[i] == maxi){
                temp++;
                i++;
            }
            result = max(result, temp);
            i++;
        }

        return result;
    }
};
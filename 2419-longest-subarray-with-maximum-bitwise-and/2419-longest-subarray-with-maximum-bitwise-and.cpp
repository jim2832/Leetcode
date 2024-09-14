/*
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        int result = INT_MIN;
        int i = 0, n = nums.size(), temp;
        
        for(auto &num : nums){
            maxi = max(maxi, num);
        }

        while(i < n){
            temp = 0;
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
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0, temp = 0;
        int maxi = *max_element(nums.begin(), nums.end());

        for(auto &num : nums){
            if(num == maxi) result = max(result, ++temp);
            else temp = 0;
        }

        return result;
    }
};
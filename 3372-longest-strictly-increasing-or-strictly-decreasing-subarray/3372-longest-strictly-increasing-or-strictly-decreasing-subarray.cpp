class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1, maxi = 1;

        for(int i=0; i<n-1; i++){
            // strictly increasing
            if(nums[i] > nums[i+1]){
                inc++;
                dec = 1;
            }
            // strictly decreasing
            else if(nums[i] < nums[i+1]){
                dec++;
                inc = 1;
            }
            else{
                inc = dec = 1;
            }
            maxi = max(maxi, max(inc, dec));
        }

        return maxi;
    }
};
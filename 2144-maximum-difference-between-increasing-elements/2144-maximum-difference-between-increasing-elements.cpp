class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(i < j && nums[i] < nums[j]){
                    maxi = max(maxi, nums[j] - nums[i]);
                }
            }
        }

        return maxi == INT_MIN ? -1 : maxi;
    }
};
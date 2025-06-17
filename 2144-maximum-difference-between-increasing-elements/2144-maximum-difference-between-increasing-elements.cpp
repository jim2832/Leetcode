class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = -1;
        int current_min = nums[0];
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > current_min){
                maxi = max(maxi, nums[i] - current_min);
            }
            else{
                current_min = nums[i];
            }
        }

        return maxi;
    }
};
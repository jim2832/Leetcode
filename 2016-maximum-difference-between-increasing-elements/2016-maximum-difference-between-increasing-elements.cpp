class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max = -1;
        int current_min = nums[0];
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > current_min){
                if(max < nums[i] - current_min){
                    max = nums[i] - current_min;
                }
            }
            else{
                current_min = nums[i];
            }
        }

        return max;
    }
};
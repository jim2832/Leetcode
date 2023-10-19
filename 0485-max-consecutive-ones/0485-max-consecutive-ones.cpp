class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max = -INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]){
                count++;
            }
            else{
                count = 0;
            }
            max = count > max ? count : max;
        }

        return max;
    }
};
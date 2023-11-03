class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lower = 0, upper = nums.size()-1;
        while(lower < upper){
            int mid = lower + (upper - lower) / 2;
            if(mid % 2 == 1){
                mid--;
            }
            // the single number will appear on the left side
            if(nums[mid] != nums[mid+1]){
                upper = mid;
            }
            // the single number will appear on the right side
            else{
                lower = mid + 2;
            }
        }

        return nums[lower];
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size()-1;

        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            // case 1
            if(target < nums[mid]){
                upper = mid - 1;
            }
            // case 2
            else if(target > nums[mid]){
                lower = mid + 1;
            }
            // case 3
            else{
                return mid;
            }
        }

        return -1;
    }
};
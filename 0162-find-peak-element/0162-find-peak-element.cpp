class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size()-1;

        while(lower < upper){
            int mid = lower + (upper - lower) / 2;
            // 比右邊的高 -> 往左邊找有沒有更高
            if(nums[mid] > nums[mid+1]){
                upper = mid;
            }
            // 比右邊的低 -> 往右邊找有沒有更高
            else{
                lower = mid + 1;
            }
        }

        return lower;
    }
};
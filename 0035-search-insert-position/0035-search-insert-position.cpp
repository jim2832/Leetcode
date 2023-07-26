class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return Binary_search(nums, 0, nums.size()-1, target);
    }

    int Binary_search(vector<int> &nums, int lower, int upper, int target){
        if(upper < lower){
            return lower;
        }
        
        int mid = lower + (upper - lower) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            return Binary_search(nums, lower, mid-1, target);
        }
        else{
            return Binary_search(nums, mid+1, upper, target);
        }
    }
};
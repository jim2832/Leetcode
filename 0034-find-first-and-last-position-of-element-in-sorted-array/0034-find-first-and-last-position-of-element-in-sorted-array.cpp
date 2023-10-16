class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = front(nums, target);
        int second = back(nums, target);

        return {first, second};
    }

    int front(vector<int>& nums, int target){
        int n = nums.size();
        int lower = 0;
        int upper = n;
        int res = -1;

        while(lower < upper){
            int mid = lower + (upper - lower) / 2;
            // case 1
            if(nums[mid] == target){
                res = mid;
                upper = mid;
            }
            // case 2
            else if(nums[mid] < target){
                lower = mid + 1;
            }
            // case 3
            else{
                upper = mid;
            }
        }

        return res;
    }

    int back(vector<int>& nums, int target){
        int n = nums.size();
        int lower = 0;
        int upper = n;
        int res = -1;

        while(lower < upper){
            int mid = lower + (upper - lower) / 2;
            // case 1
            if(nums[mid] == target){
                res = mid;
                lower = mid+1;
            }
            // case 2
            else if(nums[mid] < target){
                lower = mid + 1;
            }
            // case 3
            else{
                upper = mid;
            }
        }

        return res;
    }
};
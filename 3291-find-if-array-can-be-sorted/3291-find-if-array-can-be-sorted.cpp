class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int prev_max = INT_MIN;
        int cur_min = nums[0], cur_max = nums[0];
        int bits = __builtin_popcount(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(__builtin_popcount(nums[i]) == bits){
                cur_min = min(cur_min, nums[i]);
                cur_max = max(cur_max, nums[i]);
            }
            else{ // 遇到1個數不同的，下一個segment
                if(prev_max > cur_min) return false;
                // 更新資訊
                prev_max = cur_max;
                cur_min = nums[i];
                cur_max = nums[i];
                bits = __builtin_popcount(nums[i]);
            }
        }

        return prev_max < cur_min;
    }
};
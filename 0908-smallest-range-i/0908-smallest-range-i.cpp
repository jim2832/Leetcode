// [0,10], k=2 -> (10-0) - 2*2 = 0
// [2,10], k=3 -> (10-2) - 2*3 = 2

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return max(nums[nums.size()-1] - nums[0] - 2*k, 0);
    }
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = (nums.size() - 1) / 2;
        int result = 0;

        sort(nums.begin(), nums.end());

        for(auto &num : nums){
            result += abs(num - nums[mid]);
        }

        return result;
    }
};
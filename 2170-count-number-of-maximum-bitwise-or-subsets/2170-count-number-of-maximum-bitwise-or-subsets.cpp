class Solution {
public:
    void backtracking(vector<int> &nums, int current, int target, int idx, int &count){
        if(idx == nums.size()){
            if(current == target){
                count++;
            }
            return;
        }
        backtracking(nums, current | nums[idx], target, idx+1, count);
        backtracking(nums, current, target, idx+1, count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0, count = 0;

        for(auto &num : nums){
            target |= num;
        }

        backtracking(nums, 0, target, 0, count);

        return count;
    }
};
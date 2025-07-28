class Solution {
public:
    void solve(vector<int>& nums, int index, int current, int target, int &count){
        if(index == nums.size()){
            if(current == target){
                count++;
            }
            return;
        }
        solve(nums, index + 1, current | nums[index], target, count);
        solve(nums, index + 1, current, target, count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0, count = 0;

        for(int num : nums){
            target |= num;
        }

        solve(nums, 0, 0, target, count);
        
        return count;
    }
};
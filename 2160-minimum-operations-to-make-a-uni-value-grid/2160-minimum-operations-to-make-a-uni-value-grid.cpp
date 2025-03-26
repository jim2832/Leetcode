class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto &g : grid){
            for(auto &ele : g){
                nums.push_back(ele);
            }
        }

        sort(nums.begin(), nums.end());

        // determine whether it is valid
        for(auto &num : nums){
            if(abs(num - nums[0]) % x != 0) return -1;
        }

        // find median
        int median = nums[nums.size() / 2];
        int count = 0;

        for(auto &num : nums){
            count += abs(num - median) / x;
        }

        return count;
    }
};
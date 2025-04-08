class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        unordered_set<int> seen;
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(seen.count(nums[i])) {
                return(i + 1 + 2) / 3;
            }
            seen.insert(nums[i]);
        }
        return 0;
    }
};

class Solution {
public:
    void solver(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>> &result){
        result.push_back(subset);
        for(int i = index; i < nums.size(); i++){
            subset.push_back(nums[i]);
            solver(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        solver(nums, 0, subset, result);
        return result;
    }
};
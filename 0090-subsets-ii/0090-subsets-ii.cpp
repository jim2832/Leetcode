class Solution {
public:
    void solver(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>> &result, set<vector<int>> &us){
        if(!us.count(subset)){
            result.push_back(subset);
            us.insert(subset);
        }
        for(int i = index; i < nums.size(); i++){
            subset.push_back(nums[i]);
            solver(nums, i + 1, subset, result, us);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> us;
        vector<vector<int>> result;
        vector<int> subset;
        solver(nums, 0, subset, result, us);
        return result;
    }
};
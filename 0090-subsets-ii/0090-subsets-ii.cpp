class Solution {
public:
    void solver(vector<int>& nums, int index, vector<int>& sub, vector<vector<int>> &subs){
        if(count(subs.begin(), subs.end(), sub) <= 0){
            subs.push_back(sub);
        }
        for(int i=index; i<nums.size(); i++){
            sub.push_back(nums[i]);
            solver(nums, i+1, sub, subs);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;
        solver(nums, 0, sub, subs);

        return subs;
    }
};
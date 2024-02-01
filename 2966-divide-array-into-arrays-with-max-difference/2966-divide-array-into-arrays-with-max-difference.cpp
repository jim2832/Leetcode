/*

nums = [1,3,4,8,7,9,3,5,1]
sort
nums = [1,1,3,3,4,5,7,8,9]

*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int i = 0;
        while(i < nums.size()){
            if(nums[i+2] - nums[i] > k){
                return {};
            }
            result.push_back({nums[i], nums[i+1], nums[i+2]});
            i += 3;
        }

        return result;
    }
};
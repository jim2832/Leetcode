class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        
        vector<int> result;
        map<int, vector<int>> hash;

        for(int i=0; i<n; i++){
            for(int j=0; j<nums[i].size(); j++){
                hash[i+j].push_back(nums[i][j]);
            }
        }

        for(auto &pair:hash){
            for(int i=pair.second.size()-1; i>=0; i--){
                result.push_back(pair.second[i]);
            }
        }
        
        return result;
    }
};
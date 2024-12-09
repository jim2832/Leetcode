class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<bool> result;

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1];
            if((nums[i-1] & 1) == (nums[i] & 1)) prefix[i]++;
        }

        for(auto &query : queries){
            result.push_back(prefix[query[0]] == prefix[query[1]]);
        } 

        return result;
    }
};
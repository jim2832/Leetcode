class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);

        for(auto &query : queries){
            int l = query[0], r = query[1];
            diff[l]++;
            if(r + 1 < n + 1){
                diff[r+1]--;
            }
        }

        int prefix_sum = 0;
        for(int i = 0; i < n; i++){
            prefix_sum += diff[i];
            if(nums[i] > prefix_sum) return false;
        }

        return true;
    }
};
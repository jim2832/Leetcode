class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int min_len = INT_MAX;

        for(int i=0; i<n; i++){
            int or_val = 0;
            for(int j=i; j<n; j++){
                or_val |= nums[j];
                if(or_val >= k){
                    min_len = min(min_len, j-i+1);
                }
            }
        }

        return min_len == INT_MAX ? -1 : min_len;
    }
};
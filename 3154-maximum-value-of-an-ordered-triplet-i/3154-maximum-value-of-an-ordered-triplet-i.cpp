class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long max_i = nums[0];
        long long max_ij = INT_MIN;
        long long max_ijk = 0;
        
        for(int i=1; i<n-1; i++){
            max_ij = max(max_ij, max_i - nums[i]);
            max_i = max(max_i, (long long)nums[i]);
            max_ijk = max(max_ijk, (long long)max_ij * nums[i+1]);
        }

        return max_ijk;
    }
};
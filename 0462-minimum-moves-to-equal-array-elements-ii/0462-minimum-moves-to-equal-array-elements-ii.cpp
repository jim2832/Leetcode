class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ope = 0;
        int n = nums.size();
        int mid = (n-1) / 2;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            ope += abs(nums[i] - nums[mid]);
        }

        return ope;
    }
};
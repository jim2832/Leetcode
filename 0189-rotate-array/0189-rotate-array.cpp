class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec;

        if(n < k) k %= n;

        for(int i=n-k; i<n; i++){
            vec.push_back(nums[i]);
        }

        for(int i=n-1; i>=0; i--){
            nums[i] = i >= k ? nums[i-k] : vec[i];
        }
    }
};
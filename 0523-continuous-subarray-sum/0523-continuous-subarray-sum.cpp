class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, bool> hash;
        int sum = 0, temp = 0;

        for(int i=0; i<n; i++){
            sum = (sum + nums[i]) % k;
            if(hash[sum]) return true;
            hash[temp] = true;
            temp = sum;
        }

        return false;
    }
};
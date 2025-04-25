class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int prefix = 0;
        unordered_map<int, long long> hash;
        hash[0] = 1;
        long long result = 0;

        for(auto &num : nums){
            if(num % modulo == k) prefix++;
            int target = (prefix % modulo + modulo - k) % modulo;
            result += hash[target];
            hash[prefix % modulo]++;
        }

        return result;
    }
};
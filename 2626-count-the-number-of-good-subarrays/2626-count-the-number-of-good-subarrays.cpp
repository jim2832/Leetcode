class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, pairs = 0;
        long long result = 0;
        unordered_map<int, int> hash;

        for(int end=0; end<n; end++){
            pairs += hash[nums[end]];
            hash[nums[end]]++;

            while(pairs >= k){
                result += (n - end);
                pairs -= hash[nums[start]] - 1;
                hash[nums[start]]--;
                start++;
            }
        }

        return result;
    }
};
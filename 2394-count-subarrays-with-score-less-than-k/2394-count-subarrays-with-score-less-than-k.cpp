class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int start = 0, len = 0;
        long long score = 0;
        long long result = 0;
        
        for(int end = 0; end < n; end++){
            if(len) score /= len;
            len++;
            score = (score + nums[end]) * len;

            while(score >= k){
                score /= len;
                len--;
                score = (score - nums[start]) * len;
                start++;
            }

            result += end - start + 1;
        }

        return result;
    }
};
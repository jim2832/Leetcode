class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long current_max = -INT_MAX;
        vector<long long> result(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(current_max < nums[i]){
                current_max = nums[i];
            }
            nums[i] += current_max;
            result[i] = (long long) nums[i];
        }

        for(int i=1; i<result.size(); i++){
            result[i] += result[i-1];
        }

        return result;
    }
};
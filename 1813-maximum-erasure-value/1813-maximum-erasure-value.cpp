class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        unordered_map<int, int> hashMap;

        for(int start = 0, end = 0; end < nums.size(); end++){
            hashMap[nums[end]]++;
            sum += nums[end];

            while(hashMap[nums[end]] > 1){
                hashMap[nums[start]]--;
                sum -= nums[start];
                start++;
            }

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
/*
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
transfer into
nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
*/

class Solution {
public:
    int rev(int number) {
        int reversedNumber = 0;

        while (number != 0) {
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10;
        }

        return reversedNumber;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long, long> hash;
        long long count = 0;
        
        for(int i=0; i<n; i++){
            int diff = nums[i] - rev(nums[i]);
            if(hash.count(diff)){
                count += hash[diff];
            }
            hash[diff]++;
        }

        return count % 1000000007;
    }
};
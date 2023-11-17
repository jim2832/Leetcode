/*
j - i != nums[j] - nums[i]
tranfer into
nums[i] - i != nums[j] - j
*/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        // count the all possible number
        long long total = 0;
        for(int i=1; i<n; i++){
            total += i;
        }

        long long good_pair = 0;
        unordered_map<int, int> hash;
        for(int i=0; i<n; i++){
            long long diff = nums[i] - i;
            if(hash.count(diff)){
                good_pair += hash[diff];
            }
            hash[diff]++;
        }

        return total - good_pair;
    }
};
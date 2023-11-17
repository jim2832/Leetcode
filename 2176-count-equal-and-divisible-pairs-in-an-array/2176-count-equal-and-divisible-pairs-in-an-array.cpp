/*

1. nums[i] == nums[j]
2. (i * j) % k == 0

*/

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int ,int> hash;
        int count = 0;
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j] && (i*j) % k == 0){
                    count++;
                }
            }
        }

        return count;
    }
};
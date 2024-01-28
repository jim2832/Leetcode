/*

[1,2,3], k = 3

round 1
sum = 1
count += seen[-2] -> 0
seen[1]++
hash table
  0    1
  1    1

round 2
sum = 3
count += seen[0] -> 1
seen[3]++
hash table
  0    1
  1    1
  3    1

round 3
sum = 6
count += seen[3]
seen[6]++
hash table
  0    1
  1    1
  3    1
  6    1

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash = {{0,1}};
        int sum = 0;
        int count = 0;

        for(auto &num:nums){
            sum += num;
            count += hash[sum - k];
            hash[sum]++;
        }

        return count;
    }
};
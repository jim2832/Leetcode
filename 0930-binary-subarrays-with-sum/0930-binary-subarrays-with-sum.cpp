class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int count = 0;
        int current_sum = 0;
        int diff;

        for(int i=0; i<n; i++){
            current_sum += nums[i];
            if(current_sum == goal){
                count++;
            }
            diff = current_sum - goal;
            if(hash.find(diff) != hash.end()){
                count += hash[diff];
            }
            hash[current_sum]++;
        }

        return count;
    }
};
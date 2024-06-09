class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> hash;
        hash[0]++;
        int sum = 0, count = 0;

        for(int i=0; i<n; i++){
            sum = (sum + nums[i]) % k;
            if(sum < 0) sum += k;
            count += hash[sum];
            hash[sum]++;
        }

        return count;
    }
};
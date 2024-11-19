class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int n = nums.size();
        if(k > n) return 0;

        long long sum = 0, maxi = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
            hash[nums[i]]++;
        }

        if(hash.size() == k){
            maxi = sum;
        }

        for(int i=0; i<n-k; i++){
            // remove the front element
            sum -= nums[i];
            hash[nums[i]]--;
            if(hash[nums[i]] == 0) hash.erase(nums[i]);

            // add the back element
            sum += nums[i+k];
            hash[nums[i+k]]++;

            // no element is duplicate
            if(hash.size() == k){
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
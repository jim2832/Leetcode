class Solution{
public:
    long long maximumSubarraySum(vector<int>& nums, int k){
        int n = nums.size();
        if(k > n) return 0;

        long long sum = 0, maxi = 0;
        unordered_map<int, int> hash;

        for(int i=0; i<k; i++){
            hash[nums[i]]++;
            sum += nums[i];
        }
        if(hash.size() == k){
            maxi = sum;
        }

        for(int i=0; i<n-k; i++){
            sum -= nums[i];
            if(--hash[nums[i]] == 0) hash.erase(nums[i]);

            sum += nums[i + k];
            hash[nums[i + k]]++;

            if(hash.size() == k){
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};

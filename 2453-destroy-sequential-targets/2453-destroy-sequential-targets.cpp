class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int ans = INT_MAX, maxi = -INT_MAX;

        unordered_map<int, int> hash;
        for(auto &num : nums){
            hash[num % space]++; // track the freqency
            maxi = max(maxi, hash[num % space]); // track the maximal freqency
        }

        for(auto &num : nums){
            if(hash[num % space] == maxi){
                ans = min(ans, num);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto &num : nums){
            hash[num]++;
        }

        int maxi = -INT_MAX;
        for(auto [num, freq] : hash){
            if(maxi < freq){
                maxi = freq;
            }
        }
        
        int count = 0;
        for(auto [num, freq] : hash){
            if(freq == maxi){
                count++;
            }
        }

        return maxi * count;
    }
};
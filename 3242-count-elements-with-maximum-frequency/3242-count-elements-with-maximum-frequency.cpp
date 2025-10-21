class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int max_freq = 0, count = 0;

        for(int &num : nums){
            max_freq = max(max_freq, ++hashMap[num]);
        }

        for(auto &[n, f] : hashMap){
            if(f == max_freq) count += f;
        }

        return count;
    }
};
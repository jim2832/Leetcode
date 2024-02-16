class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // record the freqency
        unordered_map<int, int> hash;
        for(auto &num:arr){
            hash[num]++;
        }
        
        // only freqency in the vector
        vector<int> freq;
        for(auto [a, b] : hash){
            freq.push_back(b);
        }
        sort(freq.begin(), freq.end());

        // calculate the remaining element
        int ans = freq.size();
        for(auto &fre:freq){
            if(fre > k) break;
            k -= fre;
            ans--;
        }

        return ans;
    }
};
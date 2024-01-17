// 全部的頻率都不同: true

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // record the frequency of every element
        unordered_map<int, int> hash;
        for(auto &ele:arr){
            hash[ele]++;
        }

        // check if there is duplicate
        unordered_set<int> s;
        for(auto [num, freq] :hash){
            if(s.count(freq)){
                return false;
            }
            s.insert(freq);
        }

        return true;
    }
};
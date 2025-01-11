class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> hash;
        int n = s.size(), count = 0;
        if(n < k) return false;

        for(auto &c : s) hash[c]++;

        for(auto &[c, f] : hash){
            if(f % 2) count++;
        }

        return count <= k;
    }
};
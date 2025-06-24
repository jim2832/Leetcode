class Solution{
public:
    bool isEqual(const unordered_map<char, int>& a, const unordered_map<char, int>& b){
        if(a.size() != b.size()) return false;
        for(const auto &[key, val] : a){
            auto it = b.find(key);
            if(it == b.end() || it->second != val){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2){
        int n = s2.size(), m = s1.size();
        if(n < m) return false;

        unordered_map<char, int> hashMap1, hashMap2;
        for(auto &c : s1) hashMap1[c]++;

        for(int start = 0, end = 0; end < n; end++){
            hashMap2[s2[end]]++;

            if(end - start + 1 > m){
                hashMap2[s2[start]]--;
                if(hashMap2[s2[start]] == 0){
                    hashMap2.erase(s2[start]);
                }
                start++;
            }

            if(end - start + 1 == m){
                if(isEqual(hashMap1, hashMap2)) return true;
            }
        }

        return false;
    }
};

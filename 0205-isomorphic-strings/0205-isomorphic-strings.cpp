class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> s_map, t_map;

        for(int i=0; i<n; i++){
            if(s_map[s[i]] && s_map[s[i]] != t[i]){
                return false;
            }
            if(t_map[t[i]] && t_map[t[i]] != s[i]){
                return false;
            }

            s_map[s[i]] = t[i];
            t_map[t[i]] = s[i];
        }

        return true;
    }
};
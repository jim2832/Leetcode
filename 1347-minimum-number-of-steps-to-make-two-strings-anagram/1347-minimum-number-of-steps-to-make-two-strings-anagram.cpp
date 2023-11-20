class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        int result = 0;

        for(int i=0; i<s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        for(auto iter=smap.begin(); iter!=smap.end(); iter++){
            // no such character
            if(tmap.find(iter->first) == tmap.end()){
                result += iter->second;
            }
            // the character exists, but not enough
            else if(tmap[iter->first] < iter->second){
                result += iter->second - tmap[iter->first];
            }
        }

        return result;
    }
};
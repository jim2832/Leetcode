class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> smap, tmap;
        int result = 0;

        // count the frequency
        for(int i=0; i<s.size(); i++){
            smap[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            tmap[t[i]]++;
        }

        for(auto iter=smap.begin(); iter!=smap.end(); iter++){
            // not such character in t
            if(tmap.find(iter->first) == tmap.end()){
                result += iter->second;
            }
            // the character exists, but not enough
            else if(tmap[iter->first] < iter->second){
                result += iter->second - tmap[iter->first];
            }
        }

        for(auto iter=tmap.begin(); iter!=tmap.end(); iter++){
            if(smap[iter->first] < iter->second){
                result += iter->second - smap[iter->first];
            }
        }

        return result;
    }
};
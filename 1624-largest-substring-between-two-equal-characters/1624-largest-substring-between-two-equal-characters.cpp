class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int, vector<int>> hash; // record the index of the character
        bool dup = false;

        for(int i=0; i<s.size(); i++){
            hash[s[i]].push_back(i);
        }

        int maxi = -INT_MAX;
        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            auto vec = iter->second;
            if(vec.size() > 1){
                dup = true;
            }
            int current = vec[vec.size()-1] - vec[0] - 1;
            maxi = max(maxi, current);
        }

        return dup ? maxi : -1;
    }
};
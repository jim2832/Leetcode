class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, pair<int, int>> hash;

        for(int i=0; i<paths.size(); i++){
            hash[paths[i][0]].first++;
            hash[paths[i][0]].second = 0;
            hash[paths[i][1]].first++;
            hash[paths[i][1]].second = 1;
        }

        // for(auto iter=hash.begin(); iter!=hash.end(); iter++){
        //     cout << iter->first << " " << iter->second.first << ", " << iter->second.second << endl;
        // }

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            if(iter->second.first == 1 && iter->second.second == 1){
                return iter->first;
            }
        }

        return "";
    }
};
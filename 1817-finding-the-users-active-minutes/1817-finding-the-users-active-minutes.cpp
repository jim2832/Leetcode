class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> result(k, 0);
        unordered_map<int, unordered_set<int>> hash; // user -> unique minutes {1,2,3,...}

        for(int i=0; i<logs.size(); i++){
            hash[logs[i][0]].insert(logs[i][1]);
        }

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            int temp = iter->second.size();
            result[temp-1]++;
        }

        return result;
    }
};
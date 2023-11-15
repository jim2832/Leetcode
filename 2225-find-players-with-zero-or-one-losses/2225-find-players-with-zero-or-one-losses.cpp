class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> hash;
        vector<vector<int>> result(2, vector<int>());

        for(int i=0; i<matches.size(); i++){
            if(!hash.count(matches[i][0])){
                hash[matches[i][0]] = 0;
            }
            hash[matches[i][1]]++;
        }

        // for(auto iter=hash.begin(); iter!=hash.end(); iter++){
        //     if(iter->second == 0){
        //         result[0].push_back(iter->first);
        //     }
        //     else if(iter->second == 1){
        //         result[1].push_back(iter->first);
        //     }
        // }

        for(auto [person, loss] : hash){
            if(loss == 0){
                result[0].push_back(person);
            }
            if(loss == 1){
                result[1].push_back(person);
            }
        }

        return result;
    }
};
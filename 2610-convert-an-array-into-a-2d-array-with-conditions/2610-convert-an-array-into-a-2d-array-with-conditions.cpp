class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int &num:nums){
            hash[num]++;
        }

        vector<vector<int>> result;
        while(hash.size()){
            vector<int> temp;
            for(auto &pair:hash){
                temp.push_back(pair.first);
            }
            for(int &i:temp){
                if(--hash[i] == 0){
                    hash.erase(i);
                }
            }
            result.push_back(temp);
        }

        return result;
    }
};
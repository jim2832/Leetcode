class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> result;

        for(auto &str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(str);
        }

        for(auto &[t, s] : hashMap){
            result.push_back(s);
        }

        return result;
    }
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, int> hash;
        vector<string> result;

        for(int i=0; i<heights.size(); i++) hash[heights[i]] = i;
        sort(heights.begin(), heights.end(), greater<int>());
        for(auto &height : heights) result.push_back(names[hash[height]]);

        return result;
    }
};
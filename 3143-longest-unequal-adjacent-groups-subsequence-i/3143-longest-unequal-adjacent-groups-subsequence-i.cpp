class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> result = {words[0]};

        for(int i = 1; i < n; i++){
            if(groups[i] != groups[i-1]){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
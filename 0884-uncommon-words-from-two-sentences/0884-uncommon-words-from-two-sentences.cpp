class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string str = s1 + " " + s2, temp;
        int n = str.size();
        unordered_map<string, int> hash;
        vector<string> result;
        
        for(int i=0; i<=n; i++){
            if(str[i] == ' ' || i == n){
                hash[temp]++;
                temp = "";
            }
            else{
                temp += str[i];
            }
        }

        for(auto [s, f] : hash){
            if(f == 1) result.emplace_back(s);
        }

        return result;
    }
};
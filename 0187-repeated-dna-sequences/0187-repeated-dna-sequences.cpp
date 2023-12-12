class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_set<string> us;
        set<string> res; // for removing duplicate element
        vector<string> result;

        for(int i=0; i<=n-10; i++){
            string temp = s.substr(i, 10);
            if(us.find(temp) != us.end()){ // if found
                res.insert(temp);
            }
            us.insert(temp);
        }

        for(auto &str:res){
            result.push_back(str);
        }

        return result;
    }
};
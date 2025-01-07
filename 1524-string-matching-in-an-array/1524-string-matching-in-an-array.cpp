class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        unordered_set<string> seen;

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if (words[j].find(words[i]) != string::npos) {
                    seen.insert(words[i]);
                    break;
                }
            }
        }

        result.assign(seen.begin(), seen.end());
        return result;
    }
};

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;

        int n = word.size();
        string result = "";

        for(int i = 0; i < n; i++){
            string s = word.substr(i, n - numFriends + 1);
            result = max(result, s);
        }

        return result;
    }
};
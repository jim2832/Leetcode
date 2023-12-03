class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int j = 0; // pointer of s
        for(int i=0; i<t.size(); i++){
            if(t[i] == s[j]){
                j++;
            }
        }

        return j == n;
    }
};
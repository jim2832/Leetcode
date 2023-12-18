class Solution {
public:
    bool checkValid(string &s1, string &s2){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for(int i=0; i<s1.size(); i++){
            if(s1[i] < s2[i]){
                return false;
            }
        }

        return true;
    }

    bool checkIfCanBreak(string s1, string s2) {
        return checkValid(s1,s2) || checkValid(s2,s1);
    }
};
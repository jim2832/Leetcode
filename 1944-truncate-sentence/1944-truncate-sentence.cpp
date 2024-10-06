class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size(), i = 0;
        string temp, result;

        while(k--){
            while(s[i] != ' ' && i < n){
                temp += s[i];
                i++;
            }
            i++;
            if(k) result += temp + " ";
            else result += temp;
            temp = "";
        }

        return result;
    }
};
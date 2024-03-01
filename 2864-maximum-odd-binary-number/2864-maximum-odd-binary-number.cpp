/*

01100011 -> 11100001

*/


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '1') count++;
        }

        string result;
        for(int i=0; i<count-1; i++) result += "1";
        for(int i=0; i<n-count; i++) result += "0";

        return result + "1";
    }
};
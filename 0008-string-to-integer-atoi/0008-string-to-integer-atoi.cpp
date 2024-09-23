class Solution {
public:
    int myAtoi(string s) {
        // length of s
        int n = s.size();
        if(n == 0) return 0;

        // skipping space
        int i = 0;
        while(i < n && s[i] == ' ') i++;

        // all space exception
        if(i == n) return 0;

        // judge sign
        bool isNeg = (s[i] == '-');
        if(isNeg || s[i] == '+') i++;

        int maxi = INT_MAX / 10;
        int result = 0;
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';

            if(result > maxi || (result == maxi && digit > 7)){
                return isNeg ? INT_MIN : INT_MAX;
            }

            result = result * 10 + digit;

            i++;
        }

        return isNeg ? -result : result;
    }
};
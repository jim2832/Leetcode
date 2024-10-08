class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0, count = 0;

        for(auto &c : s){
            if(c == '[') open++;
            else if(c == ']') close++;
            if(close > open){
                count++;
                open++;
                close--;
            }
        }

        return count;
    }
};
class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0;
        int count = 0;

        for(auto &c : s){
            if(c == '[') open++;
            else if(c == ']') close++;
            // cout << "open: " << open << " close: " << close << endl;
            if(close > open){
                count++;
                open++;
                close--;
                // cout << "After swap -> open: " << open << " close: " << close << endl;
            }
        }

        return count;
    }
};
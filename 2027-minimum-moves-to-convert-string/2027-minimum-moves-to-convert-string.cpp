class Solution {
public:
    int minimumMoves(string s) {
        int i = 0;
        int count = 0;
        while(i < s.size()){
            if(s[i] == 'X'){
                count++;
                i += 3;
            }
            else{
                i++;
            }
        }

        return count;
    }
};
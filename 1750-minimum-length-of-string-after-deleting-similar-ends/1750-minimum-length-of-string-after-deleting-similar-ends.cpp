class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i < j){
            // 所有都消得掉的情況
            if(j - i == 1 && s[i] == s[j]) return 0;
            // 無法消
            if(s[i] != s[j]) break;

            // 左指標能往右
            if(s[i] == s[j] && s[i] == s[i+1]){
                i++;
            }
            // 右指標能往左
            else if(s[i] == s[j] && s[j] == s[j-1]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }

        return j - i + 1;
    }
};
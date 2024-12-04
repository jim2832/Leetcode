class Solution{
public:
    bool canMakeSubsequence(string str1, string str2){
        int i = 0, j = 0;
        int n = str1.size(), m = str2.size();
        
        while(i < n && j < m){
            if((str2[j] - str1[i] + 26) % 26 <= 1){
                j++;
            }
            i++;
        }
        
        return j == m;
    }
};
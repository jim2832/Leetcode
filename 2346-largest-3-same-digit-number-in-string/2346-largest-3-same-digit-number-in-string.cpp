class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string result;

        for(int i = 0; i < n - 2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                string cur = string(3, num[i]);
                result = max(result, cur);
            }
        }
        
        return result;
    }
};

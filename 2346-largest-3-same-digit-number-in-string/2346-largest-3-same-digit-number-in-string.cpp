class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string temp, result;

        for(int i = 0; i < n - 2; i++){
            temp = num.substr(i, 3);
            if(temp[0] == temp[1] && temp[1] == temp[2]){
                result = max(result, temp);
            }
        }
        
        return result;
    }
};
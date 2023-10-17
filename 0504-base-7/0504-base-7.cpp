class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        
        bool flag = num >= 0;
        num = abs(num);
        string result = "";

        while(num > 0){
            result = to_string(num % 7) + result;
            num /= 7;
        }

        return flag ? result : "-" + result;
    }
};
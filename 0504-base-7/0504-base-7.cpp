class Solution {
public:
    string convertToBase7(int num) {
        bool flag = num >= 0;
        num = abs(num);
        string result = "";
        if(num == 0){
            return "0";
        }

        while(num > 0){
            result = to_string(num % 7) + result;
            num /= 7;
        }

        return flag ? result : "-" + result;
    }
};
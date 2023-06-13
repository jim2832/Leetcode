class Solution {
public:
    string countAndSay(int n) {
        //initial state
        if(n == 1){
            return "1";
        }
        if(n == 2){
            return "11";
        }

        string str = "11"; //初始化
        for(int i=3; i<=n; i++){
            string temp = ""; //the string used for storing
            str += "@"; //為了要比較
            int count = 1; //計數

            //走訪先前字串的每個字元
            for(int j=0; j<str.length()-1; j++){
                // 要處理不同數字的計數
                if(str[j] != str[j+1]){
                    temp  = temp + to_string(count); //第一個數字(代表了計數)
                    temp += str[j]; //第二個數字(代表了數字本身)
                    count = 1; //reset
                }
                else{
                    count++;
                }
            }
            str = temp;
        }
        return str;
    }
};
class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;
        int i = 0;
        int n = expression.size();

        while(i < n){
            // 判斷正負號
            int sign = 1;
            if(expression[i] == '+' || expression[i] == '-'){
                if(expression[i] == '-') sign = -1;
                i++;
            }

            // 取得分子
            int num = 0;
            while(i<n && isdigit(expression[i])){
                num = num * 10 + (expression[i]-'0');
                i++;
            }

            num *= sign;
            i++; //跳過斜線
            
            // 取得分母
            int den = 0;
            while(i<n && isdigit(expression[i])){
                den = den * 10 + (expression[i]-'0');
                i++;
            }
            
            // 計算新分數
            int LCM = lcm(denominator, den);
            numerator *= LCM / denominator;
            denominator *= LCM / denominator;
            num *= LCM / den;
            den *= LCM / den;
            numerator = numerator + num;

            // 約分
            int GCD = gcd(abs(numerator), denominator);
            numerator /= GCD;
            denominator /= GCD;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};
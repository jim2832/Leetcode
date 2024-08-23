class Solution {
public:
    string solveEquation(string equation) {
        int i = 0;
        int n = equation.size();
        int left_x = 0, right_x = 0;
        int left_num = 0, right_num = 0;

        // 檢查左半邊
        while(equation[i] != '='){
            // 判斷正負號
            int sign = 1;
            if(equation[i] == '+' || equation[i] == '-'){
                if(equation[i] == '-') sign = -1;
                i++;
            }

            int temp_num = 0;
            if(i < n && isdigit(equation[i])){
                int index = i;
                while(isdigit(equation[i])) i++;
                temp_num = stoi(equation.substr(index, i-index)) * sign;
                if(i < n && equation[i] == 'x'){
                    left_x += temp_num;
                    i++;
                }
                else{
                    left_num += temp_num;
                }
            }
            // 不帶係數的 x
            else if(equation[i] == 'x'){
                left_x += sign;
                i++;
            }
        }

        // 跳過等於
        i++;

        // 檢查右半邊
        while(i < n){
            // 判斷正負號
            int sign = 1;
            if(equation[i] == '+' || equation[i] == '-'){
                if(equation[i] == '-') sign = -1;
                i++;
            }

            // 帶有係數的 x
            int temp_num = 0;
            if(i < n && isdigit(equation[i])){
                int index = i;
                while(isdigit(equation[i])) i++;
                temp_num = stoi(equation.substr(index, i-index)) * sign;
                if(i < n && equation[i] == 'x'){
                    right_x += temp_num;
                    i++;
                }
                else{
                    right_num += temp_num;
                }
            }
            // 不帶係數的 x
            else if(equation[i] == 'x'){
                right_x += sign;
                i++;
            }
        }

        if(left_x == right_x && left_num == right_num) return "Infinite solutions";
        else if(left_x == right_x) return "No solution";

        return "x=" + to_string((right_num - left_num) / (left_x - right_x));
    }
};
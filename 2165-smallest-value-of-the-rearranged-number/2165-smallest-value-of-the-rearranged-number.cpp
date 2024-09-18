/*
class Solution{
public:
    long long smallestNumber(long long num){
        if(-9 <= num && num <= 9) return num;

        int sign = num >= 0 ? 1 : -1;
        if(sign == -1) num *= sign;
        
        vector<int> digits;
        string str = to_string(num), result;
        for(auto &c : str){
            digits.emplace_back(c - '0');
        }

        int i = 0;
        if(sign == 1){
            sort(digits.begin(), digits.end());
            while(digits[i] == 0) i++;
            swap(digits[0], digits[i]);
        }
        else{
            sort(digits.begin(), digits.end(), greater<int>());
        }

        for(auto &digit : digits){
            result += to_string(digit);
        }

        num = stoll(result);

        return sign > 0 ? num : -num;
    }
};
*/

class Solution {
public:
    long long smallestNumber(long long num){
        if(-9 <= num && num <= 9) return num;

        int sign = num >= 0 ? 1 : -1;
        num = abs(num);

        string digits = to_string(num);
        if(sign == 1){
            sort(digits.begin(), digits.end());
            if(digits[0] == '0'){
                auto it = find_if(digits.begin(), digits.end(), [](char c) {return c != '0';});
                swap(digits[0], *it);
            }
        }
        else{
            sort(digits.begin(), digits.end(), greater<char>());
        }

        return sign * stoll(digits);
    }
};

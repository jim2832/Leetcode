class Solution {
public:
    bool NoZeroInt(int num){
        while(num){
            if(num % 10 == 0){
                return false;
            }
            num /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int num = 1; num < n; num++){
            if(NoZeroInt(num) && NoZeroInt(n - num)){
                return {num, n - num};
            }
        }

        return {};
    }
};
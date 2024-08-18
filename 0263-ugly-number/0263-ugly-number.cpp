class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;

        for(int num=2; num<=5; num++){
            while(n % num == 0){
                n /= num;
            }
        }

        return n == 1;
    }
};
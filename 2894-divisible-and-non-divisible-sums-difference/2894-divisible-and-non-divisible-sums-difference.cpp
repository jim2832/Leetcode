class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        
        for(int num=1; num<=n; num++){
            if(num % m)
                num1 += num;
            else
                num2 += num;
        }

        return num1 - num2;
    }
};
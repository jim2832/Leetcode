class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }


    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int num = left; num <= right; num++){
            count += isPrime(__builtin_popcount(num));
        }

        return count;
    }
};
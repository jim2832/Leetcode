// bit manipulation solution
// 若一個數是2的次方次數，他的二進位只會有一個1
// 8 -> 00001000
// 7 -> 00000111
// 若 n 和 n-1 做 bitwise and 為 0，則代表他是2的次方數
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & n-1) == 0;
    }
};

/*
// division solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // exception
        if(n == 0) return false;

        while(n % 2 == 0){
            n /= 2;
        }

        return n == 1;
    }
};
*/
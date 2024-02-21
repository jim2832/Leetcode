/*

left = 5, right = 7
5 -> 101
6 -> 110
7 -> 111

101 & 110 -> 100
100 & 111 -> 100

*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift_count = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            shift_count++;
        }
        return left << shift_count;
    }
};
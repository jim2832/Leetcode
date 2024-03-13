/*

1 -> 1
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36

1 + 2 = 3
2 + 3 + 4 + 5 + 6 + 7 + 8 = 35

1 + 2 + 3 = 6
3 + 4 + 5 + 6 + 7 + 8 = 33

*/

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n+1) / 2;
        int prefix_sum = 0;
        int temp = 0;
        
        for(int i=1; i<=n; i++){
            prefix_sum += i;
            sum -= temp;
            temp = i;
            if(prefix_sum == sum){
                return i;
            }
        }

        return -1;
    }
};
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
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += i;
        }

        int temp_sum = 0;
        int temp = 0;
        for(int i=1; i<=n; i++){
            temp_sum += i;
            sum -= temp;
            temp = i;
            if(temp_sum == sum){
                return i;
            }
        }

        return -1;
    }
};
/*

10 <= low <= high <= 10^9 -> 2到9位數

1開頭：1 12 123 1234 12345 ...
2開頭：2 23 234 2345 23456 ...
...

*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        for(int first_num=1; first_num<=9; first_num++){
            int current = first_num;

            // append next number to current
            for(int next=first_num+1; next<=9; next++){
                current = current * 10 + next;

                // judge if current is valid
                if(low <= current && current <= high){
                    result.push_back(current);
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
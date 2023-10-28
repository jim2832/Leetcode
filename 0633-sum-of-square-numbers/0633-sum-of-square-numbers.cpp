typedef long long ll;

class Solution {
public:
    bool judgeSquareSum(int c) {
        ll i = 0;
        ll j = sqrt(c);

        while(i <= j){
            ll sum = pow(i,2) + pow(j,2);

            if(sum == c)
                return true;
            else if(sum < c)
                i++;
            else
                j--;
        }

        return false;
    }
};
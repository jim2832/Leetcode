class Solution {
public:
    vector<int> sumZero(int n) {
        int max = n / 2;
        vector<int> result;

        for(int num = -max; num < 0; num++){
            result.push_back(num);
        }

        if(n % 2) result.push_back(0);

        for(int num = 1; num <= max; num++){
            result.push_back(num);
        }

        return result;
    }
};
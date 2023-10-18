class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n);
        result.push_back(0);

        if(n == 0){
            return result;
        }
        
        for(int num=1; num<=n; num++){
            result[num] = num % 2 ? result[num-1] + 1 : result[num/2];
        }

        return result;
    }
};
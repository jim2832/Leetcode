class Solution {
public:
    int numTrees(int n) {
        return calculate(2*n, n) / (n+1);
    }

    long calculate(int n, int k){
        long result = 1;
        if(k > n-k){
            k = n-k;
        }
        for(int i=0; i<k; i++){
            result *= (n-i);
            result /= (i+1);
        }

        return result;
    }
};
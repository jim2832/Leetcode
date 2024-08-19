class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num == 2 || num == 3) {
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0) {
            return false;
        }
        for (int i = 5; i <= sqrt(num); i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> factorize(int num) {
        vector<int> factors;

        while (num % 2 == 0) {
            factors.push_back(2);
            num /= 2;
        }

        for (int i = 3; i * i <= num; i += 2) {
            while (num % i == 0) {
                factors.push_back(i);
                num /= i;
            }
        }

        if (num > 2) factors.push_back(num);

        return factors;
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        vector<int> DP(n+1, 0);
        vector<int> factors;
        
        for(int i=2; i<=n; i++){
            if(isPrime(i)){
                DP[i] = i;
            }
            else{
                factors = factorize(i);
                for(auto &factor : factors){
                    DP[i] += DP[factor];
                }
            }
        }

        return DP[n];
    }
};
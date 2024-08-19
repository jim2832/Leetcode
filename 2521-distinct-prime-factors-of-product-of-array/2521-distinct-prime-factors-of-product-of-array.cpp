class Solution {
public:
    vector<int> primeFactors(int num) {
        vector<int> prime_factors;

        while (num % 2 == 0) {
            prime_factors.push_back(2);
            num /= 2;
        }

        for (int i = 3; i * i <= num; i += 2) {
            while (num % i == 0) {
                prime_factors.push_back(i);
                num /= i;
            }
        }

        if (num > 2) prime_factors.push_back(num);

        return prime_factors;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> prime_factors;
        unordered_set<int> s;

        for(auto &num : nums){
            prime_factors = primeFactors(num);
            for(auto &prime_factor : prime_factors){
                if(!s.count(prime_factor)){
                    s.insert(prime_factor);
                }
            }
        }

        return s.size();
    }
};
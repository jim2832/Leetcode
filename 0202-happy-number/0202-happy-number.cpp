class Solution {
public:
    int next_number(int n){
        int sum = 0;
        while(n){
            sum += pow(n % 10, 2);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;

        while(n != 1 && !set.count(n)){
            set.insert(n);
            n = next_number(n);
        }
        
        return n == 1;
    }
};
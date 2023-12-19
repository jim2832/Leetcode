class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int result = 0;

        // generate all fib numbers
        vector<int> fib = {1,1};
        int pre = 1, cur = 1;
        while(fib.back() <= (int)(1e9)) {
            int new_num = pre + cur;
            pre = fib.back();
            cur = new_num;
            fib.push_back(new_num);
        }

        // greedy sub
        int i = fib.size()-1;
        int current = 0;
        while(i>=0){
            if(current + fib[i] <= k){
                current += fib[i];
                result++;
            }
            if(current == k){
                break;
            }
            i--;
        }

        return result;
    }
};
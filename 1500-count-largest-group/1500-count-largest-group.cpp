class Solution {
public:
    int digit_sum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> hash;
        int maxi = INT_MIN, count = 0;

        for(int num = 1; num <= n; num++){
            maxi = max(maxi, ++hash[digit_sum(num)]);
        }

        for(auto &[digit, freq] : hash){
            if(freq == maxi) count++;
        }

        return count;
    }
};
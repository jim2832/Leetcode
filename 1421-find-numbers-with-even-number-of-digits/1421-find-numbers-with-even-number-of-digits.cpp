class Solution {
public:
    int count_digits(int num){
        int count = 0;
        while(num){
            count++;
            num /= 10;
        }

        return count;
    }

    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto &num : nums){
            if(count_digits(num) % 2 == 0){
                ans++;
            }
        }

        return ans;
    }
};
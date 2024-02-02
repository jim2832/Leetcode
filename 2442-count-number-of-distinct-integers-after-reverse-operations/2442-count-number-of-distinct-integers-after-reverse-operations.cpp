/*

reverse: 13 -> 31

*/

class Solution {
public:
    int reverse(int num){
        int result = 0;
        while(num){
            result = result * 10 + num % 10;
            num /= 10;
        }
        return result;
    }

    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(auto &num:nums){
            s.insert(reverse(num));
        }

        return s.size();
    }
};
class Solution {
public:
    int minimumLength(string s) {
        vector<int> hash(26, 0);
        int sum = 0;

        for(auto &c : s){
            sum++;
            if(++hash[c - 'a'] >= 3){
                hash[c - 'a'] -= 2;
                sum -= 2;
            }
        }

        return sum;
    }
};
class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0, one = 0;

        for(auto &c : s){
            c == '1' ? one++ : count += one;
        }

        return count;
    }
};
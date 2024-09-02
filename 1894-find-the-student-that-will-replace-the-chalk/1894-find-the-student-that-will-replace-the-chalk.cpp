class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for(auto &c : chalk) total += c;
        k %= total;

        int n = chalk.size();
        for(int i=0; i<n; i++){
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }

        return 0;
    }
};
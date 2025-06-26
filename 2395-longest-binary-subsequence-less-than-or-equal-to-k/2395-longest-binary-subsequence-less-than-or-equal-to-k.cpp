class Solution{
public:
    int longestSubsequence(string s, int k){
        int count = 0, n = s.size();
        long long cur_val = 0, weight = 1;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0'){
                count++;
            }
            else{
                if(weight <= k && cur_val + weight <= k){
                    cur_val += weight;
                    count++;
                }
            }

            if(weight <= LLONG_MAX >> 1){
                weight <<= 1;
            }
            else{
                weight = LLONG_MAX;
            }
        }

        return count;
    }
};

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, count = 0;

        for(auto &c : s){
            if(c == 'b') count++;
            else if(count){
                count--;
                ans++;
            }
        }

        return ans;
    }
};
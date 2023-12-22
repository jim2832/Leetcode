/*
分數: 左邊0的個數 + 右邊1的個數
*/

class Solution {
public:
    int maxScore(string s) {
        unordered_map<int, int> hash;

        for(auto &c:s){
            hash[c]++;
        }

        int zeros_now = 0;
        int ones_now = 0;
        int maxi = -INT_MAX;

        for(int i=0; i<s.size()-1; i++){
            // 紀錄目前遇到了幾個0和幾個1
            s[i] == '0' ? zeros_now++ : ones_now++;

            // 分數: 左邊0的個數 + 右邊1的個數(總共有幾個1 - 左邊1的個數)
            int score = zeros_now + (hash['1'] - ones_now);
            maxi = max(maxi, score);
        }

        return maxi;
    }
};
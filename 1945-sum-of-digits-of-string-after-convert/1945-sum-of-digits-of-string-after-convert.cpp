class Solution {
public:
    int getLucky(string s, int k) {
        string result;
        for(char &c : s){
            result += to_string(c - 'a' + 1);
        }

        while(k--){
            int sum = 0;
            for(auto &c : result){
                sum += (c - '0');
            }
            result = to_string(sum);
        }

        return stoi(result);
    }
};
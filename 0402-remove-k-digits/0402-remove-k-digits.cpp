class Solution {
public:
    string removeLeadingZeros(const string &s) {
        auto pos = s.find_first_not_of('0');
        if(pos == string::npos){
            return "0";
        }
        return s.substr(pos);
    }

    string removeKdigits(string num, int k) {
        int n = num.size();
        string result;

        if(k >= n) return "0";

        for(int i=0; i<n; i++){
            while(!result.empty() && num[i] < result.back() && k){
                result.pop_back();
                k--;
            }
            result += num[i];
        }

        for(int i=0; i<k; i++){
            result.pop_back();
        }

        return removeLeadingZeros(result);
    }
};
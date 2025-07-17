class Solution {
public:
    void solve(const string &digits, int index, string &current, vector<string> &result, const unordered_map<char, vector<char>> &hashMap){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }

        for(char c : hashMap.at(digits[index])){
            current.push_back(c);
            solve(digits, index + 1, current, result, hashMap);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, vector<char>> hashMap{
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };

        vector<string> result;
        string current;
        solve(digits, 0, current, result, hashMap);
        return result;
    }
};

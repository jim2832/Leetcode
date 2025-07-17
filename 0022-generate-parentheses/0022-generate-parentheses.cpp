class Solution {
public:
    void solve(int n, int left, int right, string current, vector<string> &result){
        if(current.size() == n * 2){
            result.push_back(current);
            return;
        }

        if(left < n){
            solve(n, left + 1, right, current + "(", result);
        }

        if(right < left){
            solve(n, left, right + 1, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, 0, 0, "", result);
        return result;
    }
};

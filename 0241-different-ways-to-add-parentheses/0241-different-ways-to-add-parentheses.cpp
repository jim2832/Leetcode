class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> result;

        for(int i=0; i<n; i++){
            char c = expression[i];
            if(c == '+' || c == '-' || c == '*'){
                vector<int> result1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> result2 = diffWaysToCompute(expression.substr(i+1));
                for(auto r1 : result1){
                    for(auto r2 : result2){
                        if(c == '+') result.emplace_back(r1 + r2);
                        else if(c == '-') result.emplace_back(r1 - r2);
                        else result.emplace_back(r1 * r2);
                    }
                }
            }
        }

        if(result.empty()) result.emplace_back(stoi(expression));

        return result;
    }
};
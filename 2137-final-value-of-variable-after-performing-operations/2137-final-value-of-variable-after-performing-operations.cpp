class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for(auto &o : operations){
            X += (o[1] == '+') ? 1 : -1;
        }
        return X;
    }
};

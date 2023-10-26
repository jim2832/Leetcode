class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int sum = 0;
        for(string &s:operations){
            if(s == "X++" || s == "++X"){
                sum++;
            }
            else{
                sum--;
            }
        }

        return sum;
    }
};
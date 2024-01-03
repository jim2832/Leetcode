class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // count the number of "1"
        vector<int> one_num;
        for(string &str:bank){
            int freq = 0;
            for(auto &c:str){
                if(c == '1'){
                    freq++;
                }
            }
            if(freq){
                one_num.push_back(freq);
            }
        }

        // exception
        if(one_num.empty()){
            return 0;
        }

        // count the number of lasers
        int result = 0;
        for(int i=0; i<one_num.size()-1; i++){
            int mul = one_num[i] * one_num[i+1];
            result += mul;
        }

        return result;
    }
};
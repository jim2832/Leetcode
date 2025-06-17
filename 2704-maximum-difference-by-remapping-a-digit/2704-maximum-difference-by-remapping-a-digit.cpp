class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string maxi = str, mini = str;
        char none_nine;

        for(auto &c : str){
            if(c != '9'){
                none_nine = c;
                break;
            }
        }

        for(int i = 0; i < str.size(); i++){
            if(str[i] == none_nine) maxi[i] = '9';
            if(str[i] == str[0]) mini[i] = '0';
        }

        return stoi(maxi) - stoi(mini);
    }
};
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxi = -INT_MAX;
        string result = "";

        for(int i=0; i<n-2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                // current string and number
                string current_str = num.substr(i, 3);
                int current_num = stoi(current_str);

                // check if it is larger
                if(maxi < current_num){
                    result = current_str;
                    maxi = current_num;
                }
            }
        }

        return result;
    }
};
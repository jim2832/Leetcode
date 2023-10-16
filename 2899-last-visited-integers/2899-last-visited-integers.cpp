class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int seen = 0;
        vector<int> result;

        for(int i=0; i<words.size(); i++){
            if(words[i] == "prev"){
                seen++;
                int temp = seen;
                int back = 1;
                while(true){
                    if(i-back < 0){
                        result.push_back(-1);
                        break;
                    }
                    if(words[i-back] != "prev"){
                        temp--;
                        if(temp){
                            back++;
                        }
                        else{
                            result.push_back(stoi(words[i-back]));
                            break;
                        }
                    }
                    else{
                        back++;
                    }
                }
            }
            else{
                seen = 0;
            }
        }

        return result;
    }
};
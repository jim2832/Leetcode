class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        bool good = true;

        // 設定 broken letters
        vector<int> broken(26, 0);
        for(int i=0; i<brokenLetters.size(); i++){
            broken[brokenLetters[i]-'a'] = 1;
        }
        
        for(int i=0; i<text.size(); i++){
            if(text[i] == ' '){
                if(good){
                    count++;
                }
                good = true;
            }
            else{
                if(broken[text[i]-'a'] == 1){
                    good = false;
                }
            }
        }

        //最後一個字
        if(good == true){
            count++;
        }
        
        return count;
    }
};
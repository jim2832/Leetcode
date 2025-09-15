class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> us;
        int n = text.size();
        int count = 0;
        bool flag = true;

        for(char c : brokenLetters){
            us.insert(c);
        }

        for(int i = 0; i <= n; i++){
            if(text[i] == ' ' || i == n){
                count += flag;
                flag = true;
            }
            else if(us.count(text[i])){
                flag = false;
            }
        }

        return count;
    }
};
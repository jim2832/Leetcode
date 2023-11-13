class Solution {
public:
    bool isVowel(char &c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    string sortVowels(string s) {
        vector<char> sorted;
        for(auto &c:s){
            if(isVowel(c)){
                sorted.push_back(c);
            }
        }

        sort(sorted.begin(), sorted.end());

        int j = 0;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                s[i] = sorted[j];
                j++;
            }
        }

        return s;
    }
};
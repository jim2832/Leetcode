class Solution{
public:
    int isPrefixOfWord(string sentence, string searchWord){
        int i = 0, count = 1;

        while(i < sentence.size()){
            int j = 0;
            while(i < sentence.size() && j < searchWord.size() && sentence[i] == searchWord[j]){
                i++;
                j++;
            }

            if(j == searchWord.size()){
                return count;
            }

            while(i < sentence.size() && sentence[i] != ' '){
                i++;
            }

            i++;
            count++;
        }

        return -1;
    }
};

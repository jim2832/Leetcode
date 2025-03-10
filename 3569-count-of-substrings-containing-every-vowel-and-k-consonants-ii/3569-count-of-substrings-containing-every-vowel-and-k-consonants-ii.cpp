class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atLeastK(string word, int k) {
        unordered_map<char, int> hash;
        int n = word.size();
        int start = 0;
        int consonants = 0;
        long long count = 0;

        for(int end=0; end<n; end++){
            if(isVowel(word[end])){
                hash[word[end]]++;
            }
            else{
                consonants++;
            }
            
            while(hash.size() == 5 && consonants >= k){
                count += n - end;
                if(isVowel(word[start])){
                    hash[word[start]]--;
                    if(hash[word[start]] == 0){
                        hash.erase(word[start]);
                    }
                }
                else{
                    consonants--;
                }
                start++;
            }
        }

        return count;
    }

    long long countOfSubstrings(string word, int k){
        return atLeastK(word, k) - atLeastK(word, k+1);
    }
};
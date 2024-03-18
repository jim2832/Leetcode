class Solution {
public:
    int maximumSwap(int num) {
        unordered_map<char, int> hash;

        string str = to_string(num);

        for(int i=0; i<str.size(); i++){
            hash[str[i]] = i;
        }

        for(int i=0; i<str.size(); i++){
            for(char j='9'; j>str[i]; j--){
                if(hash.count(j) && i < hash[j]){
                    swap(str[i], str[hash[j]]);
                    return stoi(str);
                }
            }
        }

        return num;
    }
};
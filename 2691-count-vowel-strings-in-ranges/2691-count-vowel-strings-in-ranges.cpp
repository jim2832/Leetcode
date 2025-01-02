class Solution{
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries){
        int n = words.size();
        vector<int> result, prefixSum(n + 1, 0);
        
        for(int i=0; i<n; i++){
            if(isVowel(words[i].front()) && isVowel(words[i].back())){
                prefixSum[i+1] = prefixSum[i] + 1;
            }
            else{
                prefixSum[i+1] = prefixSum[i];
            }
        }
        
        for(auto& query : queries){
            result.push_back(prefixSum[query[1]+1] - prefixSum[query[0]]);
        }
        
        return result;
    }
};

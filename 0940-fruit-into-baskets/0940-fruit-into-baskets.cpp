class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> hashMap;
        int max_len = 0;

        for(int start = 0, end = 0; end < n; end++){
            hashMap[fruits[end]]++;

            while(hashMap.size() > 2){
                if(--hashMap[fruits[start]] == 0){
                    hashMap.erase(fruits[start]);
                }
                start++;
            }

            max_len = max(max_len, end - start + 1);
        }

        return max_len;
    }
};
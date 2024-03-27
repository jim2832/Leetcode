class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash; // fruit type : number
        int n = fruits.size();
        int start = 0;
        int max_size = 0;

        for(int end=0; end<n; end++){
            // pick up the fruit
            hash[fruits[end]]++;

            // decrease the window size
            while(hash.size() > 2){
                hash[fruits[start]]--;
                if(hash[fruits[start]] == 0){
                    hash.erase(fruits[start]);
                }
                start++;
            }
            max_size = max(max_size, end - start + 1);
        }

        return max_size;
    }
};
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string, int> hash;
        hash["type"] = 0;
        hash["color"] = 1;
        hash["name"] = 2;
        int count = 0;
        
        for(int i=0; i<items.size(); i++){
            if(items[i][hash[ruleKey]] == ruleValue) count++;
        }

        return count;
    }
};
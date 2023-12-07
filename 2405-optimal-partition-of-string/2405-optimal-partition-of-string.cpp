class Solution {
public:
    int partitionString(string s) {
        unordered_set<int> us;
        int count = 0;

        for(auto &c:s){
            if(us.count(c)){
                count++;
                us.clear();
            }
            us.insert(c);
        }

        return count+1;
    }
};
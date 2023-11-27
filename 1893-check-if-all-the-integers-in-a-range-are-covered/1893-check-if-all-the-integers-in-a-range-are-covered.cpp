class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_set<int> s;

        for(int i=0; i<ranges.size(); i++){
            for(int j=ranges[i][0]; j<=ranges[i][1]; j++){
                s.insert(j);
            }
        }

        for(int num=left; num<=right; num++){
            if(!s.count(num)){
                return false;
            }
        }

        return true;
    }
};
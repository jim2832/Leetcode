class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int result = -1;
        set<int> s;

        for(auto &edge : edges) s.insert(edge[1]);

        for(int i=0; i<n; i++){
            if(!s.count(i)){
                if(result != -1) return -1;
                result = i;
            }
        }

        return result;
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result;
        unordered_set<int> reachable_nodes;
        for(auto edge:edges){
            reachable_nodes.insert(edge[1]);
        }
        for(int i=0; i<n; i++){
            if(reachable_nodes.find(i) == reachable_nodes.end()){
                result.push_back(i);
            }
        }

        return result;
    }
};
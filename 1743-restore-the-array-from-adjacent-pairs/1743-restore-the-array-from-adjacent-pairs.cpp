class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        
        // record the adjacent node
        for(int i=0; i<adjacentPairs.size(); i++){
            graph[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            graph[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        int root;
        for(auto &pair:graph){
            if(pair.second.size() == 1){
                root = pair.first;
                break;
            }
        }

        int current = root;
        vector<int> result = {root};
        int prev = INT_MAX;

        while(result.size() < graph.size()){
            for(int neighbor:graph[current]){
                if(neighbor != prev){
                    result.push_back(neighbor);
                    prev = current;
                    current = neighbor;
                    break;
                }
            }
        }

        return result;
    }
};
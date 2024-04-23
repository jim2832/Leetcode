class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> degrees(n, 0);

        if(n == 1) return {0};
        if(n == 2) return {0, 1};

        for(auto &edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }

        // leaf (degree = 1)
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degrees[i] == 1){
                q.push(i);
            }
        }

        vector<int> result;
        while(!q.empty()){
            int s = q.size();
            result.clear();

            // traverse
            for(int i=0; i<s; i++){
                int current = q.front();
                q.pop();
                result.push_back(current);

                for(auto &adj : graph[current]){
                    if(--degrees[adj] == 1){
                        q.push(adj);
                    }
                }
            }
        }

        return result;
    }
};
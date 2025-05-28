class Solution {
public:
    vector<vector<int>> bulidAdj(vector<vector<int>>& edges){
        vector<vector<int>> adj(edges.size() + 1); // V = E + 1

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return adj;
    }

    int DFS(vector<vector<int>> &adj, int cur, int par, int rest_steps){
        if(rest_steps < 0) return 0;
        int count = 1; // include self

        for(auto &v : adj[cur]){
            if(v != par){
                count += DFS(adj, v, cur, rest_steps - 1);
            }
        }

        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> adj1 = bulidAdj(edges1);
        vector<vector<int>> adj2 = bulidAdj(edges2);

        int n = adj1.size(), m = adj2.size();
        int tree2_max = 0;
        vector<int> result(n);

        // calculate the max of tree2
        for(int i = 0; i < m; i++){
            tree2_max = max(tree2_max, DFS(adj2, i, -1, k - 1));
        }

        // calculate the max of tree1
        for(int i = 0; i < n; i++){
            result[i] = DFS(adj1, i, -1, k) + tree2_max;
        }

        return result;
    }
};
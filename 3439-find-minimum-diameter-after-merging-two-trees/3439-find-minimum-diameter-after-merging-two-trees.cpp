class Solution{
public:
    vector<vector<int>> buildAdj(vector<vector<int>> &edges){
        vector<vector<int>> adj(edges.size() + 1); // V = E + 1

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return adj;
    }

    int farthestNode;
    int maxDist;

    void dfs(const vector<vector<int>> &adj, int u, int p, int d){
        if(d > maxDist){
            maxDist = d;
            farthestNode = u;
        }

        for(int v : adj[u]){
            if(v != p){
                dfs(adj, v, u, d + 1);
            }
        }
    }

    int getDiameter(const vector<vector<int>> &adj){
        maxDist = INT_MIN;
        dfs(adj, 0, -1, 0);

        int start = farthestNode;
        maxDist = INT_MIN;
        dfs(adj, start, -1, 0);

        return maxDist;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2){
        vector<vector<int>> adj1 = buildAdj(edges1);
        vector<vector<int>> adj2 = buildAdj(edges2);
        
        int diam1 = getDiameter(adj1);
        int diam2 = getDiameter(adj2);
        int mergedDiameter = max({diam1, diam2, ((diam1 + 1) / 2) + ((diam2 + 1) / 2) + 1});

        return mergedDiameter;
    }
};

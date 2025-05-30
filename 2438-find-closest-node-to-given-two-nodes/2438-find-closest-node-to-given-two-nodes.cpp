class Solution {
public:
    void DFS(int cur_node, vector<int> &edges, vector<int> &dist, int dis){
        dist[cur_node] = dis;
        int neighbor= edges[cur_node];
        if(neighbor != -1 && dist[neighbor] == -1){
            DFS(neighbor, edges, dist, dis + 1);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int mini = INT_MAX;
        int result = -1;
        int n = edges.size();

        vector<int> dist1(n, -1), dist2(n, -1);
        DFS(node1, edges, dist1, 0);
        DFS(node2, edges, dist2, 0);

        for(auto node = 0; node < n; node++){
            if(dist1[node] != -1 && dist2[node] != -1){
                if(mini > max(dist1[node], dist2[node])){
                    mini = max(dist1[node], dist2[node]);
                    result = node;
                }
            }
        }

        return result;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, 0.0); // 紀錄每個點最後的機率
        prob[start_node] = 1.0;

        // 進行 n-1 次的 relax
        for(int i=0; i<n-1; i++){
            bool updated = false;
            // 走訪每個 edges (對每個 edge 都做 relax)
            for(int j=0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                double current_prob = succProb[j]; // 第 j 個邊的機率

                if(prob[v] < prob[u] * current_prob){
                    prob[v] = prob[u] * current_prob;
                    updated = true;
                }

                if(prob[u] < prob[v] * current_prob){
                    prob[u] = prob[v] * current_prob;
                    updated = true;
                }
            }
            if(!updated) break;
        }

        return prob[end_node];
    }
};
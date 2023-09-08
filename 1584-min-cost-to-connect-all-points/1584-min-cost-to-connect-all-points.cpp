//MST

struct edge{
    int from;
    int to;
    int cost;
};

class compare{
    public:
        bool operator()(edge &e1, edge &e2){
            return e1.cost > e2.cost;
        }
};

class Solution {
        vector<int> MST_set;
        vector<edge> MST_edges;

    public:
        int find_set(int current){
            int root = current;

            //先找到根節點
            while(MST_set[root] >= 0){
                root = MST_set[root];
            }

            //current不斷往上，直到找到根節點
            while(current != root){
                int predecessor = MST_set[current];
                MST_set[current] = root; //指向根節點
                current = predecessor;
            }

            return root;
        }

        void merge_set(int u, int v){
            int u_root = find_set(u);
            int v_root = find_set(v);

            if(u_root == v_root) return;

            //代表 u_root 比較大
            if(MST_set[u_root] <= MST_set[v_root]){
                MST_set[u_root] += MST_set[v_root];
                MST_set[v_root] = u_root; //讓 v 指向 u
            }
            else{ //代表 v_root 比較大
                MST_set[v_root] += MST_set[u_root];
                MST_set[u_root] = v_root; //讓 u 指向 v
            }
        }

        int minCostConnectPoints(vector<vector<int>>& points) {
            int vertex = points.size();
            int edges_completed = 0; //已經處理完的邊
            MST_set.resize(vertex);
            priority_queue<edge, vector<edge>, compare> sorted_edges;

            // push and initialization
            for(int i=0; i<vertex; i++){
                MST_set[i] = -1; //一開始每個點自己本身都是一個MST

                // edge i -> j
                for(int j=i+1; j<vertex; j++){
                    int current_cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    edge current = {i, j, current_cost};
                    sorted_edges.push(current);
                }
            }

            while(!sorted_edges.empty() && edges_completed < vertex-1){
                edge current = sorted_edges.top();
                sorted_edges.pop();
                //確認不會形成環
                if(find_set(current.from) != find_set(current.to)){
                    merge_set(current.from, current.to);
                    MST_edges.push_back(current);
                    edges_completed++;
                }
            }

            int sum = 0;
            for(int i=0; i<MST_edges.size(); i++){
                sum += MST_edges[i].cost;
            }

            return sum;
        }
};
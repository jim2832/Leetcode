class Solution {
public:
    int target;
    vector<int> temp;
    vector<vector<int>> result;

    void DFS(vector<vector<int>> &graph, int current_node){
        // add current node
        temp.push_back(current_node);

        // if we have arrived at the target
        if(current_node == target){
            result.push_back(temp);
        }
        // if we don't arrive at the target yet,
        // DFS the graph continuously
        else{
            for(auto &node:graph[current_node]){
                DFS(graph, node);
            }
        }

        // backtracking
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        DFS(graph, 0);

        return result;
    }
};
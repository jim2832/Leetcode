class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> edges(numCourses);
        vector<int> in_degree(numCourses, 0);

        for(auto &p : prerequisites){
            edges[p[1]].push_back(p[0]);
            in_degree[p[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in_degree[i] == 0){ // source
                q.push(i);
            }
        }

        while(!q.empty()){
            auto current = q.front();
            q.pop();
            numCourses--;
            for(auto &neighbor : edges[current]){
                in_degree[neighbor]--;
                if(in_degree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        return numCourses == 0;
    }
};
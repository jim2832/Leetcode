class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> in_degrees(numCourses, 0);
        vector<int> ordering;

        // build graph
        for(auto &p : prerequisites){
            edges[p[1]].push_back(p[0]);
            in_degrees[p[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in_degrees[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto current = q.front();
            q.pop();
            numCourses--;
            ordering.push_back(current);
            for(auto &neighbor : edges[current]){
                if(--in_degrees[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        return numCourses == 0 ? ordering : vector<int>{};
    }
};
// topological sort 解法

/*
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses); //紀錄順序
        vector<int> in_degree(numCourses, 0); //紀錄每個點的 in degree
        vector<int> result; //紀錄最後要回傳的結果
        queue<int> topological_sort; //紀錄已處理好的順序

        //把prerequisites每筆資料取出來
        for(auto& prerequisite:prerequisites){
            // prerequisites[1] -> prerequisites[0] (代表先完成1才能做0)
            edges[prerequisite[1]].push_back(prerequisite[0]);
            in_degree[prerequisite[0]]++; //被指到所以in degree +1
        }

        //先找出一個 in degree 為 0 的點
        for(int i=0; i<numCourses; i++){
            if(in_degree[i] == 0){
                topological_sort.push(i);
                result.push_back(i);
            }
        }

        while(!topological_sort.empty()){
            int current = topological_sort.front();
            topological_sort.pop();
            
            int edge_count = edges[current].size(); //目前這個點有幾個邊
            // 刪除所有這個點的相鄰邊
            for(int i=0; i<edge_count; i++){
                // current -> edges[current][i]
                in_degree[edges[current][i]]--; //因為刪掉了，所以被指向的點 in degree 要 -1
                if(in_degree[edges[current][i]] == 0){
                    topological_sort.push(edges[current][i]);
                    result.push_back(edges[current][i]);
                }
            }
        }

        //若最後 result vector 內的數量等於節點總數，則代表有一組 topological_sort
        return result.size() == numCourses ? result : vector<int>(0);
    }
};
*/

//DFS解法
class Solution {
    vector<int> color;
    vector<vector<int>> edges; //紀錄相鄰邊
    vector<int> topological_sort; //紀錄修課順序

    bool check_cycle(int vertex){
        color[vertex] = 1; //走訪後設定成灰色

        for(int i=0; i<edges[vertex].size(); i++){
            if(color[edges[vertex][i]] == 0){ //如果是白點，則可以繼續走訪
                bool cycled = check_cycle(edges[vertex][i]); //繼續往下走訪
                if(cycled){ //有環
                    return true;
                }
            }
            //有環(有走訪到黑點)
            else if(color[edges[vertex][i]] == 1){
                return true;
            }
        }
        
        color[vertex] = 2; //走訪後設定成黑色
        topological_sort.insert(topological_sort.begin(), vertex);
        return false;
    }

    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            color.resize(numCourses);
            edges.resize(numCourses);
            vector<int> empty;

            for(auto edge:prerequisites){
                // edge[1] -> edge[0]
                edges[edge[1]].push_back(edge[0]);
            }

            //DFS
            for(int i=0; i<numCourses; i++){
                if(color[i] == 0){ //找白點
                    //檢查是否有環，如果有，則無法符合題目條件
                    bool cycled = check_cycle(i);
                    if(cycled){
                        return empty;
                    }
                }
            }

            return topological_sort;
        }
};
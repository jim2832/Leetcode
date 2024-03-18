/*

[[10,16],[2,8],[1,6],[7,12]]
[[1,6],[2,8],[7,12],[10,16]]

*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int n = points.size();
        int arrows = 1;
        
        int cur_end = points[0][1];
        for(int i=0; i<n-1; i++){
            if(cur_end >= points[i+1][0]){
                cur_end = min(cur_end, points[i+1][1]);
            }
            else{
                cur_end = points[i+1][1];
                arrows++;
            }
        }

        return arrows;
    }
};
/*

[1,1] -> [3,4] diff=[2,3] need time 3
[3,4] -> [-1,0] diff=[4,4] need time 4

*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        int n = points.size();

        for(int i=0; i<n-1; i++){
            int x_diff = abs(points[i][0] - points[i+1][0]);
            int y_diff = abs(points[i][1] - points[i+1][1]);
            time += max(x_diff, y_diff);
        }

        return time;
    }
};
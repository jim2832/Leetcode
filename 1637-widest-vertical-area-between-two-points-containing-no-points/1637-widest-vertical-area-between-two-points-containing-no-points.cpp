class Solution {
public:
    static bool compare(vector<int> &vec1, vector<int> &vec2){
        return vec1[0] < vec2[0];
    }

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // sortign the points
        sort(points.begin(), points.end(), compare);
        
        // max value
        int maxi = -INT_MAX;

        for(int i=0; i<points.size()-1; i++){
            maxi = max(maxi, points[i+1][0] - points[i][0]);
        }

        return maxi;
    }
};
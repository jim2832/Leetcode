class Solution {
public:
    int dist(vector<int> point1, vector<int> point2){
        return pow(point1[0]-point2[0], 2) + pow(point1[1]-point2[1], 2);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, int> hash; // distance : count
        
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int dis = dist(points[i], points[j]);
                count += 2 * hash[dis];
                hash[dis]++;
            }
            hash.clear();
        }

        return count;
    }
};
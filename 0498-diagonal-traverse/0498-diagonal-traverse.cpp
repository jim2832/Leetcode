// (0,0) (0,1) (0,2)
// (1,0) (1,1) (1,2)
// (2,0) (2,1) (2,2)

// 走訪順序: (0,0) -> (0,1) -> (1,0) -> (2,0) -> (1,1) -> (0,2) -> (1,2) -> (2,1) -> (2,2)
// index加總是偶數: 往上走訪
// index加總是奇數: 往下走訪

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> result;
        map<int, vector<int>> hash;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                hash[i+j].push_back(mat[i][j]);
            }
        }

        for(auto &pair:hash){
            // cout << pair.first << " -> ";
            // 加總為偶數: 往上走訪
            if(pair.first % 2 == 0){
                for(int i=pair.second.size()-1; i>=0; i--){
                    result.push_back(pair.second[i]);
                }
            }
            // 加總為奇數: 往下走訪
            else{
                for(int i=0; i<pair.second.size(); i++){
                    result.push_back(pair.second[i]);
                }
            }
            // for(int i=0; i<pair.second.size(); i++){
                // cout << pair.second[i] << " ";
            // }
            // cout << endl;
        }
        
        return result;
    }
};
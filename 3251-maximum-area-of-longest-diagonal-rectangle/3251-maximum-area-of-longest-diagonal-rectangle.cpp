class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_dia = 0, max_area = 0;

        for(auto &dim : dimensions){
            int l = dim[0], w = dim[1];
            int dia = l * l + w * w;  // 對角線平方
            int area = l * w;

            if(dia > max_dia || (dia == max_dia && area > max_area)){
                max_dia = dia;
                max_area = area;
            }
        }

        return max_area;
    }
};

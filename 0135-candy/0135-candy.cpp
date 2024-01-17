// 1. 每個小孩至少要1顆糖果
// 2. 如果這個小孩的評分比鄰居高，則他要拿到比鄰居更多的糖果

/*

[1,0,2]
 1 1 2 -> 2 1 2

[1,2,2]
 1 2 1

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // 從頭檢查一遍
        for(int i=0; i<n-1; i++){
            if(ratings[i+1] > ratings[i]){
                candies[i+1] = candies[i] + 1;
            }
        }

        //從尾檢查一遍是否有不合理的分配
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        int result = 0;
        for(auto ele:candies){
            result += ele;
        }

        return result;
    }
};
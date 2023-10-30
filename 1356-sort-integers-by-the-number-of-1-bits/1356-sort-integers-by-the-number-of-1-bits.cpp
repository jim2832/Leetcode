class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> result;
        priority_queue<pair<int, int>> pq;

        for(auto &num:arr){
            int dem = num;
            int count = 0;
            while(dem > 0){
                count += (dem & 1);
                dem = dem >> 1;
            }
            pq.push({count, num});
        }

        while(!pq.empty()){
            // cout << pq.top().first << " " << pq.top().second << endl;
            result.push_back(pq.top().second);
            pq.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
class Solution{
public:
    int binarySearch(vector<vector<int>>& items, int targetPrice){
        int left = 0;
        int right = items.size() - 1;
        int maxBeauty = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(items[mid][0] > targetPrice){
                right = mid - 1;
            }
            else{
                maxBeauty = max(maxBeauty, items[mid][1]);
                left = mid + 1;
            }
        }
        
        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries){
        sort(items.begin(), items.end());

        int maxBeauty = items[0][1];
        for(auto &item : items){
            maxBeauty = max(maxBeauty, item[1]);
            item[1] = maxBeauty;
        }

        for(int i=0; i<queries.size(); i++){
            queries[i] = binarySearch(items, queries[i]);
        }

        return queries;
    }
};
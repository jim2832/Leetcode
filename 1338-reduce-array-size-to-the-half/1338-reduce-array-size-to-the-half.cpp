class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> hash;
        int n = arr.size();
        int half = arr.size() / 2;
        int count = 0;

        for(auto &num:arr){
            hash[num]++;
        }

        for(auto &pair:hash){
            pq.push({pair.second, pair.first}); //frequency:number
        }

        // while(!pq.empty()){
        //     cout << pq.top().first << " " << pq.top().second << endl;
        //     pq.pop();
        // }

        while(n > half){
            n -= pq.top().first;
            pq.pop();
            count++;
        }

        return count;
    }
};
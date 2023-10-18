class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> hash;
        vector<int> result;
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }

        for(auto data:hash){
            pq.push({data.second, data.first});
            // data.second -> 出現次數
            // data.first -> 數字本身
        }

        while(!pq.empty()){
            if(!k) break;
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};
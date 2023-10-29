class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int ,int> hash;
        priority_queue<pair<int, int>> pq;
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            pq.push({-iter->second, iter->first});
        }

        while(!pq.empty()){
            int fre = pq.top().first;
            int num = pq.top().second;
            
            for(int i=0; i<abs(fre); i++){
                result.push_back(num);
            }
            pq.pop();
        }

        return result;

        return {};
    }
};
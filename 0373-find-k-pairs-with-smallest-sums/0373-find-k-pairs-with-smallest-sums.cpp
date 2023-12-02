class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        // min-heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // sum:[ele1,ele2]
        for(int i=0; i<nums1.size(); i++){
            pq.push({nums1[i]+nums2[0], {i,0}});
        }

        while(!pq.empty() && k--){
            // cout << pq.top().first << ": [" << pq.top().second.first << "," << pq.top().second.second << "]" << endl;
            auto temp = pq.top();
            pq.pop();
            int x = temp.second.first, y = temp.second.second;
            result.push_back({nums1[x], nums2[y]});
            if(y != nums2.size()-1){
                pq.push({nums1[x] + nums2[y+1], {x,y+1}});
            }
        }

        return result;
    }
};
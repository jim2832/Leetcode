/*
先記錄每個點在 roads 出現的頻率，再依據頻率來 assign 點的 importance
*/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        unordered_map<int, int> frequency; // node : frequency
        priority_queue<pair<int, int>> pq; // <frequency, node>
        unordered_map<int, int> importance; // node : importance

        // record the frequency of every node
        for(auto &road:roads){
            frequency[road[0]]++;
            frequency[road[1]]++;
        }

        // put the hash table into priority queue
        int freq, node;
        for(auto &pair:frequency){
            node = pair.first;
            freq = pair.second;
            pq.push({freq, node});
        }

        // assign the importance of the node
        int temp = n;
        while(!pq.empty()){
            node = pq.top().second;
            pq.pop();
            importance[node] = n--;
        }

        // accumulate the sum
        long long sum = 0;
        for(auto &road:roads){
            sum += importance[road[0]];
            sum += importance[road[1]];
        }

        return sum;
    }
};
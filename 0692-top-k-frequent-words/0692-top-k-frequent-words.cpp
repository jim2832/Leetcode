#define DS pair<int, string>

class compare{
    public:
        bool operator()(pair<int,string> a, pair<int,string> b){
            if(a.first < b.first){
                return true;
            }
            else if(a.first == b.first && a.second > b.second){
                return true;
            }
            return false;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash; // string:frequency
        for(auto &str:words){
            hash[str]++;
        }

        priority_queue<DS, vector<DS>, compare> pq; // frequency:string
        for(auto &pair:hash){
            pq.push({pair.second, pair.first});
        }

        vector<string> result;
        while(!pq.empty() && k--){
            // cout << pq.top().second << ": " << pq.top().first << endl;
            result.push_back(pq.top().second);
            pq.pop();
        }

        // sort(result.begin(), result.end());

        return result;
    }
};
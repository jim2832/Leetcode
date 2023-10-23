class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        priority_queue<pair<int, char>> pq;
        string result = "";
        
        // build hash table
        for(char &c:s)
            hash[c]++;

        // build priority queue
        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            pq.push({iter->second, iter->first});
        }

        // get data from priority queue and plus to result string
        while(!pq.empty()){
            auto temp = pq.top();
            result += string(temp.first, temp.second);
            pq.pop();
        }

        return result;
    }
};
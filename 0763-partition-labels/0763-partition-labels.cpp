class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        // record the last position of each character
        unordered_map<char, int> hash;
        for(int i=0; i<n; i++){
            hash[s[i]] = i;
        }

        vector<int> result;
        int i = 0;
        int prev_pos = 0;

        while(i < n){
            int cur_last_pos = hash[s[i]];
            while(i <= cur_last_pos){
                cur_last_pos = max(cur_last_pos, hash[s[i]]);
                i++;
            }
            result.push_back(i - prev_pos);
            prev_pos = i;
        }

        return result;
    }
};
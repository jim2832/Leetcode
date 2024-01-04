class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> hash;
        int count = 0;

        // record the frequency of the task
        for(auto &task:tasks){
            hash[task]++;
        }

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            cout << iter->first << ": " << iter->second << endl;
            int freq = iter->second;
            if(freq == 1){
                return -1;
            }
            if(freq % 3 == 0){
                count += (freq / 3);
            }
            else{
                count += (freq / 3) + 1;
            }
        }

        return count;
    }
};
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s;
        int sum = 0, count = 0;

        for(auto &ban : banned){
            if(ban <= n) s.insert(ban);
        }

        for(int num = 1; num <= n; num++){
            if(sum + num > maxSum) break;
            if(!s.count(num)){
                sum += num;
                count++;
            }
        }

        return count;
    }
};
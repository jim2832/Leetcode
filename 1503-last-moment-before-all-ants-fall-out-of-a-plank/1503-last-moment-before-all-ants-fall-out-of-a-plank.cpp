class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;

        // time for the left direction is the max of the number in left vector
        for(int &l:left){
            time = max(time, l);
        }

        // time for the left direction is the max of n munus the number in left vector
        for(int &r:right){
            time = max(time, n-r);
        }

        return time;
    }
};
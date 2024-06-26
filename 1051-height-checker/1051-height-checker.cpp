class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy(heights);
        sort(copy.begin(), copy.end());
        int count = 0;

        for(int i=0; i<copy.size(); i++){
            if(heights[i] != copy[i]) count++;
        }

        return count;
    }
};
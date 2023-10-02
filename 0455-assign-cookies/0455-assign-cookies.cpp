class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int satisfied = 0;
        int i = 0, j = 0; //pointer of two array

        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                satisfied++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return satisfied;
    }
};
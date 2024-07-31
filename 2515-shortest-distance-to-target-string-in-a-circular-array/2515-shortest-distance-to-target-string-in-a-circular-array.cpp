class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int count = 0;

        bool flag = false;
        for(int i=0; i<n; i++){
            if(words[i] == target) flag = true;
        }
        if(!flag) return -1;

        int i = startIndex, j = startIndex;
        while(words[i] != target && words[j] != target){
            i = (i - 1 + n) % n;
            j = (j + 1 + n) % n;
            count++;
        }

        return count;
    }
};
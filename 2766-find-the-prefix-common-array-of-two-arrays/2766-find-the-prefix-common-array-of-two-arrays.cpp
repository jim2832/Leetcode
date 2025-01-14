class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int count = 0;
        vector<bool> seen(n+1, false);
        vector<int> result(n);

        for(int i=0; i<n; i++) {
            if(seen[A[i]]) count++;
            if(seen[B[i]]) count++;
            if(A[i] == B[i]) count++;
            seen[A[i]] = seen[B[i]] = true;
            result[i] = count;
        }

        return result;
    }
};

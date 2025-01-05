class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long cumulativeShift = 0;

        for(int i=n-1; i>=0; i--) {
            cumulativeShift += shifts[i];
            shifts[i] = cumulativeShift % 26;
        }

        for(int i=0; i<n; i++) {
            s[i] = 'a' + (s[i] - 'a' + shifts[i]) % 26;
        }

        return s;
    }
};

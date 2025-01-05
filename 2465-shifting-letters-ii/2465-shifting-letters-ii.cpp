class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> change(n + 1, 0);

        for(auto &shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = (shift[2] == 0) ? -1 : 1;

            change[start] += direction;
            change[end+1] -= direction;
        }

        for(int i=1; i<n; i++) {
            change[i] += change[i-1];
        }

        for(int i=0; i<n; i++) {
            s[i] = 'a' + (s[i] - 'a' + change[i] % 26 + 26) % 26;
        }

        return s;
    }
};

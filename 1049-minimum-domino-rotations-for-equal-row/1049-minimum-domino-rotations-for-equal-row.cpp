class Solution {
public:
    int check(int target, vector<int>& A, vector<int>& B) {
        int n = A.size();
        int swap_a = 0, swap_b = 0;

        for(int i = 0; i < n; i++) {
            if(A[i] != target && B[i] != target) return -1;
            else if(A[i] != target) swap_a++;  // need to bring target to top
            else if(B[i] != target) swap_b++;  // need to bring target to bottom
        }
        
        return min(swap_a, swap_b);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = check(tops[0], tops, bottoms);
        if(ans != -1) return ans;
        return check(bottoms[0], tops, bottoms);
    }
};

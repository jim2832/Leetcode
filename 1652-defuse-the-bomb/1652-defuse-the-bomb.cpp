class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if(k > 0){
            for(int i=0; i<n; i++){
                for(int j=1; j<=k; j++){
                    result[i] += code[(i+j+n) % n];
                }
            }
        }
        else if(k < 0){
            for(int i=0; i<n; i++){
                for(int j=1; j<=-k; j++){
                    result[i] += code[(i-j+n) % n];
                }
            }
        }

        return result;
    }
};
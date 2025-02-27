class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxi = INT_MIN;
        unordered_set<int> s(arr.begin(), arr.end());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int len = 2;
                int first = arr[i];
                int second = arr[j];
                while(s.count(first + second)){
                    len++;
                    int temp = second;
                    second = first + second;
                    first = temp;
                }
                maxi = max(maxi, len);
            }
        }

        return maxi == 2 ? 0 : maxi;
    }
};
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for(auto &num : arr){
            int rem = num % k;
            if(rem < 0) rem += k; // negtive case
            freq[rem]++;
        }

        if(freq[0] % 2) return false; // mod 後為 0 的個數必須為偶數

        for(int i=1; i<=k/2; i++){
            if(freq[i] != freq[k-i]) return false;
        }

        return true;
    }
};
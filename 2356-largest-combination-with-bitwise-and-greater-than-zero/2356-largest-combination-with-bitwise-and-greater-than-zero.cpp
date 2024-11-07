class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        vector<int> bits(32);

        for(auto &candidate : candidates){
            for(int i=31; i>=0; i--){
                bits[i] += (candidate & 1);
                candidate >>= 1;
            }
        }

		for(auto &bit : bits){
			ans = max(ans, bit);
        }

		return ans;
    }
};
class Solution{
public:
    string findDifferentBinaryString(vector<string>& nums){
        unordered_set<string> s(nums.begin(), nums.end());
        int n = nums[0].size(), num = 0;
        string ans;

        while(true){
            ans = bitset<16>(num).to_string().substr(16 - n); // 確保是 n 位元
            if(!s.count(ans)) break;
            num++;
        }

        return ans;
    }
};

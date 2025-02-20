class Solution{
public:
    string findDifferentBinaryString(vector<string>& nums){
        unordered_set<string> s(nums.begin(), nums.end());
        int n = nums.size(), num = 0;
        string str;

        while(true){
            str = bitset<16>(num).to_string().substr(16 - n); // 確保是 n 位元
            if(!s.count(str)) break;
            num++;
        }

        return str;
    }
};

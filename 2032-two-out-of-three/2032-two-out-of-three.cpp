class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> s1, s2, s3;
        unordered_map<int, int> hash;
        vector<int> result;

        // 消除重複項
        for(int &num:nums1)
            s1.insert(num);
        for(int &num:nums2)
            s2.insert(num);
        for(int &num:nums3)
            s3.insert(num);

        // 計算出現次數
        for(auto &s:s1)
            hash[s]++;
        for(auto &s:s2)
            hash[s]++;
        for(auto &s:s3)
            hash[s]++;

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            if(iter->second >= 2){
                result.push_back(iter->first);
            }
        }

        return result;
    }
};
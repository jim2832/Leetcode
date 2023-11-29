/*

nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
nums1[i] + nums2[j] = -(nums3[k] + nums4[l])
nums1[i] + nums2[j] + nums3[k] = -nums4[l]

*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> hash;

        for(auto &i:nums1){
            for(auto &j:nums2){
                hash[i+j]++;
            }
        }

        for(auto &i:nums3){
            for(auto &j:nums4){
                auto iter = hash.find(-(i+j));
                if(iter != hash.end()){
                    count += iter->second;
                }
            }
        }

        return count;
    }
};
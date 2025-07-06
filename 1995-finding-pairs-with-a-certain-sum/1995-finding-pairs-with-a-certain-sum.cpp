class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> hashMap2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int num : nums2){
            hashMap2[num]++;
        }
    }
    
    void add(int index, int val) {
        int oldVal = vec2[index];
        int newVal = oldVal + val;

        // 更新 hashMap2
        hashMap2[oldVal]--;
        if(hashMap2[oldVal] == 0) {
            hashMap2.erase(oldVal);
        }
        hashMap2[newVal]++;

        vec2[index] = newVal;
    }
    
    int count(int tot) {
        int pairs = 0;
        for(int num1 : vec1){
            int target = tot - num1;
            if(hashMap2.count(target)){
                pairs += hashMap2[target];
            }
        }
        return pairs;
    }
};

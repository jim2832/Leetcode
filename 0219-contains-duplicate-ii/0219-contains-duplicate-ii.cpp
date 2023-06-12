class Solution{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k){
            unordered_map<int, int> index;
            for(int i=0; i<nums.size(); i++){
                // 檢查nums[i]是否有出現在index過
                auto iter = index.find(nums[i]);
                if(iter != index.end()){
                    if(i - index[nums[i]] <= k){
                        return true;
                    }
                }
                index[nums[i]] = i; //更新位置
            }
            return false;
        }
};
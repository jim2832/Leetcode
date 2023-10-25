class Solution {
public:
    unordered_map<int, vector<int>> hash;

    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        if(hash[target].size() == 1){
            return hash[target][0];
        }
        else{
            random_device rd;  // 用于种子的随机设备
            mt19937 gen(rd()); // Mersenne Twister 伪随机数生成器

            if(hash.find(target) != hash.end()){
                int start = 0, end = hash[target].size()-1;
                // 创建一个分布，指定范围为1到5
                uniform_int_distribution<int> distribution(start, end);

                // 生成随机数
                int random_number = distribution(gen);
                
                return hash[target][random_number];
            }
        }

        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
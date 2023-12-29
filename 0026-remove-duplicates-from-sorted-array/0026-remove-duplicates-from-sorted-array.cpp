class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 初始化一個指標 i，表示不重複元素的結尾位置
        int i = 0;

        // 使用迴圈從第二個元素開始遍歷整個陣列
        for(int j=1; j<nums.size(); j++){
            // 如果目前位置的元素與上一個不同
            if(nums[i] != nums[j]){
                // 把目前位置的元素放到指標 i 的下一個位置
                nums[i+1] = nums[j];
                // 更新指標 i
                i++;
            }
        }

        // 返回不重複元素的個數（因為索引從 0 開始，所以加 1）
        return i+1;
    }
};

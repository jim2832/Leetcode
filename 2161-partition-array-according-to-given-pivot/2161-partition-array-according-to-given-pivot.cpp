class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, greater;
        int count = 0;
        
        for(auto &num : nums){
            if(num < pivot) less.push_back(num);
            else if(num > pivot) greater.push_back(num);
            else count++;
        }

        for(int i=0; i<count; i++) less.push_back(pivot);
        for(auto &ele : greater) less.push_back(ele);

        return less;
    }
};
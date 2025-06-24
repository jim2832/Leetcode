class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> result;

        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                for(int j = i - k; j <= i + k; j++){
                    if(j >= 0 && j < n){
                        visited[j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(visited[i]) result.push_back(i);
        }

        return result;
    }
};

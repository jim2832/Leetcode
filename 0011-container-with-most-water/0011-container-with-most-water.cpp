class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxi = INT_MIN;

        while(i < j){
            maxi = max(maxi, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;
        }

        return maxi;
    }
};
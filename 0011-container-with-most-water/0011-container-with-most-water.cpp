class Solution {
public:

    // brutal force
    /*
    int maxArea(vector<int>& height) {
        int max = 0, flow = 0;
        int h, w;

        for(int i=0; i<height.size()-1; i++){
            for(int j=i+1; j<height.size(); j++){
                h = min(height[i], height[j]);
                w = abs(i-j);
                flow = h * w;
                max = flow > max ? flow : max;
            }
        }
        return max;
    }
    */

    // another approach
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max = 0, flow = 0;
        int h, w;

        while(i < j){
            h = min(height[i], height[j]);
            w = abs(i-j);
            flow = h * w;
            max = flow > max ? flow : max;
            
            // 如果水管沒有更高，就不可能有更多的水量，因此跳過比現在矮的水管
            while(height[i] <= h && i < j) i++;
            while(height[j] <= h && i < j) j--;
        }

        return max;
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // merge two vectors
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        // sorting
        sort(nums1.begin(), nums1.end());

        int n = nums1.size();
        double result;

        if(n % 2)
            result = nums1[n/2];
        else
            result = (double)(nums1[n/2] + nums1[n/2-1]) / 2;

        return result;
    }
};
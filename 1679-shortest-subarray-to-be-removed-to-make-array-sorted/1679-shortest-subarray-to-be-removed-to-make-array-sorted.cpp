class Solution{
public:
    int findLengthOfShortestSubarray(vector<int>& arr){
        int n = arr.size();
        int i = 0, j = n - 1;

        while(i < n - 1 && arr[i] <= arr[i + 1]) i++;
        if(i == n - 1) return 0;
        while(j > 0 && arr[j - 1] <= arr[j]) j--;

        int result = min(n - i - 1, j);

        int left = 0, right = j;
        while(left <= i && right < n){
            if(arr[left] <= arr[right]){
                result = min(result, right - left - 1);
                left++;
            }
            else{
                right++;
            }
        }

        return result;
    }
};

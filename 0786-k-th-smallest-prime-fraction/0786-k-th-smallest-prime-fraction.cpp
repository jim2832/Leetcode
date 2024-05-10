class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, vector<int>>> numbers;

        int n = arr.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                double value = (double)arr[i] / arr[j];
                numbers.push_back({value, {arr[i], arr[j]}});
            }
        }

        sort(numbers.begin(), numbers.end());

        return numbers[k-1].second;
    }
};
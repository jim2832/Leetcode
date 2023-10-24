class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        unordered_set<int> s;
        for(int &i:arr){
            s.insert(i);
        }

        sort(arr.begin(), arr.end());
        int min = INT_MAX;
        for(int i=1; i<arr.size(); i++){
            min = arr[i] - arr[i-1] < min ? arr[i] - arr[i-1] : min;
        }

        for(int i=1; i<arr.size(); i++){
            if(arr[i] - arr[i-1] == min){
                result.push_back({arr[i-1], arr[i]});
            }
        }

        return result;
    }
};
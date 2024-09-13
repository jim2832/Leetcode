/*
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;

        for(auto &query : queries){
            int temp = 0;
            for(int i=query[0]; i<=query[1]; i++) temp ^= arr[i];
            result.push_back(temp);
        }

        return result;
    }
};
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;

        for(int i=0; i<arr.size()-1; i++){
            arr[i+1] ^= arr[i];
        }

        for(auto &query : queries){
            int start = query[0];
            int end = query[1];
            int temp = start ? arr[start-1] ^ arr[end] : arr[end];
            result.push_back(temp);
        }

        return result;
    }
};
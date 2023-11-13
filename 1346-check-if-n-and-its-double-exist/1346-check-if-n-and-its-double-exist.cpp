class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int i=0; i<arr.size(); i++){
            // even
            if(arr[i] % 2 == 0){
                if(s.count(arr[i] * 2) || s.count(arr[i] / 2)){
                    return true;
                }
            }
            else{ // odd
                if(s.count(arr[i] * 2)){
                    return true;
                }
            }
            s.insert(arr[i]);
        }

        return false;
    }
};
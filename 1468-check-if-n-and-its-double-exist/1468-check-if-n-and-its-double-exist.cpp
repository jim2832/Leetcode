class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;

        for(auto &ele : arr){
            if(s.count(ele * 2)) return true;
            else if(ele % 2 == 0 && s.count(ele / 2)) return true;
            s.insert(ele);
        }

        return false;
    }
};
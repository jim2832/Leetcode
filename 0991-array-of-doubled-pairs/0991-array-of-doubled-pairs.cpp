class Solution {
public:
    static bool compare(int &a, int &b){
        return abs(a) < abs(b);
    }

    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> hash;

        for(auto &ele : arr){
            hash[ele]++;
        }

        sort(arr.begin(), arr.end(), compare);

        for(auto &ele : arr){
            if(hash[ele] > 0 && hash[2*ele] > 0){
                hash[ele]--;
                hash[2*ele]--;
            }
            else if(hash[ele] > 0 && hash[2*ele] <= 0){
                return false;
            }
        }

        return true;
    }
};
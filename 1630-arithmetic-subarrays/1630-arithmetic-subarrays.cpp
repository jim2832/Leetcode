// [-2,-8,-6,0] -> [0,-2,-6,-8]

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<int> temp;
        vector<bool> result;

        for(int i=0; i<l.size(); i++){
            int start = l[i];
            int end = r[i];
            for(int j=start; j<=end; j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            bool flag = true;
            for(int j=0; j<temp.size()-1; j++){
                // cout << temp[j] << " ";
                if(abs(temp[j+1] - temp[j]) == abs(temp[1] - temp[0])){
                    flag = true;
                }
                else{
                    flag = false;
                    break;
                }
            }
            result.push_back(flag);
            // cout << endl;
            temp.clear();
        }

        return result;
    }
};
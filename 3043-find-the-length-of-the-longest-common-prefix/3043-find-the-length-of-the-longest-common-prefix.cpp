class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s;
        int max_len = 0;

        for(auto &n1 : arr1){
            string str1 = to_string(n1), temp;
            for(int i=0; i<str1.size(); i++){
                temp += str1[i];
                s.insert(temp);
            }
        }

        for(auto &n2 : arr2){
            string str2 = to_string(n2), temp;
            for(int i=0; i<str2.size(); i++){
                temp += str2[i];
                int n = temp.size();
                if(s.count(temp)){
                    max_len = max(max_len, n);
                }
            }
        }

        return max_len;
    }
};
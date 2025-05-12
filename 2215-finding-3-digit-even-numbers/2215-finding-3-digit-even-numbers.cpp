class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int hash[10] = {0};
        vector<int> result;

        for(auto &digit : digits){
            hash[digit]++;
        }

        for(int num = 100; num < 999; num += 2){
            // record the frequency
            int cur[10] = {0};
            int temp = num;
            while(temp){
                cur[temp % 10]++;
                temp /= 10;
            }

            // check if the number can be generated
            bool flag = true;
            for(int i = 0; i < 10; i++){
                if(cur[i] > hash[i]){ // exceed
                    flag = false;
                    break;
                }
            }

            if(flag) result.emplace_back(num);
        }

        return result;
    }
};
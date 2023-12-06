class Solution {
public:
    int totalMoney(int n) {
        int day = 1;
        int total = 0;
        int Monday_money = 0;
        int current_money = 1;

        while(day <= n){
            // Monday
            if(day % 7 == 1){
                Monday_money++;
                current_money = Monday_money;
            }
            
            total += current_money;
            current_money++;

            day++;
        }

        return total;
    }
};
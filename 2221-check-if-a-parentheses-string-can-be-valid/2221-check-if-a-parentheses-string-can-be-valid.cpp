class Solution{
public:
    bool canBeValid(string s, string locked){
        int n = s.size();
        if(n % 2) return false;

        int free = 0, balance = 0;

        // 從左到右：確保右括號數量不會超過可配對的左括號數量。
        for(int i=0; i<n; i++){
            if(locked[i] == '0'){
                free++;
            }
            else if(s[i] == '('){
                balance++; // 鎖定的左括號增加平衡
            }
            else{
                balance--; // 鎖定的右括號減少平衡
            }

            // 如果平衡被打破，嘗試用未鎖定括號修復
            if(balance < 0){
                if(free > 0){
                    free--;
                    balance++;
                }
                else{
                    return false; // 無法修復，返回 false
                }
            }
        }

        free = 0;
        balance = 0;
        
        // 從右到左：確保左括號數量不會超過可配對的右括號數量。
        for(int i=n-1; i>=0; i--){
            if(locked[i] == '0'){
                free++;
            }
            else if(s[i] == ')'){
                balance++; // 鎖定的右括號增加平衡
            }
            else{
                balance--; // 鎖定的左括號減少平衡
            }

            // 如果平衡被打破，嘗試用未鎖定括號修復
            if(balance < 0){
                if(free > 0){
                    free--;
                    balance++;
                }
                else{
                    return false; // 無法修復，返回 false
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        //記錄某一天知道秘密的人數
        vector<long long> knowing(n, 0);

        //總共知道的人數
        long long total_knowing = 0;

        //要mod的數字
        int mod = 1e9 + 7;

        //第一天只有1個人知道秘密
        knowing[0] = 1;

        //總共有n天
        for(auto day=0; day<n; day++){
            for(auto delayy=delay; delayy<forget && day+delayy<n; delayy++){
                //計算在 day+delay 天知道秘密的人數
                knowing[day+delayy] = (knowing[day+delayy] + knowing[day]) % mod;
            }
            //更新所有知道秘密的人數
            total_knowing = (total_knowing + knowing[day]) % mod;

            //去除忘記的情況
            if(day >= forget){
                total_knowing = (total_knowing - knowing[day - forget] + mod) % mod;
            }
        }

        return total_knowing;
    }
};
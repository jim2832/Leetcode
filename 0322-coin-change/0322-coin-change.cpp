/*
class Solution {
public:
    //這邊是用貪婪演算法(greedy)來做，但答案會是錯的(因為只考慮到局部最佳解)

    int coinChange(vector<int>& coins, int amount) {
        // exception
        if(!amount){
            return 0;
        }

        sort(coins.begin(), coins.end(), greater<int>()); //排序(由大到小)
        int coin = 0; //紀錄有幾枚硬幣
        int len = coins.size();

        for(int i=0; i<len; i++){
            int value = coins[i]; //目前硬幣的面額
            coin += amount / value; //目前要找幾枚硬幣(例如11元一開始找11/5=2枚)
            amount %= value; //剩餘要找的錢
        }

        // 如果最後要找的錢為0(也就是全部找開了)則回傳數量，否則回傳-1
        return (!amount) ? coin : -1;
    }
};
*/

// 以下為 DP 的方法

// 現在有三種硬幣：1元 5元 8元
// 假設找 x 元時需要 coin(x) 枚硬幣
// coin(1) = 1
// coin(2) = 2
// coin(3) = 3
// coin(4) = 4
// coin(5) = 1

// 6元硬幣可能有兩種情形
// 1. 至少有一枚1元硬幣: 1 + coin(5)
// 2. 至少有一枚5元硬幣: 1 + coin(1)
// coin(6) = min(1 + coin(5), 1 + coin(1))

// x元硬幣可能會有三種情形，從中挑硬幣最少的
// 1. 至少有一枚1元硬幣: 1 + coin(x-1)
// 2. 至少有一枚5元硬幣: 1 + coin(x-5)
// 3. 至少有一枚8元硬幣: 1 + coin(x-8)
// coin(x) = min(1 + coin(x-1), 1 + coin(x-5), 1 + coin(x-8))
// = 1 + min(coin(x-1), coin(x-5), coin(x-8))

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // exception
        if(!amount){
            return 0;
        }

        // 代表 n 元需要 min_coin[n-1]
        // 一開始將所有值都初始化為-1，表示還沒解過
        vector<int> min_coin(amount, -1);

        for(int i=0; i<amount; i++){
            // min_coin[i] = 1 + min(
            // min_coin[i-coins[0]],
            // min_coin[i-coins[1]],
            // min_coin[i-coins[2]],
            // ...
            // min_coin[i-coins[amount]]
            // )

            int min = 2147483647;
            for(int coin:coins){
                int current = i+1-coin; //代表目前還有多少錢要找
                int coin_now;

                if(current < 0){
                    coin_now = 2147483647;
                }
                else if(current == 0){
                    coin_now = 0;
                }
                else{ //current > 0
                    if(min_coin[current-1] == -1){
                        coin_now = 2147483647;
                    }
                    else{
                        coin_now = min_coin[current-1];
                    }
                }
                min = coin_now < min ? coin_now : min;
            }

            if(min == 2147483647){
                min_coin[i] = -1;
            }
            else{
                min_coin[i] = min + 1;
            }
        }

        return min_coin[amount-1];
    }
};
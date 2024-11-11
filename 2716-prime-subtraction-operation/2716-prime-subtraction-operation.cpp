class Solution{
public:
    bool primeSubOperation(vector<int>& nums){
        int n = nums.size();
        bool result = true;
        int prev = nums.back(); // the last element

        vector<int> prime; // 儲存所有質數
        vector<bool> isPrime(1005, true);

        isPrime[0] = isPrime[1] = false; // 0 和 1 不是質數
        for(int i=2; i<1005; i++){
            if(isPrime[i]){
                prime.push_back(i); // 若是質數，加入列表
                for(int j=2*i; j<1005; j+=i){
                    isPrime[j] = false; // 將質數的倍數標記為非質數
                }
            }
        }

        for(int i=n-2; i>=0; i--){
            // 符合嚴格遞增
            if(nums[i] < prev){
                prev = nums[i];
                continue;
            }

            // 不符合嚴格遞增
            result = false;

            // 嘗試找到一個最佳的質數
            for(int sub=0; sub < prime.size() && prime[sub] < nums[i]; sub++){
                if(nums[i] - prime[sub] < prev){
                    prev = nums[i] - prime[sub];
                    result = true;
                    break;
                }
            }

            // 無法透過相減達成嚴格遞增
            if(!result) break;
        }

        return result;
    }
};
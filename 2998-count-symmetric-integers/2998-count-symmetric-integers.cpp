class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int num = low; num <= high; num++){
            int digits[6];
            int len = 0, temp = num;

            while(temp){
                digits[len] = temp % 10;
                temp /= 10;
                len++;
            }

            if(len % 2) continue;
            len /= 2;

            int left_sum = 0, right_sum = 0;
            for(int i=0; i<len; i++){
                left_sum += digits[i];
                right_sum += digits[i + len];
            }

            if(left_sum == right_sum) count++;
        }

        return count;
    }
};
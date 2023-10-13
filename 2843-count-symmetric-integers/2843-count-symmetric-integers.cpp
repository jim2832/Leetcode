class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int num=low; num<=high; num++){
            int left = 0, right = 0;
            string str = to_string(num);
            int len = str.size();

            if(len % 2 == 0){
                for(int j=0; j<len; j++){
                    // left
                    if(j < len/2){
                        left += str[j] - '0';
                    }
                    //right
                    else{
                        right += str[j] - '0';
                    }

                }
                if(left == right){
                    count++;
                }
            }
        }

        return count;
    }
};
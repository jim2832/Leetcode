class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;

        for(int num=0; num<n; num++){
            if((num+1) % 3 == 0 && (num+1) % 5 == 0){
                result.push_back("FizzBuzz");
                continue;
            }
            else if((num+1) % 3 == 0){
                result.push_back("Fizz");
            }
            else if((num+1) % 5 == 0){
                result.push_back("Buzz");
            }
            else{
                result.push_back(to_string(num+1));
            }
        }

        return result;
    }
};
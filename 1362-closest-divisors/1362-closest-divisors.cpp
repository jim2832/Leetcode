class Solution {
public:
    vector<int> helper(int num) {
        vector<int> result;
        int mini = INT_MAX;

        for(int i=1; i<=sqrt(num); i++){
            if(num % i == 0){
                if(mini > abs(num/i - i)){
                    mini = abs(num/i - i);
                    result = {num/i, i};
                }
            }
        }

        return result;
    }

    vector<int> closestDivisors(int num) {
        int mini = INT_MAX;
        vector<int> vec1 = helper(num + 1);
        vector<int> vec2 = helper(num + 2);

        if(abs(vec1[0] - vec1[1]) < abs(vec2[0] - vec2[1])){
            return vec1;
        }

        return vec2;
    }
};
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            if(!grumpy[i]){
                sum += customers[i];
                customers[i] = 0;
            }
        }

        int temp_sum = 0;
        for(int i=0; i<minutes; i++){
            temp_sum += customers[i];
        }

        int maxi = temp_sum;
        for(int i=minutes; i<n; i++){
            temp_sum -= customers[i-minutes];
            temp_sum += customers[i];
            maxi = max(maxi, temp_sum);
        }

        return sum + maxi;
    }
};
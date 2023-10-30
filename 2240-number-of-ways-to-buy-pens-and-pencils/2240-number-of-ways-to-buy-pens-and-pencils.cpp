class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long count = 0;
        long long greater = max(cost1, cost2);
        long long smaller = min(cost1, cost2);
        long long greater_num = 0;

        while(greater * greater_num <= total){
            long long rest = total - greater * greater_num;
            count += rest ? (rest / smaller) + 1 : 1;
            greater_num++;
        }

        return count;
    }
};
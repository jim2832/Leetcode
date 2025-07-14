class Solution {
public:
    int newNum(int n){
        int temp = 0;
        while(n){
            temp += (n % 10) * (n % 10);
            n /= 10;
        }
        return temp;
    }

    bool isHappy(int n) {
        int current = n;
        unordered_set<int> s;

        while(current != 1){
            current = newNum(current);
            if(s.count(current)) return false;
            s.insert(current);
        }

        return true;
    }
};
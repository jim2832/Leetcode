class Solution {
public:
    int distMoney(int money, int children) {
        int max_8 = 0;
        
        if(money < children)
            return -1;

        if(money > children * 8)
            return children - 1;

        while(money && money - 8 >= children - 1){
            max_8++;
            money -= 8;
            children--;
        }

        if(money == 4 && children == 1)
            max_8--;

        return max_8;
    }
};
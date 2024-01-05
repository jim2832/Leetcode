/*

q -> [1,2,3,4,5]
1 2 -> 2淘汰

q -> [1,3,4,5]
3 4 -> 4淘汰

q -> [1,3,5]
5 1 -> 1淘汰

q -> [3,5]
3 5 -> 5淘汰

*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        // init the vector
        vector<int> people;
        for(int i=1; i<=n; i++){
            people.push_back(i);
        }

        int index = 0;
        while(people.size() != 1){
            index = (index + k - 1) % people.size();
            people.erase(people.begin() + index);
        }

        return people[0];
    }
};
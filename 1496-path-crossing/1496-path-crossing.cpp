/*
用set來記錄走過的點，若有重複立即回傳true
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;
        auto current = make_pair(0,0);
        visited.insert(current);

        for(auto &c:path){
            if(c == 'N'){
                current.first++;
            }
            else if(c == 'S'){
                current.first--;
            }
            else if(c == 'E'){
                current.second++;
            }
            else if(c == 'W'){
                current.second--;
            }

            // check if it is existed
            if(visited.find(current) != visited.end()){
                return true;
            }

            visited.insert(current);
        }

        return false;
    }
};
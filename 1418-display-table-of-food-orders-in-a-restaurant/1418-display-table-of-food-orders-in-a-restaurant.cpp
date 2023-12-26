/*
每個 order 的內容代表
0. 客人名字
1. 桌號
2. 食物
*/

class Solution {
public:
    static bool compare(vector<string> &vec1, vector<string> &vec2){
        return stoi(vec1[0]) < stoi(vec2[0]);
    }

    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string, unordered_map<string, int>> hash; // <桌號, <食物, 數量>>
        set<string> foods = {};
        vector<string> head_row = {"Table"};
        vector<vector<string>> result;

        string table;
        for(auto &vec:orders){
            table = vec[1];
            string food = vec[2];
            foods.insert(food); // record the category of the food
            hash[table][food]++;
        }

        // head row
        for(auto &ele:foods){
            head_row.push_back(ele);
        }
        // result.push_back(head_row);

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            vector<string> temp;
            table = iter->first;
            temp.push_back(table);

            unordered_map<string, int> food_table = iter->second;
            for(auto &food:foods){
                if(food_table[food] == 0){
                    temp.push_back("0");
                }
                else{
                    temp.push_back(to_string(food_table[food]));
                }
            }
            result.push_back(temp);
        }
        sort(result.begin(), result.end(), compare);

        result.insert(result.begin(), head_row);

        return result;
    }
};
class FoodRatings {
public:
    map<string, pair<string, int>> record; // foods : {cuisine, rating}
    map<string, map<int, set<string>>> highest_rating; // cuisine : set<pair<rating, food>>

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            record[foods[i]] = {cuisines[i], ratings[i]};
            highest_rating[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        // update record
        auto food_info = record.find(food);
        string cuisine = food_info->second.first;
        int oldRating = food_info->second.second;
        food_info->second.second = newRating;

        // update highest_rating
        highest_rating[cuisine][oldRating].erase(food);
        if (highest_rating[cuisine][oldRating].empty())
            highest_rating[cuisine].erase(oldRating);

        highest_rating[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *highest_rating[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
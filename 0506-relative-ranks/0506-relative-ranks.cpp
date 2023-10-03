class Solution {
public:
    int find_max_index(vector<int>& score){
        int max_index;
        int max = -INT_MAX;

        for(int i=0; i<score.size(); i++){
            if(max < score[i]){
                max = score[i];
                max_index = i;
            }
        }

        return max_index;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        int max_index;
        vector<string> result(score.size(), "");
        vector<string> award = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        //初始化 award
        for(int i=3; i<score.size(); i++){
            award.push_back(to_string(i+1));
        }

        for(int i=0; i<score.size(); i++){
            max_index = find_max_index(score);
            score[max_index] = -1;
            result[max_index] = award[0];
            if (!award.empty()){
                award.erase(award.begin()); // Erase the first element
            }
        }

        return result;
    }
};
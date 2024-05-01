class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int index = 0;

        for(int i=0; i<s.size(); i++){
            if(index < spaces.size() && i == spaces[index]){
                result += " ";
                index++;
            }
            result += s[i];
        }

        return result;
    }
};
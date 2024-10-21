class Solution {
public:
    int backtrack(int start, string &s, unordered_set<string> &seen){
        if(start == s.size()){
            return 0;
        }

        int max_split = 0;
        for(int end=start+1; end<=s.size(); end++){
            string sub_string = s.substr(start, end-start);
            if(!seen.count(sub_string)){
                seen.insert(sub_string);
                max_split = max(max_split, 1 + backtrack(end, s, seen));
                seen.erase(sub_string);
            }
        }
        
        return max_split;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(0, s, seen);
    }
};
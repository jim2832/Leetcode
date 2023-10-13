class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> hash;
        for(int i=0; i<moves.size(); i++){
            hash[moves[i]]++;
        }

        // for(auto iter=hash.begin(); iter!=hash.end(); iter++){
        //     cout << "string: " << iter->first << "\t" << "times: " << iter->second << endl;
        // }

        return abs(hash['_'] + max(hash['R'], hash['L']) - min(hash['R'], hash['L']));
    }
};
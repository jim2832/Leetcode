class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> hash(1024, 0);
        hash[0] = 1;
        long long result = 0;
        int bitmask = 0;

        for(auto &c : word){
            int index = c - 'a';
            bitmask ^= 1 << index;
            result += hash[bitmask];

            for(int i=0; i<10; i++){
                result += hash[bitmask ^ (1 << i)];
            }

            hash[bitmask]++;
        }

        return result;
    }
};
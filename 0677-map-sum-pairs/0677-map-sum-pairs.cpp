class MapSum {
public:
    unordered_map<string, int> hash;

    MapSum() {
        
    }
    
    void insert(string key, int val) {
        hash[key] = val;
    }
    
    int sum(string prefix) {
        int n = prefix.size();
        int sum = 0;

        // traverse the hash table
        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            string temp = iter->first;
            if(prefix == temp.substr(0, n)){
                sum += iter->second;
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
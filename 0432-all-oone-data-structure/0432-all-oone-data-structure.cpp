class AllOne {
public:
    unordered_map<string, int> hash;

    AllOne() {
        
    }
    
    void inc(string key) {
        hash[key]++;
    }
    
    void dec(string key) {
        hash[key]--;
        if(hash[key] == 0){
            hash.erase(key);
        }
    }
    
    string getMaxKey() {
        if(hash.empty()){
            return "";
        }
        int max = -INT_MAX;
        string maxKey;
        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            if(max < iter->second){
                max = iter->second;
                maxKey = iter->first;
            }
        }
        return maxKey;
    }
    
    string getMinKey() {
        if(hash.empty()){
            return "";
        }
        int min = INT_MAX;
        string minKey;
        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            if(min > iter->second){
                min = iter->second;
                minKey = iter->first;
            }
        }
        return minKey;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
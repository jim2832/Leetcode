class MyHashSet {
public:
    vector<int> s;

    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(s.begin(), s.end(), key) != s.end()){
            return;
        }
        s.push_back(key);
    }
    
    void remove(int key) {
        for(int i=0; i<s.size(); i++){
            if(s[i] == key){
                s.erase(s.begin() + i);
            }
        }
    }
    
    bool contains(int key) {
        for(int i=0; i<s.size(); i++){
            if(s[i] == key){
                return true;
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
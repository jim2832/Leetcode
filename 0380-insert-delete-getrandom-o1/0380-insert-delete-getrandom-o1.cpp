class RandomizedSet {
public:
    unordered_map<int, int> hash;
    vector<int> array;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hash.find(val) == hash.end()){
            array.push_back(val);
            hash[val] = array.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        // 1. 將 array 中的 val 刪除
        // 2. 將 hash table 中的 val entry 刪除
        // 重點: 要只靠 unordered_map 的操作來實現
        if(hash.find(val) != hash.end()){
            auto iter = hash.find(val);
            int index = iter->second;

            array[index] = array.back(); // 將 array 最後一個元素複製到要刪除元素的位置
            array.pop_back(); // 刪除最後一個元素

            // 更新 hash table
            hash[array[index]] = index;
            hash.erase(val);
            
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return array[rand() % array.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
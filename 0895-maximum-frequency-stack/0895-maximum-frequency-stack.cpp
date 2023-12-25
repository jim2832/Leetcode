class FreqStack {
public:
    // 使用 unordered_map 來儲存每個數字對應的index x
    unordered_map<int, int> mp;

    // 使用 unordered_map 來儲存每個數字的出現頻率
    unordered_map<int, int> freq;

    // 使用 set 來儲存一對 {頻率, 索引}，依照頻率和索引的大小自動排序
    set<pair<int, int>> s;

    // 用來記錄每次 push 操作的索引值
    int x = 0;

    FreqStack() {
        
    }
    
    void push(int val) {
        // 1. udpate the frequency of the number
        freq[val]++;

        // 2. map the index to the number (val)
        mp[x] = val;
        
        // 3. maintain the set which element is {freq, x}
        s.insert({freq[val], x++});
    }
    
    int pop() {
        auto it = *s.rbegin();  // 取得 set 中最後一個元素的 {頻率, 索引} 這對值 (也就是最大頻率的)
        s.erase(it);  // 從 set 中移除這對值

        int val = mp[it.second];  // 取得數字 val
        freq[val]--;  // 減少 val 的出現頻率

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
class MyCalendar {
public:
    map<int, int> hash;

    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto iter = hash.upper_bound(start);
        if(iter == hash.end() || iter->second >= end){
            hash[end] = start;
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
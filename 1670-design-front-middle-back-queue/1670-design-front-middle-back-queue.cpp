class FrontMiddleBackQueue {
public:
    vector<int> queue;

    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        queue.insert(queue.begin(), val);
    }
    
    void pushMiddle(int val) {
        int mid = queue.size() / 2;
        queue.insert(queue.begin() + mid, val);
    }
    
    void pushBack(int val) {
        queue.push_back(val);
    }
    
    int popFront() {
        if(queue.empty()) return -1;
        int temp = queue[0];
        queue.erase(queue.begin());
        return temp;
    }
    
    int popMiddle() {
        if(queue.size()==0) return -1;
        int mid = (queue.size()-1) / 2;
        int temp = queue[mid];
        queue.erase(queue.begin() + mid);
        return temp;
    }
    
    int popBack() {
        if(queue.empty()) return -1;
        int temp = queue[queue.size()-1];
        queue.pop_back();
        return temp;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
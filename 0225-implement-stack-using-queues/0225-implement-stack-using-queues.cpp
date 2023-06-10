class MyStack {
public:
        queue<int> q, temp;
    
    MyStack() {
    }
    
    void push(int x) {
        return q.push(x);
    }
    
    int pop() {
        //將queue裏面pop到只剩最後一個元素
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        
        //紀錄最後一個元素並刪除
        int result = q.front();
        q.pop();

        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        
        return result;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
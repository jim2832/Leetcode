class MyQueue {
public:
    stack<int> stack1, stack2;

    MyQueue() {
        
    }
    
    void push(int x) {
        //先把 stack1 的東西都先搬到 stack2
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        // 將資料塞入 stack1
        stack1.push(x);
        //把 stack2 的資料移回 stack1
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    int pop() {
        int temp = stack1.top();
        stack1.pop();
        return temp;
    }
    
    int peek() {
        return stack1.top();
    }
    
    bool empty() {
        return stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
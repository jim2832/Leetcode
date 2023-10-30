class CustomStack {
public:
    vector<int> stack;
    int siz;

    CustomStack(int maxSize) {
        siz = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < siz){
            stack.push_back(x);
        }
    }
    
    int pop() {
        if(stack.empty()){
            return -1;
        }
        int top = stack[stack.size()-1];
        stack.pop_back();
        return top;
    }
    
    void increment(int k, int val) {
        if(stack.size() == 0) return;
        k = k < stack.size() ? k : stack.size();
        for(int i=0; i<k; i++){
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
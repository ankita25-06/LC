class MinStack {
    vector<pair<int,int>> stack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
       if(stack.empty()){
        stack.push_back({value,value});
       }else{
        stack.push_back({value,min(value,stack.back().second)});
       }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
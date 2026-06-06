class MinStack {
public:
    stack<int> main;
    stack<int> extra;
    MinStack() {
    }
    
    void push(int val) {
        main.push(val);
        if (!extra.empty()) {
            extra.push(min(val, extra.top()));
        } else {
            extra.push(val);
        }
    }
    
    void pop() {
        main.pop();
        extra.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return extra.top();
    }
};

class MinStack {
private:
    stack<int> s;
    stack<int> minS;

public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (minS.empty() || minS.top() > val) minS.push(val);
        else minS.push(minS.top());
    }
    
    void pop() {
        s.pop();
        minS.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

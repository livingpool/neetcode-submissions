class Solution {
public:
    bool checkStoi(string s) {
        if (s.size() == 1 && !isdigit(s[0])) return false; 
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string t : tokens) {
            if (checkStoi(t)) s.push(stoi(t));
            else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if (t == "+") s.push(a + b);
                else if (t == "-") s.push(b - a);
                else if (t == "*") s.push(a * b);
                else if (t == "/") s.push(b / a);        
            }
        }

        return s.top();
    }
};

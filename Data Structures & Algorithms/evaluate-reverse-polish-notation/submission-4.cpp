class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> main;
        for (string tkn : tokens) {
            if (main.empty()) {
                main.push(tkn);
            } else {
                if (tkn == "+" || tkn == "-" || tkn == "*" || tkn == "/") {
                    int t1 = stoi(main.top());
                    main.pop();
                    int t2 = stoi(main.top());
                    main.pop();
                    if (tkn == "+") main.push(to_string(t1 + t2));
                    else if (tkn == "-") main.push(to_string(t2 - t1));
                    else if (tkn == "*") main.push(to_string(t1 * t2));
                    else if (tkn == "/") main.push(to_string(t2 / t1));
                } else {
                    main.push(tkn);
                }
            }
        }
        return stoi(main.top());
    }
};

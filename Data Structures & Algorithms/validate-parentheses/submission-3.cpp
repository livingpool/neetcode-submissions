class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty()) {
                st.push(c);
                continue;
            }
            char t = st.top();
            if (t == '(' && c == ')') {
                st.pop();
            } else if (t == '{' && c == '}') {
                st.pop();
            } else if (t == '[' && c == ']') {
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty() ? true : false;
    }
};
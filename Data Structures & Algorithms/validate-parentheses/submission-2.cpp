class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> m{
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') stack.push_back(c); 
            else {
                if (stack.size() == 0) return false;
                else if (m[c] != stack.back()) return false;
                else stack.pop_back();
            }
        }

        if (stack.size() != 0) return false;

        return true;
    }
};

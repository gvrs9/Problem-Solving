class Solution {
public:
    bool isValid(string s) {
        if(s.size() & 1) return false;
        stack<char> st;
        for(auto& x : s) {
            if(x == '[' || x == '(' || x == '{') st.push(x);
            else if (x == ']' || x == ')' || x == '}') {
                //always check for !st.empty() otherwise, it will refer to a null pointer when empty and will give sgev error!!
                if(x == ']' && !st.empty() && st.top() == '[') st.pop();
                else if(x == '}' && !st.empty() && st.top() == '{') st.pop();
                else if(x == ')' && !st.empty() && st.top() == '(') st.pop();
                else return false;
            }
            else return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};
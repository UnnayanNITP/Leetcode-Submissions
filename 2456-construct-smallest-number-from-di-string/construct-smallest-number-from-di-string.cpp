class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
    string result = "";
    int num = 1;

    for (int i = 0; i <= pattern.length(); i++) {
        st.push(num++);
        if (i == pattern.length() || pattern[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }

    return result;
    }
};
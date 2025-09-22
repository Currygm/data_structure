#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<char> st;
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if (s[i] == ')') {
                    if (st.empty()) {
                        cout << "No" << endl;
                        return 0;
                    }
                    if (st.top() != '(') {
                        cout << "No" << endl;
                        return 0;
                    }
                    st.pop();
                }
                else if (s[i] == ']') {
                    if (st.empty()) {
                        cout << "No" << endl;
                        return 0;
                    }
                    if (st.top() != '[') {
                        cout << "No" << endl;
                        return 0;
                    }
                    st.pop();
                }
                else if (s[i] == '}') {
                    if (st.empty()) {
                        cout << "No" << endl;
                        return 0;
                    }
                    if (st.top() != '{') {
                        cout << "No" << endl;
                        return 0;
                    }
                    st.pop();
                }
            }
        }
        if (st.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
        while (!st.empty()) {
            st.pop();
        }
    }
}
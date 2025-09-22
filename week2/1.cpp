#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
int main() {
    string s;
    stack<int> st;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                st.push(s[i] - 'a' + 1);
            }
            else {
                double p, q;
                if (s[i] == '+') {
                    p = st.top();
                    st.pop();
                    q = st.top();
                    st.pop();
                    st.push(p + q);
                }
                else if (s[i] == '-') {
                    p = st.top();
                    st.pop();
                    q = st.top();
                    st.pop();
                    st.push(q - p); 
                }
                else if (s[i] == '*') {
                    p = st.top();
                    st.pop();
                    q = st.top();
                    st.pop();
                    st.push(p * q); 
                }
                else {
                    p = st.top();
                    st.pop();
                    q = st.top();
                    st.pop();
                    st.push(q / p);
                }
            }
        }
        cout << fixed << setprecision(2) << st.top() << endl;
        st.pop();
    }
    return 0;
}
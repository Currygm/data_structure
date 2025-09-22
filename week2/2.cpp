#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s, result;
    stack<char> op;
    while (cin >> s) {
        result = "";
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                result += s[i];
            }
            else {
                if (s[i] == ')') {
                    while (op.top() != '(') {
                        result += op.top();
                        op.pop();
                    }
                    op.pop();
                }
                else {
                    if (s[i] == '+' || s[i] == '-') {
                        while (!op.empty() && op.top() != '(') {
                            result += op.top();
                            op.pop();
                        }
                        op.push(s[i]);
                    }
                    else if (s[i] == '*' || s[i] == '/') {
                        while (op.top() == '*' || op.top() == '/') {
                            result += op.top();
                            op.pop();
                        }
                        op.push(s[i]);
                    }
                    else {
                        op.push(s[i]);
                    }
                }
            }
        }
        while (!op.empty()) {
            result += op.top();
            op.pop();
        }
        cout << result << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
class arr {
private:
    int elem[10000];
public:
    int &operator[](int i) { return elem[i]; }
};
class heap {
private:
    int n;
    arr h;
public:
    void clear() { n = 0; }
    int top() { return h[1]; }
    int size() { return n; }
    void push(int x) {
        h[++n] = x;
        int i = n;
        while (i > 1 && h[i/2] > h[i]) {
            int tmp = h[i/2];
            h[i/2] = h[i];
            h[i] = tmp;
            i = i/2;
        }
    }
    void pop() {
        if (n == 0) return;
        h[1] = h[n--];
        int i = 1;
        while (1) {
            int l = i*2;
            int r = i*2 + 1;
            int min = i;
            if (l <= n && h[l] < h[min]) {   // 不能以l < n作为条件，否则当l为左叶子节点时，无法进入判断条件
                min = l;
            }
            if (r <= n && h[r] < h[min]) {   // 同理
                min = r;
            }
            if (min != i) {
                int tmp = h[min];
                h[min] = h[i];
                h[i] = tmp;
                i = min;
            }
            else break;
        }
    }
};


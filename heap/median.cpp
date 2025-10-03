// 中位数问题，尤其是处理数据流，通常用双堆（heap）解决；
// 一个大根堆（堆顶为最大值）和一个小根堆（堆顶为最小值），分别用来存储较大数和较小数；
// 同时维护的过程中保证大根堆的元素数量大于小根堆且差值不大于1，(即s.size >= b.size 且 s.size <= b.size + 1)若不符合则进行调整；
// 最终若大根堆元素多一个则取大根堆堆顶为中位数，否则取两个堆堆顶元素的平均值。
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
long long int N;
priority_queue<long long int> s;   // 优先队列实际上就是用堆实现的。
priority_queue<long long int, vector<long long int>, greater<long long int>> b;  // 小根堆的定义.
int main () {
    cin >> N;
    long long int tmp = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        // 插入元素
        if (s.empty() || tmp <= s.top()) {
            s.push(tmp);
        } else {
            b.push(tmp);
        }

        // 平衡堆
        if (s.size() > b.size() + 1) {   // 区别于s.size() - b.size() > 1，因为STL中该函数的返回类型是无符号类型，当s.size() < b.size()时s.size() - b.size()得到的不是一个负数而是一个非常大的正数
            b.push(s.top());
            s.pop();
        } else if (b.size() > s.size()) {
            s.push(b.top());
            b.pop();
        }

        // 输出中位数（奇数个时）
        if (i % 2 == 0) {
            cout << s.top() << "\n";
        }
    }
    return 0;
}

// #include <iostream>
// #include <queue>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N;
//     cin >> N;

//     priority_queue<long long> s; // 大根堆（左半部分）
//     priority_queue<long long, vector<long long>, greater<long long>> b; // 小根堆（右半部分）

//     for (int i = 0; i < N; i++) {
//         long long x;
//         cin >> x;

//         // 插入元素
//         if (s.empty() || x <= s.top()) s.push(x);
//         else b.push(x);

//         // 平衡两个堆
//         if (s.size() > b.size() + 1) {
//             b.push(s.top());
//             s.pop();
//         } else if (b.size() > s.size()) {
//             s.push(b.top());
//             b.pop();
//         }

//         // 当前是奇数个元素时输出中位数
//         if (i % 2 == 0) {
//             cout << s.top() << "\n";
//         }
//     }

//     return 0;
// }

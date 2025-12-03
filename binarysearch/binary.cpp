#include <iostream>
#include <vector>
using namespace std;
int main () {
    int target = 0, tmp = 0, N = 0;
    vector<int> list;
    cin >> N;
    cin >> target;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        list.push_back(tmp);
    }
    // 判断有无元素
    if (N == 0) {
        return 0;
    }
    int bottom = 0, top = list.size() - 1;
    // 判断是否越界
    if (target < list[bottom] || target > list[top]) {
        return 0;
    }
    while (bottom < top) {
        int mid = (bottom + top) / 2;
        if (target <= list[mid]) {    // 若可取等号则不需要mid +/- 1
            top = mid;
        }
        else {
            bottom = mid + 1;         // 不取等号的需要mid +/- 1
        }
    }
    // 如果 target <= list[mid]，说明答案可能在 mid 或 mid 左边
    // 所以 top = mid，不需要 mid - 1（因为 mid 可能就是答案）

    // 否则（target > list[mid]），mid 不可能是答案
    // 所以 bottom = mid + 1（+1 是因为排除掉 mid）
    if (target != list[top]) {
        return 0;
    }
    cout << top;
    return 0;
}
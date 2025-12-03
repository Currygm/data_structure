#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
// 顺序表实现插入排序
int main() {
    int N, tmp = 0, key = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    for (int i = 1; i < N; i++) {
        key = nums[i];
        int j = i - 1;
        for (; j >= 0 && key <= nums[j]; j--) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = key;
    }
    for (int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}
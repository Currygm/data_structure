#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
// 选择排序：每次都找到未排序元素的最大值（最小值），将其放到已排序元素的末尾。
int main () {
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        int min = i;
        // 找到未排序的元素的最小值，和第一个未排序元素交换位置。注意不要在内部循环内就swap，要找到最值后再换。
        for (int j = i; j < N; j++) {
            if (nums[min] > nums[j]) {
                min = j;
            }
        }
        tmp = nums[min];
        nums[min] = nums[i];
        nums[i] = tmp;
    }
    for (int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}
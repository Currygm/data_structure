#include <iostream>
#include <vector>
using namespace std;
// 希尔排序，通过对序列分组分别进行插入排序，降低时间复杂度
vector<int> nums;
int main () {
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    // 每个分组的元素在原来序列中的间距为gap
    for (int gap = N/2; gap > 0; gap /= 2) {
        // 隐式的处理子序列，并没有直接将子序列写出
        // 若gap为3，i遍历到0，3，6实际上是一个子序列
        for (int i = gap; i < N; i++) {
            tmp = nums[i];
            int j = i;
            while (j - gap >= 0 && nums[j - gap] > tmp) {
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = tmp;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}
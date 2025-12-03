// 归并排序
#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
void merge(int left, int mid, int right) {
    vector<int> tmp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            tmp.push_back(nums[i]);
            i++;
        }
        else {
            tmp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid) {
        tmp.push_back(nums[i++]);
    }
    while (j <= right) {
        tmp.push_back(nums[j++]);
    }
    for (int i = 0; i < (right - left + 1); i++) {
        nums[i + left] = tmp[i];
    }
}
void mergesort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid + 1, right);
        merge(left, mid, right);
    }
}
int main () {
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    mergesort(0, N - 1);
    for (int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}
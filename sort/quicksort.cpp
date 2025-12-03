#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
int partition(int left, int right) {
    int base = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= base) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= base) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = base;
    return left;
}
void quicksort(int left, int right) {
    if (left < right) {
        int pos = partition(left, right);
        quicksort(left, pos - 1);
        quicksort(pos + 1, right);
    }
}
int main () {
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    quicksort(0, N - 1);
    for (int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}
<font face=STKaiti><center>

# 中山大学计算机学院本科生实验报告
### （2025学年第1学期）</center>


课程名称：数据结构与算法实验 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;任课老师：张子臻
|  |  |  |  |
|:-----:|:-------:|:-------:|:--------:|
| 年级: | 2024级   | 专业(方向):   | 计算机科学与技术(人工智能与大数据)
| 学号: | 24325155 | 姓名: | 梁桂铭
| 电话: | 15817681625 | Email: | lianggm8@mail2.sysu.edu.cn
| 开始日期: | 2025年10月11日 | 完成日期: | 2025年10月11日

---

## 第二题

### 1.实验题目

#### 题目描述

把一个包含n个正整数的序列划分成m个连续的子序列（每个正整数恰好属于一个序列）。  
设第i个序列的各数之和为S(i)，如何让所有S(i)的最大值尽量小？  
例如序列`1 2 3 2 5 4`，划分成3个序列的最优方案为`1 2 3 | 2 5 | 4`，其中`S(1)=6, S(2)=7, S(3)=4`，最大值为7；  
如果划分成`1 2 | 3 2 | 5 4`，则最大值为9，不如刚才的好。  
输入：多个样例，每个样例第一行输入n和m，第二行输入n个整数。  
输出：所有划分方案中子序列和的最大值的最小值。

输入样例：
```
6 3
1 2 3 2 5 4
```
输出样例：
```
7
```

---

### 2.实验目的

1. 掌握**二分查找在答案空间中的应用**。
2. 理解**贪心思想**在可行性判断中的使用。
3. 学会解决“**最小化最大值**”类划分问题。

---

### 3.算法设计

#### (1) 思路分析

该题要求在划分后使得每个子序列的和的最大值最小。  
由于序列划分连续且`S(i)`单调变化，可以将问题转化为：

> 在一个给定的最大子段和上限`mid`下，判断能否用不超过`m`个子序列划分所有元素。

我们可用二分搜索答案：

1. 左边界`l`为数组中最大值（每段至少要包含最大元素）；  
2. 右边界`r`为数组总和（只划分成一个序列时）。  
3. 每次取中点`mid`：判断是否可以用不超过`m`段划分完数组；  
   若可以，则说明`mid`可能过大，收缩右边界；否则扩大左边界。  
4. 当`l == r`时即为最优解。

#### (2) 可行性判断函数`check(mid)`
使用贪心策略：从左到右遍历，累积当前段的和`s`，当`s + nums[i] > mid`时开新段。  
若段数超过`m`则说明`mid`太小。

#### (3) 代码实现

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;

bool check(long long mid) {
    int cnt = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + nums[i] <= mid) sum += nums[i];
        else {
            cnt++;
            sum = nums[i];
        }
    }
    return cnt <= m;
}

int main() {
    while (cin >> n >> m) {
        nums.resize(n);
        long long l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            l = max(l, (long long)nums[i]);
            r += nums[i];
        }
        while (l < r) {
            long long mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
```

#### (4) 复杂度分析

- **时间复杂度**：`O(n log(sum))`  
  每次二分执行一次O(n)检查。
- **空间复杂度**：`O(n)`  
  存储输入序列。

---

### 4.程序运行与测试

#### 测试样例

| 输入 | 输出 | 说明 |
|:------:|:------:|:------:|
| `6 3
1 2 3 2 5 4` | `7` | 最优划分(1 2 3 | 2 5 | 4) |
| `5 2
1 2 3 4 5` | `9` | 最优划分(1 2 3 4 | 5) |
| `3 3
2 2 2` | `2` | 每个单独成段 |

#### 运行截图（略）

#### 结果说明

程序能正确输出最小的最大段和，验证了二分与贪心结合的正确性。

---

### 5.实验总结与心得

本实验让我深入理解了**二分答案法**的思想，即在解空间上使用二分查找，通过判断函数`check`来逐步逼近最优值。  
同时，本题也体现了**贪心策略的局部最优**可以保证全局可行性。  
在实际编程中，注意处理边界条件，如：  
- 当某个元素超过`mid`时必须单独成段；  
- 多组输入需循环读取。  

通过本次实验，我掌握了将复杂优化问题转化为**判定 + 二分**的常见解题模式，为后续算法设计奠定基础。

---

## 附录、提交文件清单

### 第二题
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;

bool check(long long mid) {
    int cnt = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + nums[i] <= mid) sum += nums[i];
        else {
            cnt++;
            sum = nums[i];
        }
    }
    return cnt <= m;
}

int main() {
    while (cin >> n >> m) {
        nums.resize(n);
        long long l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            l = max(l, (long long)nums[i]);
            r += nums[i];
        }
        while (l < r) {
            long long mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
```
</font>

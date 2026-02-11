#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// 有序数组中找<=num的最右位置
class FindRight {
public:
    // 为了验证
    static void runTest() {
        int N = 100;
        int V = 1000;
        int testTime = 500000;
        cout << "测试开始" << endl;

        // 初始化随机数种子，保证每次运行随机数不同
        srand((unsigned int)time(nullptr));

        for (int i = 0; i < testTime; i++) {
            int n = rand() % N;
            vector<int> arr = randomArray(n, V);
            sort(arr.begin(), arr.end());
            int num = rand() % V;
            if (right(arr, num) != findRight(arr, num)) {
                cout << "出错了!" << endl;
                return; // 出错后立即退出，方便调试
            }
        }
        cout << "测试结束" << endl;
    }

    // 为了验证：生成随机数组
    static vector<int> randomArray(int n, int v) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % v + 1;
        }
        return arr;
    }

    // 为了验证：暴力解法（从后往前找）
    // 保证arr有序，才能用这个方法
    static int right(const vector<int>& arr, int num) {
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] <= num) {
                return i;
            }
        }
        return -1;
    }

    // 核心算法：有序数组中找<=num的最右位置（二分查找）
    // 保证arr有序，才能用这个方法
    static int findRight(const vector<int>& arr, int num) {
        int l = 0;
        int r = (int)arr.size() - 1; // 转换为int避免size_t的无符号问题
        int m = 0;
        int ans = -1;
        while (l <= r) {
            m = l + ((r - l) >> 1); // 等价于(l + r)/2，避免溢出
            if (arr[m] <= num) {
                ans = m;
                l = m + 1; // 继续往右找更大的符合条件的位置
            }
            else {
                r = m - 1; // 往左找
            }
        }
        return ans;
    }
};

// 程序入口
//int main() {
//    FindRight::runTest();
//    return 0;
//}
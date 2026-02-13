#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class FindNumber {
public:
    // 核心测试方法
    static void runTest() {
        // 设置随机数种子（必须放在函数内执行）
        srand(static_cast<unsigned int>(time(nullptr)));
        const int N = 10;//数组长度
        const int V = 100;//数字的最大范围
        const int testTime = 5;//测试次数

        cout << "测试开始" << endl;
        for (int i = 0; i < testTime; ++i) {
            int n = rand() % N;//生成数组的长度
            vector<int> arr = randomArray(n, V);//生成随机数组
            sort(arr.begin(), arr.end()); // 排序保证二分查找前提
            int num = rand() % V;//生成随机数字

            // 调用静态方法验证结果
            if (right(arr, num) != findleft(arr, num)) {
                cout << "出错了!" << endl;
                cout << "数组为："; printArray(arr);
                cout << "查找数字：" << num << endl;
                cout << "暴力验证" << right(arr, num) << endl;
                cout << "二分搜索" << findleft(arr, num) << endl;

                return;
            }
        }
        cout << "测试结束" << endl;
    }

    // 生成随机数组：长度n，元素范围[1, v]（保持static）
    static vector<int> randomArray(int n, int v) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = (rand() % v) + 1;
        }
        return arr;
    }

    // 二分搜索（改为static，适配静态调用）
    static int findleft(const vector<int>& arr, int num) {
        int l = 0, r = arr.size() - 1, m = 0;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (num <= arr[mid]) {
                ans = mid;
                r = mid - 1;//记录下来，向左移
            }
            else {
                l = mid + 1;//不记录，向右移
            }
        }
        return ans;
    }
    // 暴力查找（改为static，适配静态调用）
    static int right(const vector<int>& arr, int num) {
        // 遍历数组，找到第一个>=num的元素索引
        for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
            if (arr[i] >= num) {
                return i;
            }
        }
        // 所有元素都<num，返回-1
        return -1;
    }
    // 辅助函数：打印数组（保持static）
    static void printArray(const vector<int>& arr) {
        if (arr.empty()) {
            cout << "空数组" << endl;
            return;
        }
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

// 程序入口
/*int main() {
    FindNumber::runTest();
    return 0;
}*/
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
            vector<int> arr = randomArray(n, V);
            sort(arr.begin(), arr.end()); // 排序保证二分查找前提
            int num = rand() % V;

            // 调用静态方法验证结果
            if (FFindNum(arr,num)!=FindNum(arr,num)){
                cout << "出错了!" << endl;
                cout << "查找数字：" << num << endl;
                cout << "有序数组：";
                printArray(arr);
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
    static bool FindNum(const vector<int>& arr, int num) {
        if (arr.empty()) return false; // 空数组直接返回
        int l = 0;
        int r = static_cast<int>(arr.size()) - 1; // 避免size_t类型溢出
        while (l <= r) {
            int mid = l + (r - l) / 2; // 优化：防止l+r溢出
            if (num < arr[mid]) {
                r = mid - 1;//小于向左找
            }
            else if (num > arr[mid]) {
                l = mid + 1;//大于向右找
            }
            else {
                return true;
            }
        }
        return false;
    }
    // 暴力查找（改为static，适配静态调用）
    static bool FFindNum(const vector<int>& arr, int num) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == num) return true;
        }
        return false;
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
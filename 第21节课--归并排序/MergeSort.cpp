#include <iostream>
#include <algorithm>
using namespace std;
//递归版本
const int MAX = 100000;
int arr[MAX];
int help[MAX];
int n;
void merge(int l, int m, int r) {
    int i = l;
    int a = l;
    int b = m + 1;
    while (a <= m && b <= r) {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];//辅助数组谁小拷贝谁，拷贝完成后，拷贝回原数组
    }while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = help[i];
    }
}//时间复杂度O（n）
void MergeSort(int l, int r) {
    if (l == r)return;
    int m = (l + r) / 2;
    MergeSort(l, m);
    MergeSort(m + 1, r);
    merge(l, m, r);//左部分排好序、右部分排好序、利用merge过程让左右整体有序
}//时间复杂度O（nlogn）
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    MergeSort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}
//非递归版
void MergeSort() {
    for (int step = 1; step < n; step <<= 1) {
        int l = 0;//时间复杂度O（logn）
        while (l < n) {
            int m = l + step - 1;
            if (m + 1 >= n) {
                break;//说明右侧已经没有数据，无需再进行排序
            }
            int r = min(l + (step << 1) - 1, n - 1);//防止右边界越界
            merge(l, m, r);//确定边界，用merge排序，时间复杂度O（n）
            l = r + 1;//左边界移动到下一组
        }
    }
}//时间复杂度O（nlogn)，需要辅助数组，所以额外空间复杂度O(n)
// 测试链接 : https://www.luogu.com.cn/problem/P1177
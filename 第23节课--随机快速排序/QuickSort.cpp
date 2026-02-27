//经典随机快排
// 测试链接 : https://www.luogu.com.cn/problem/P1177
#include <cstdio>   // 仅用于scanf/printf
#include <cstdlib>  // 仅用于rand()/srand()
#include <ctime>    // 仅用于time()初始化随机数种子
#include<iostream>
using namespace std;
const int MAX = 100001;
int arr[MAX];
int n; int first, last;
void swap(int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}
//小于等于x的值，去左边，大于x的值去右边，a作为左边的边界
//最后将等于x的值移动到左边最后一个，这个数字的位置就排好了
int partition(int l, int r, int x) {
    int a = l; int xi;
    for (int i = l; i <= r; i++) {
        if (arr[i] <= x) {
            swap(a, i);
            if (arr[a] == x) {
                xi = a;
            }
            a++;
        }
    }
    swap(xi, a - 1);
    return a - 1;
}
//随机一个数字，排完序后，左右部分再重复该过程
void quickSort(int l, int r) {
    if (l >= r) {
        return;
    }
    // 随机这一下，常数时间比较大
    // 但只有这一下随机，才能在概率上把快速排序的时间复杂度收敛到O(n * logn)
    int randIdx = l + rand() % (r - l + 1);
    int x = arr[randIdx];
    int mid = partition(l, r, x);
    quickSort(l, mid - 1);
    quickSort(mid + 1, r);
}
int main() {
    // 初始化随机数种子，等价于Java的随机数初始化
    srand((unsigned)time(NULL));

    // 快速读取输入
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(0, n - 1);

    // 输出结果
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
    return 0;
}
//优化随机快排,荷兰国旗问题
//小于等于x的值，去左边，大于x的值去右边，a作为左边的边界
//first,last全局变量，更新成==x区域的左右边界，作为函数的返回值
void partition(int l, int r, int x) {
    first = l; last = r;
    int i = l;
    while (i <= last) {
        if (arr[i] == x) {
            i++;
        }
        else if (arr[i] < x) {
            swap(i++, first++);
        }
        else if (arr[i] > x) {
            swap(i, last--);
        }
    }
}
//随机一个数字，排完序后，左右部分再重复该过程
void quickSort(int l, int r) {
    if (l >= r) {
        return;
    }
    int randIdx = l + rand() % (r - l + 1);
    int x = arr[randIdx];
    partition(l, r, x);
    // 为了防止底层的递归过程覆盖全局变量
    // 这里用临时变量记录first、last
    int left = first; int right = last;
    quickSort(l, left - 1);
    quickSort(right + 1, r);
}
/*快速排序的时间和空间复杂度分析

核心点：怎么选择数字？

选择的数字是当前范围上的固定位置，比如范围上的最右数字，那么就是普通快速排序
选择的数字是当前范围上的随机位置，那么就是随机快速排序

普通快速排序，时间复杂度O(n^2)，额外空间复杂度O(n)
随机快速排序，时间复杂度O(n * logn)，额外空间复杂度O(logn)压栈的深度
*/
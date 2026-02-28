// 基数排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177
#include <bits/stdc++.h>
using namespace std;

const int BASE = 10;//进制
const int MAXN = 100001;//数组的最大长度

int arr[MAXN];
int help[MAXN];
int cnts[BASE];//以进制为长度的计数数组
int n;//数组的真实长度
// 基数排序核心代码
// arr内要保证没有负数
// m是arr中最大值在BASE进制下有几位
void radixSort(int bits) {
    for (int offset = 1; bits > 0; bits--, offset *= BASE) {
        //要重置计数数组，因为本次统计当前位的数字出现次数，并不会覆盖上一次的统计
        memset(cnts, 0, sizeof(cnts));
        //遍历arr,用cnts统计当前位的数字出现次数
        // 数字提取某一位的技巧
        for (int i = 0; i < n; i++) {
            cnts[(arr[i] / offset) % BASE]++;
        }
        //遍历cnts，计算前缀和
        for (int i = 1; i < BASE; i++) {
            cnts[i] = cnts[i] + cnts[i - 1];
        }
        //逆序遍历，如果当前位相同，不会打乱上一次的排序。如果当前位不同，会根据当前位重新排序，当前位优先级更高。用cnts确定当前位数数字，在辅助数组的位置
        // 前缀数量分区的技巧
        for (int i = n - 1; i >= 0; i--) {
            int location = (--cnts[(arr[i] / offset) % BASE]);//根据当前位数数字确定位置
            help[location] = arr[i];//把数字放到辅助数组
        }
        for (int i = 0; i < n; i++) {
            arr[i] = help[i];
        }
    }

}
//返回数字的位数
int get_bits(int num) {
    int ans = 0;
    while (num > 0) {
        ans++;
        num /= 10;
    }
    return ans;
}

void Sort() {
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        min_val = min(min_val, arr[i]);
    }
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        arr[i] -= min_val;
        max_val = max(max_val, arr[i]);
    }
    radixSort(get_bits(max_val));
    for (int i = 0; i < n; i++) {
        arr[i] += min_val;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Sort();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}//基数排序的核心操作都是 “扫一遍数组”，而且要扫的次数是固定的、很少的，所以整体时间就跟着数组长度 n 走，也就是 O (n)。
//空间复杂度O(n + BASE)，其中 n 是输入数组的长度，BASE 是计数数组的长度。
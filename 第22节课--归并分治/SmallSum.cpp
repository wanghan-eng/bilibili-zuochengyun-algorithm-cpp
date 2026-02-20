/*原理：
1）思考一个问题在大范围上的答案，是否等于，左部分的答案 + 右部分的答案 + 跨越左右产生的答案
2）计算“跨越左右产生的答案”时，如果加上左、右各自有序这个设定，会不会获得计算的便利性
3）如果以上两点都成立，那么该问题很可能被归并分治解决（话不说满，因为总有很毒的出题人）
4）求解答案的过程中只需要加入归并排序的过程即可，因为要让左、右各自有序，来获得计算的便利性
*/
// 测试链接 : https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
//返回跨左右的小和，并将数字排好序。算完小和再排序，排序是为下一次计算小和做准备
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int n;
int arr[MAX];
int help[MAX];
long long merge(int l, int r, int m) {
    long long  ans = 0;
    for (int i = l, j = m + 1, sum = 0; j <= r; j++) {
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
    }
    //排序：谁小拷贝谁，两个数组都拷贝完成后，拷贝回原数组
    int a = l, b = m + 1; int i = l;
    while (a <= m && b <= r) {
        help[i++] = (arr[a] <= arr[b]) ? arr[a++] : arr[b++];
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = help[i];
    }
    return ans;
}
//左部分+右部分++加跨左右
// 时间复杂度O(n * logn)
long long SmallSum(int l, int r) {
    if (l == r) { return 0; }
    int m = (l + r) >> 1;
    return SmallSum(l, m) + SmallSum(m + 1, r) + merge(l, r, m);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << SmallSum(0, n - 1) << endl;
    }
}
// 翻转对数量
// 测试链接 : https://leetcode.cn/problems/reverse-pairs/
class Solution {
public:
    static const int MAXN = 50001;
    int help[MAXN];
    int reversePairs(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        return counts(arr, 0, arr.size() - 1);
    }
private:
    int counts(vector<int>& arr, int l, int r) {
        if (l == r) {
            return 0;
        }
        int m = (l + r) / 2;
        return counts(arr, l, m) + counts(arr, m + 1, r) + merge(arr, l, m, r);
    }

    // 归并过程中统计跨左右的翻转对，并完成归并排序
    int merge(vector<int>& arr, int l, int m, int r) {
        int ans = 0;
        for (int i = l, j = m + 1; i <= m; i++) {//左边逐个检查，右边灵活变动
            while (j <= r && (long long)arr[i] > (long long)arr[j] * 2) {
                j++;
            }
            ans += j - m - 1;
        }
        int i = l;
        int a = l;
        int b = m + 1;
        while (a <= m && b <= r) {
            help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
        }
        while (a <= m) {
            help[i++] = arr[a++];
        }
        while (b <= r) {
            help[i++] = arr[b++];
        }
        for (i = l; i <= r; i++) {
            arr[i] = help[i];
        }

        return ans;
    }
};

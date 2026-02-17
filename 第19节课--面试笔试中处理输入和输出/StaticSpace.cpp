// 每一组测试都给定数据规模
// 任何空间都提前生成好，一律都是静态空间，然后自己去复用，推荐这种方式(优先采用静态复用，但要清空上次用的数据）
// 测试链接 : https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?

#include <iostream>
#include <cstring>   // 用于memset（数组清空）
#include <climits>   // 用于INT_MIN（对应Java的Integer.MIN_VALUE）
#include <algorithm> // 用于max函数
using namespace std;

// 题目给定的行列最大数据量（对应Java的静态常量）
const int MAXN = 201;
const int MAXM = 201;

// 静态全局矩阵空间，全程复用（对应Java的static int[][] mat）
int mat[MAXN][MAXM];

// 静态全局辅助数组，全程复用（对应Java的static int[] arr）
int arr[MAXM];

// 当前测试用例的行列数（全局变量，控制边界，对应Java的static n/m）
int n, m;

// 求子数组的最大累加和（无参数，复用全局arr和m，逻辑与Java完全一致）
int maxSumSubarray() {
    int max_val = INT_MIN;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        cur += arr[i];
        max_val = max(max_val, cur);
        cur = cur < 0 ? 0 : cur;
    }
    return max_val;
}

// 求子矩阵的最大累加和（无参数，复用全局mat/arr/n/m，逻辑与Java完全一致）
int maxSumSubmatrix() {
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        // 清空辅助数组前m个元素（对应Java的Arrays.fill(arr, 0, m, 0)）
        memset(arr, 0, sizeof(int) * m);
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                arr[k] += mat[j][k];
            }
            max_val = max(max_val, maxSumSubarray());
        }
    }
    return max_val;
}

// ACM风格主函数：高效处理输入输出（匹配Java的BufferedReader+PrintWriter）
int main() {
    // 关闭cin/cout与C标准流的同步，解绑cin和cout，极致提升IO效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 循环读取输入直到EOF（对应Java的StreamTokenizer.TT_EOF）
    while (cin >> n >> m) {
        // 读取矩阵数据到静态全局数组mat中
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        // 计算并输出结果（用'\n'替代endl，避免强制刷新缓冲区）
        cout << maxSumSubmatrix() << '\n';
    }

    return 0;
}
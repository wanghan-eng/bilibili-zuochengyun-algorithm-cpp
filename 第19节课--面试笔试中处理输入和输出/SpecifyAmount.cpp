// 每一组测试都给定数据规模
// 需要任何空间都动态生成，在大厂笔试或者比赛中，这种方式并不推荐
// 测试链接 : https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
#include <iostream>
#include <vector>
#include <climits> // 对应MIN_VALUE
#include <cstdio>  // 用于高效输入输出（scanf/printf）
using namespace std;

// 求子数组的最大累加和（与原Java逻辑完全一致）
int maxSumSubarray(vector<int>& arr, int m) {
    int max_val = INT_MIN;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        cur += arr[i];
        max_val = max(max_val, cur);
        cur = cur < 0 ? 0 : cur;
    }
    return max_val;
}

// 求子矩阵的最大累加和（与原Java逻辑完全一致）
int maxSumSubmatrix(vector<vector<int>>& mat, int n, int m) {
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        // 辅助数组，动态初始化大小为m，初始值0
        vector<int> arr(m, 0);
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                arr[k] += mat[j][k];
            }
            max_val = max(max_val, maxSumSubarray(arr, m));
        }
    }
    return max_val;
}

// ACM风格的主函数，高效处理输入输出
int main() {
    ios::sync_with_stdio(false); // 关闭C++流与C流的同步，提升效率
    cin.tie(nullptr);            // 解绑cin和cout，避免cout刷新导致的慢

    int n, m;
    // 循环读取输入，直到EOF（对应Java的StreamTokenizer.TT_EOF）
    while (cin >> n >> m) {
        // 动态生成n行m列的矩阵，初始值0
        vector<vector<int>> mat(n, vector<int>(m));
        // 读取矩阵元素
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        // 计算并输出结果（cout效率已通过ios配置优化）
        cout << maxSumSubmatrix(mat, n, m) << '\n';
    }

    return 0;
}
//如果题目数据量极大，可将 main 函数中的输入输出替换为 scanf/printf：
/*int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) { // 读取n和m，直到EOF
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        printf("%d\n", maxSumSubmatrix(mat, n, m));
    }
    return 0;
}*/
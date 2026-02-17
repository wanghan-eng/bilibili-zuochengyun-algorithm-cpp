// 测试链接 : https://www.nowcoder.com/exam/test/70070648/detail?pid=27976983
// 其中，7.A+B(7)，就是一个没有给定数据规模，只能按行读数据的例子
// 此时需要自己切分出数据来计算
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
#include <iostream>
#include <string>
#include <sstream>  // 用于字符串流分割（对应Java的split）
#include <vector>
using namespace std;

// 全局变量对应Java的static变量，保持逻辑结构一致
string line;
vector<string> parts;
int sum;

// 辅助函数：按空格分割字符串（模拟Java的String.split(" ")）
vector<string> split(const string& s) {
    vector<string> res;
    stringstream ss(s);
    string token;
    // 按空格读取每个子串（自动忽略多个连续空格）
    while (ss >> token) {
        res.push_back(token);
    }
    return res;
}

int main() {
    // 关闭同步+解绑cin/cout，提升IO效率（匹配Java的BufferedReader）
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 逐行读取输入，直到EOF（对应Java的in.readLine() != null）
    while (getline(cin, line)) {
        // 分割字符串为数字字符串数组
        parts = split(line);
        sum = 0;
        // 遍历分割后的部分，累加求和
        for (string& num : parts) {
            // 字符串转整数（对应Java的Integer.valueOf）
            sum += stoi(num);
        }
        // 输出结果（用'\n'替代endl，避免刷新缓冲区）
        cout << sum << '\n';
    }

    return 0;
}
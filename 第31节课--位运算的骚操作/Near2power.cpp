#include <iostream>
using namespace std;
// 已知n是非负数
// 返回大于等于n的最小的2某次方
// 如果int范围内不存在这样的数，返回整数最小值
class Code03_Near2power {
public:
    static const int near2power(int n) {
        // 处理非正数的情况，返回1（2^0）
        if (n <= 0) {
            return 1;
        }
        // 核心位运算逻辑：减1之后，从最左面的1开始，后面全部刷成1、
        //两种情况：是2的幂，或者不是2的幂
        int temp = n - 1;
        temp |= temp >> 1;
        temp |= temp >> 2;
        temp |= temp >> 4;
        temp |= temp >> 8;
        temp |= temp >> 16;
        return temp + 1;
    }
};

// 测试主函数，保持与Java相同的输入输出行为
int main() {
    int number = 100;
    cout << Code03_Near2power::near2power(number) << endl; // 输出128
    return 0;
}
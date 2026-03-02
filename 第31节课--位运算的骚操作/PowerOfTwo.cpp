class Solution {
public:
    // Brian Kernighan算法
    // 提取出二进制里最右侧的1
    // 判断一个整数是不是2的幂（数字在二进制某位只有一个1）
    // 测试链接 : https://leetcode.cn/problems/power-of-two/
    bool isPowerOfTwo(int n) {
        //不用转成无符号整数，不会溢出。但凡有可能溢出就要转成无符号整数
        return n > 0 && n == (n & -n);
    }
};
class Solution {
public:// 给你两个整数 left 和 right ，表示区间 [left, right]
    // 返回此区间内所有数字 & 的结果
    // 包含 left 、right 端点
    int rangeBitwiseAnd(int left, int right) {
        //存在小于right的数字，right-1,二进制最右侧的1变成0，而且这个数字一定存在，与之后这个位置就变成0了
        //最终目的是找到能保留下来的前面的01010001
        while (left < right) {
            right -= right & -right;
        }
        return right;
    }
};
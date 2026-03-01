// 数组中只有1种数出现次数少于m次，其他数都出现了m次
// 返回出现次数小于m次的那种数
// 测试链接 : https://leetcode.cn/problems/single-number-ii/
// 注意 : 测试题目只是通用方法的一个特例，课上讲了更通用的情况
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return find(nums, 3);
    }

    // 更通用的方法
    // 已知数组中只有1种数出现次数少于m次，其他数都出现了m次
    // 返回出现次数小于m次的那个数
    int find(vector<int>& arr, int m) {
        int cnts[32] = { 0 };
        for (int num : arr) {
            for (int i = 0; i < 32; i++) {
                cnts[i] += (num >> i) & 1;//提取数字某一位二进制值。向右移动几位，与一个1.
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (cnts[i] % m != 0) {//不等于0，就是那个数字留下的痕迹
                ans |= (1 << i);//把数字某一位二进制变成1。1向左移动几位，给或进去
            }
        }
        return ans;
    }
};
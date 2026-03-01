// 找到缺失的数字
// 测试链接 : https://leetcode.cn/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int eorall = 0; int eorHas = 0;
        for (int i = 0; i < nums.size(); i++) {
            eorall ^= i;
            eorHas ^= nums[i];
        }
        eorall ^= nums.size();
        return eorall ^ eorHas;
        //整体异或和如果是x，整体中某个部分的异或和如果是y，那么剩下部分的异或和是x^y
    }
};

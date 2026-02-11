/*二分搜索不一定发生在有序数组上

峰值元素是指其值严格大于左右相邻值的元素
给你一个整数数组 nums，已知任何两个相邻的值都不相等
找到峰值元素并返回其索引
数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
你可以假设 nums[-1] = nums[n] = 无穷小
你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
测试链接 : https://leetcode.cn/problems/find-peak-element/
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n == 0) { return 0; }//如果长度为一，返回0
        if (nums[0] > nums[1]) {
            return 0;
        }//检查第一个元素
        if (nums[n] > nums[n - 1]) {
            return n;
        }//检查最后一个元素
        int l = 1;
        int r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m - 1]) {
                r = m - 1;//峰值在左，向左找
            }
            else if (nums[m] < nums[m + 1]) {
                l = m + 1;//峰值在右，向右找
            }
            else {
                return m;//峰值
            }
        }
        return -1;
    }
};
// 无序数组中第K大的元素
// 测试链接 : https://leetcode.cn/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int first, last;
    void swap(vector<int>& arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    //荷兰国旗问题
    void partition(vector<int>& arr, int l, int r, int x) {
        first = l;
        last = r;
        int i = l;
        while (i <= last) {
            if (arr[i] < x) {
                swap(arr, first++, i++);
            }
            else if (arr[i] == x) {
                i++;
            }
            else {
                swap(arr, i, last--);
            }
        }
    }
    // 随机选择算法，时间复杂度O(n)
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        int pos = nums.size() - k;
        for (int l = 0, r = nums.size() - 1; l <= r;) {
            int randIdx = l + rand() % (r - l + 1);
            int x = nums[randIdx];
            /*因为first,last只使用一次，使用完以后就没有用了，可以调用partition覆盖*/
            partition(nums, l, r, x);
            if (pos < first) {
                r = first - 1;
            }
            else if (pos > last) {
                l = last + 1;
            }
            else {
                ans = nums[pos];
                break;
            }
        }
        return ans;
    }

};
// 将数组和减半的最少操作次数
// 测试链接 : https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/class
//STL的大根堆
//时间复杂度O(n*logn)总体来看，n个元素进出堆一次
//空间复杂度O（N）
Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;
        //将数组装到大根堆
        for (int num : nums) {
            pq.push(static_cast<double>(num));
            sum += static_cast<double>(num);
        }
        int ans = 0;
        double minus = 0;
        //简单的贪心算法
        while (minus < (sum / 2)) {
            double cur = pq.top();
            pq.pop();
            cur /= 2;
            pq.push(cur);
            minus += cur;
            ans++;
        }
        return ans;

    }
};
//手动实现大根堆
class Solution {
private:
    const int MAXN = 100001;
    long long heap[100001]; // 手动大根堆，用long long避免溢出
    int size;               // 堆的大小

    // 交换堆中两个元素
    void swap(int i, int j) {
        long long tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }

    // 堆化函数（向下调整，维护大根堆）
    void heapify(int i) {
        int l = i * 2 + 1;
        while (l < size) {
            int best = (l + 1 < size && heap[l + 1] > heap[l]) ? l + 1 : l;
            best = (heap[best] > heap[i]) ? best : i;
            if (best == i) {
                break;
            }
            swap(best, i);
            i = best;
            l = i * 2 + 1;
        }
    }

public:
    int halveArray(vector<int>& nums) {
        size = nums.size();
        long long sum = 0;

        // 初始化堆：数值左移20位（等价于*2^20），避免浮点数
        //从后往前建堆，时间复杂度O（n）
        for (int i = size - 1; i >= 0; i--) {
            heap[i] = static_cast<long long>(nums[i]) << 20;
            sum += heap[i];
            heapify(i);
        }

        long long target = sum / 2; // 需要减少的目标总和
        int ans = 0;
        long long minus = 0;        // 累计减少的数值

        // 每次取最大值减半，直到累计减少量达到target
        while (minus < target) {
            heap[0] /= 2;
            minus += heap[0];
            heapify(0);
            ans++;
        }

        return ans;
    }
};
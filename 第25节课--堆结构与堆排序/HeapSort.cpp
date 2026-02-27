/*堆结构
完全二叉树和数组前缀范围来对应，大小，单独的变量size来控制
i的父亲节点：(i-1)/2，i的左孩子：i*2 + 1，i的右孩子：i*2 + 2
堆的定义（大根堆、小根堆），本节课讲解按照大根堆来讲解，小根堆是同理的。
堆的调整：heapInsert（向上调整）、heapify（向下调整）
heapInsert、heapify方法的单次调用，时间复杂度O(log n)，完全二叉树的结构决定的

堆排序
   A. 从顶到底建堆，时间复杂度O(n * log n)，log1 + log2 + log3 + … + logn -> O(n*logn)
      或者用增倍分析法：建堆的复杂度分析+子矩阵数量的复杂度分析
   B. 从底到顶建堆，时间复杂度O(n)，总代价就是简单的等比数列关系，为啥会有差异？简单图解一下
   C. 建好堆之后的调整阶段，从最大值到最小值依次归位，时间复杂度O(n * log n).就是建堆的逆过程
时间复杂度O(n * log n)，不管以什么方式建堆，调整阶段的时间复杂度都是这个，所以整体复杂度也是这个
额外空间复杂度是O(1)，因为堆直接建立在了要排序的数组上，所以没有什么额外空间

*/
class Solution {
private:
    vector<int> arr;
public:
    void swap(int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    //i位置的数字，向上调整大根堆
    void heapInsert(int i) {
        while (arr[i] > arr[(i - 1) / 2]) {
            swap(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }
    //i位置的数字，向下调整大根堆
    //当前数组的长度为size;
    void heapify(int i, int size) {
        int l = i * 2 + 1;
        while (l < size) {
            int best = (l + 1) < size && arr[l + 1] > arr[l] ? l + 1 : l;
            best = (arr[best] > arr[i]) ? best : i;
            //如果条件成立，说明数字已经到达最下面
            if (best == i) {
                break;
            }
            swap(i, best);
            i = best;
            l = i * 2 + 1;
        }
    }
    // 从顶到底建立大根堆，O(n * logn)
    // 依次弹出堆内最大值并排好序，O(n * logn)
    // 整体时间复杂度O(n * logn)
    void heapSort1() {
        for (int i = 0; i < arr.size(); i++) {
            heapInsert(i);
        }
        int size = arr.size();
        while (size > 1) {
            swap(0, --size);
            heapify(0, size);
        }
    }
    // 从底到顶建立大根堆，O(n)
    // 依次弹出堆内最大值并排好序，O(n * logn)
    // 整体时间复杂度O(n * logn)
    void heapSort2() {
        for (int i = arr.size(); i >= 0; i--) {
            heapify(i, arr.size());
        }
        int size = arr.size();
        while (size > 1) {
            swap(0, --size);
            heapify(0, size);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        arr = nums;
        heapSort2();
        return arr;
    }
};
class Bitset {
    // 测试链接 : https://leetcode-cn.com/problems/design-bitset/
    // 位图的实现
// Bitset是一种能以紧凑形式存储位的数据结构
// Bitset(int n) : 初始化n个位，所有位都是0
// void fix(int i) : 将下标i的位上的值更新为1
// void unfix(int i) : 将下标i的位上的值更新为0
// void flip() : 翻转所有位的值
// boolean all() : 是否所有位都是1
// boolean one() : 是否至少有一位是1
// int count() : 返回所有位中1的数量
// String toString() : 返回所有位的状态
private:
    vector<int> set;
    const int size;   // 总位数
    int zeros;        // 0的数量
    int ones;         // 1的数量
    bool reverse;     // 是否翻转状态

public:
    // 构造函数：初始化n个位，所有位都是0
    Bitset(int n) : size(n), zeros(n), ones(0), reverse(false) {
        // 计算需要的int数量：(n + 31) / 32，向上取整
        set.resize((n + 31) / 32, 0);
    }

    // 把i这个位置的位更新为1
    void fix(int i) {
        int index = i / 32;
        int bit = i % 32;
        if (!reverse) {
            // 位图所有位的状态，维持原始含义
            // 0 : 不存在
            // 1 : 存在
            //判断某位的数字：num>>到最后，然后与1。或者1<<到某位，然后与num.  
            if ((set[index] & (1 << bit)) == 0) {
                zeros--;
                ones++;
                set[index] |= (1 << bit);
            }
        }
        else {
            // 位图所有位的状态，翻转了
            // 0 : 存在
            // 1 : 不存在
            if ((set[index] & (1 << bit)) != 0) {
                zeros--;
                ones++;
                set[index] ^= (1 << bit);
            }
        }
    }

    // 把i这个位置的位更新为0
    void unfix(int i) {
        int index = i / 32;
        int bit = i % 32;
        if (!reverse) {
            if ((set[index] & (1 << bit)) != 0) {
                ones--;
                zeros++;
                set[index] &= ~(1 << bit);
            }
        }
        else {
            if ((set[index] & (1 << bit)) == 0) {
                ones--;
                zeros++;
                set[index] |= (1 << bit);
            }
        }
    }

    // 翻转所有位的值
    void flip() {
        reverse = !reverse;
        // 交换0和1的计数
        int tmp = zeros;
        zeros = ones;
        ones = tmp;
    }

    // 是否所有位都是1
    bool all() {
        return ones == size;
    }

    // 是否至少有一位是1
    bool one() {
        return ones > 0;
    }

    // 返回所有位中1的数量
    int count() {
        return ones;
    }

    // 返回所有位的状态字符串
    string toString() {
        string s1;
        for (int i = 0, k = 0, number, status; i < size; k++) {
            number = set[k];
            for (int j = 0; j < 32 && i < size; j++, i++) {
                status = (number >> j) & 1;
                status ^= reverse ? 1 : 0;
                s1 += (char)('0' + status);
            }
        }
        return s1;
    }
};

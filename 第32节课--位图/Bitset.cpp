#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

// 位图的实现
class Bitset {
public:
    int* set; // 存储位图的整型数组
    int capacity; // 记录数组容量，用于内存释放
    // n个数字 : 0~n-1
    Bitset(int n) {
        // 前提是a和b都是非负数
        // a/b如果结果想向上取整，可以写成 : (a+b-1)/b
		//a=k*b+小余数。在加上b-1后，只要有小余数，就会进位到下一个整数倍的k*b上去。
        capacity = (n + 31) / 32;
        set = new int[capacity](); // 初始化数组所有元素为0
    }

    // 析构函数，释放动态分配的内存
    ~Bitset() {
        delete[] set;
        set = nullptr;
    }
    //把某位设置为1，1移动到某位，把1或进去
    void add(int num) {
        set[num / 32] = set[num / 32] | (1 << (num % 32));
    }
	//把某位设置为0，1移动到某位，把1取反后,把0与进去。如果确定为1，也可以用异或
    void remove(int num) {
        set[num / 32] = set[num / 32] & (~(1 << (num % 32)));
    }
	//把某位取反，1移动到某位，把1异或进去。
    void reverse(int num) {
        set[num / 32] = set[num % 32] ^ (1 << (num % 32));
    }
	//提取某一位的数字，把数字移动到最后一位，与1进行与运算，如果结果为1，说明该位是1，否则为0
    bool contains(int num) {
        return ((set[num / 32] >> (num % 32)) & 1) == 1;
    }

};
/*位运算
或0不改变，与1不改变
或1改变，与0不改变*/
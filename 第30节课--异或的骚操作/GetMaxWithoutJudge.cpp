// 不用任何判断语句和比较操作，返回两个数的最大值
// 测试链接 : https://www.nowcoder.com/practice/d2707eaf98124f1e8f1d9c18ad487f76
//c有溢出的问题
#include <sys/types.h>
class Solution {
private:
    // 必须保证n一定是0或者1
    // 0变1，1变0
    int flip(int n) {
        return n ^ 1;
    }
    // 非负数返回1
    // 负数返回0
    // Java的无符号右移>>>在C++中需要先转为unsigned再右移
    int sign(int n) {
        return flip(static_cast<unsigned>(n) >> 31);
    }
public:
    int getMax(int a, int b) {
        int c = a - b;
        //这两个互斥，要不返回A,要不返回B;
        int returnA = sign(c);
        int returnB = flip(returnA);
        return a * returnA + b * returnB;
    }
};
// 没有任何问题的实现
#include <sys/types.h>
class Solution {
private:
    // 必须保证n一定是0或者1
    // 0变1，1变0
    int flip(int n) {
        return n ^ 1;
    }
    // 非负数返回1
    // 负数返回0
    // Java的无符号右移>>>在C++中需要先转为unsigned再右移
    int sign(int n) {
        return flip(static_cast<unsigned>(n) >> 31);
    }
public:
    int getMax(int a, int b) {
        int c = a - b;// c可能是溢出的
        int sa = sign(a);
        int sb = sign(b);
        int sc = sign(c);
        int diffAB = sa ^ sb;// 判断A和B，符号是不是不一样，如果不一样diffAB=1，如果一样diffAB=0
        int sameAB = flip(diffAB);// 判断A和B，符号是不是一样，如果一样sameAB=1，如果不一样sameAB==0
        //返回A的条件：a,b一样且c是正的。a,b不一样a是正的。
        //a,b不一样，c可能溢出。用a的符号来判断，避免使用c
        int returnA = diffAB * sa + sameAB * sc;
        int returnB = flip(returnA);
        return returnA * a + returnB * b;
    }
};
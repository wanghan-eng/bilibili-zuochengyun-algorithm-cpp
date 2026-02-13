#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// 对应原Java代码的QueueStackAndCircularQueue类
class QueueStackAndCircularQueue {
public:
    // 直接使用C++标准库的queue实现（对应原Queue1）
    class Queue1 {
    private:
        // C++标准库的queue，底层默认是deque（双端队列），类似Java的LinkedList
        queue<int> q;

    public:
        // 判断队列是否为空
        bool isEmpty() {
            return q.empty();
        }

        // 向队列尾部添加元素
        void offer(int num) {
            q.push(num); // C++中push对应Java的offer
        }

        // 从队列头部弹出元素
        int poll() {
            int frontVal = q.front(); // 先获取头部值
            q.pop(); // C++的pop只删除元素，不返回值
            return frontVal;
        }

        // 获取队列头部元素（不弹出）
        int peek() {
            return q.front();
        }

        // 返回队列大小
        int size() {
            return q.size();
        }
    };

    // 基于数组的队列实现
    class Queue2 {
    private:
        vector<int> queue; // 用vector替代Java的数组，更安全
        int l; // 队头指针
        int r; // 队尾指针

    public:
        // 构造函数：初始化队列容量
        Queue2(int n) : l(0), r(0) {
            queue.resize(n); // 预分配数组大小
        }

        // 判断队列是否为空
        bool isEmpty() {
            return l == r;
        }

        // 向队列尾部添加元素
        void offer(int num) {
            queue[r++] = num;
        }

        // 从队列头部弹出元素
        int poll() {
            return queue[l++];
        }

        // 获取队头元素（不弹出）
        int head() {
            return queue[l];
        }

        // 获取队尾元素
        int tail() {
            return queue[r - 1];
        }

        // 返回队列大小
        int size() {
            return r - l;
        }
    };

    // 直接使用C++标准库的stack实现（对应原Stack1）
    class Stack1 {
    private:
        stack<int> st;

    public:
        // 判断栈是否为空
        bool isEmpty() {
            return st.empty();
        }

        // 入栈
        void push(int num) {
            st.push(num);
        }

        // 出栈
        int pop() {
            int topVal = st.top(); // 先获取栈顶值
            st.pop(); // C++的pop只删除元素，不返回值
            return topVal;
        }

        // 获取栈顶元素（不弹出）
        int peek() {
            return st.top();
        }

        // 返回栈大小
        int size() {
            return st.size();
        }
    };

    // 基于数组的栈实现（对应原Stack2），常数时间更优
    class Stack2 {
    private:
        vector<int> stack; // 用vector替代数组
        int size; // 栈当前元素个数（栈顶指针）

    public:
        // 构造函数：初始化栈容量
        Stack2(int n) : size(0) {
            stack.resize(n); // 预分配大小
        }

        // 判断栈是否为空
        bool isEmpty() {
            return size == 0;
        }

        // 入栈
        void push(int num) {
            stack[size++] = num;
        }

        // 出栈
        int pop() {
            return stack[--size];
        }

        // 获取栈顶元素（不弹出）
        int peek() {
            return stack[size - 1];
        }

        // 返回栈大小
        int size() {
            return size;
        }
    };
    //循环队列
    class MyCircularQueue {
    private:
        // 成员变量声明在类的私有区域
        vector<int> queue;
        int l, r, size, limit;
    public:
        MyCircularQueue(int k) {
            queue.resize(k);
            l = 0;
            r = 0;
            size = 0;//循环队列的关键时用一个计数器来看满没满
            limit = k;
        }

        bool enQueue(int value) {
            if (isFull())return false;
            queue[r] = value;
            r = (r == limit - 1 ? 0 : r + 1);//到达最后就弹回0
            size++;
            return true;
        }

        bool deQueue() {
            if (isEmpty())return false;
            l = (l == limit - 1 ? 0 : l + 1);//到达最后弹回0
            size--;
            return true;

        }

        int Front() {
            if (isEmpty())return -1;
            return queue[l];
        }

        int Rear() {
            if (isEmpty())return -1;
            int last = (r == 0 ? limit - 1 : r - 1);//寻找r的上一个
            return queue[last];
        }

        bool isEmpty() {
            return size == 0;
        }

        bool isFull() {
            return size == limit;
        }
    };


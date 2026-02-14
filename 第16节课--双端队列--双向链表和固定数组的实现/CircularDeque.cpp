//使用STL
class MyCircularDeque {
private:
    deque<int> de;
    int size, limit;
public:
    MyCircularDeque(int k) {
        size = 0; limit = k;
    }

    bool insertFront(int value) {
        if (isFull())return false;
        de.push_front(value);
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())return false;
        de.push_back(value);
        size++;
        return true;
    }

    bool deleteFront() {
        if (de.empty())return false;
        de.pop_front();
        size--;
        return true;
    }

    bool deleteLast() {
        if (de.empty())return false;
        de.pop_back();
        size--;
        return true;
    }

    int getFront() {
        if (de.empty())return -1;
        else return de.front();
    }

    int getRear() {
        if (de.empty()) {
            return -1;
        }
        else {
            return de.back();
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }
};
//固定数组实现双端队列
class MyCircularDeque {
private:
    vector<int> queue;
    int left, right, size, limit;
public:
    MyCircularDeque(int k) {
        queue.resize(k);//初始化数组大小为k
        limit = k;
        left = right = size = 0;//一定要初始化
    }
    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }
    bool insertFront(int value) {
        if (isFull()) { return false; }
        if (isEmpty()) {
            queue[size] = value;
            left = right = 0;
        }
        else {
            left = left == 0 ? limit - 1 : left - 1;
            queue[left] = value;//先跳再入值
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())return false;
        if (isEmpty()) {
            queue[size] = value;
            left = right = 0;//如果是空的，都是插入到第一个
        }
        else {
            right = right == limit - 1 ? 0 : right + 1;
            queue[right] = value;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())return false;
        left = left == limit - 1 ? 0 : left + 1;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())return false;
        right = right == 0 ? limit - 1 : right - 1;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty())return -1;
        else {
            return queue[left];
        }
    }

    int getRear() {
        if (isEmpty())return -1;
        else {
            return queue[right];
        }
    }


};// 设计循环双端队列
// 测试链接 : https://leetcode.cn/problems/design-circular-deque/
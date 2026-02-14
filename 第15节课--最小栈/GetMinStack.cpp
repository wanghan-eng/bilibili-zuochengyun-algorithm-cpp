//标准库
class MinStack {
private:
    stack<int> st;
    stack<int> min;
public:
    MinStack() {

    }

    void push(int val) {
        st.push(val);
		if (min.empty() || val <= min.top()) {//压入min的是较小值
            min.push(val);
        }
        else {
            min.push(min.top());
        }
    }

    void pop() {
        st.pop();
        min.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//自己实现
class MinStack {
private:
    static const int MAX = 100000;
    int st[MAX];
    int min[MAX];
    int size;
public:
    MinStack() {
        size = 0;
    }

    void push(int val) {
        st[size] = val;
        if (size == 0 || val <= min[size - 1]) {
            min[size] = val;
        }
        else {
            min[size] = min[size - 1];
        }
        size++;
    }

    void pop() {
        size--;
    }

    int top() {
        return st[size - 1];
    }

    int getMin() {
        return min[size - 1];
    }
};

// 测试链接 : https://leetcode.cn/problems/min-stack/
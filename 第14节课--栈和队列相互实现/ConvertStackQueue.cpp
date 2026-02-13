#include<vector>
#include<stack>
#include<queue>
using namespace std;
class MyQueue {
private:
    stack<int> in;
    stack<int> out;
    void InToOut() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
    //1.out为空才能倒入
    //2.要倒入，in就要全部倒入
public:
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        InToOut();
        int val = out.top();
        out.pop();
        return val;
    }

    int peek() {
        InToOut();
        return out.top();
    }

    bool empty() {
        if (in.empty() && out.empty())return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyStack {
public:
    queue<int> q;
    MyStack() {

    }

    void push(int x) {
        int num = q.size();
        q.push(x);
        for (int i = 0; i < num; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
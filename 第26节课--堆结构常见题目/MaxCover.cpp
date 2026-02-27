// 最多线段重合问题
// 测试链接 : https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
pair<int, int> line[MAX];//pair类型的结构体
int n;
//仿函数std::sort 要求比较规则满足 “严格弱序”它的核心逻辑是：
//当仿函数返回 true 时，表示 第一个参数 a 应该排在第二个参数 b 的前面；
//记忆：默认为真，第一个优先。降序就第一个小于第二个
struct CompareLine {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};
int compute() {
    // line [0...n) 排序 : 所有小数组，开始位置谁小谁在前
    sort(line, line + n, CompareLine());
    //用小根堆
    priority_queue<int, vector<int>, greater<int> >heap;
    int ans = 0;
    //时间复杂度O（n*logn)总体来看，n个line[i].sencond进出堆一次
    //进入堆，O（logn)
    //空间复杂度O(n)
    for (int i = 0; i < n; i++) {
        while (!heap.empty() && heap.top() <= line[i].first) {
            heap.pop();
        }
        heap.push(line[i].second);
        ans = max(ans, (int)heap.size());
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> line[i].first >> line[i].second;
    }
    cout << compute() << '\n';
}

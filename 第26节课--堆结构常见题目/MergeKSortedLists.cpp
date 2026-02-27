struct CompareNode {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;//返回为真，后面的更优先，以后面的为主体
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    // write code here
// 定义小根堆：优先队列 + 自定义比较规则
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> heap;

    // 遍历所有链表的头节点，非空则加入堆
    for (ListNode* h : lists) {
        if (h != nullptr) {
            heap.push(h);
        }
    }

    // 如果堆为空，说明没有有效链表，返回null
    if (heap.empty()) {
        return nullptr;
    }

    // 弹出堆顶（最小值节点）作为结果链表的头
    ListNode* h = heap.top();
    heap.pop();
    ListNode* pre = h;

    // 如果当前节点有下一个节点，加入堆
    if (pre->next != nullptr) {
        heap.push(pre->next);
    }

    // 循环处理堆中的节点，构建合并后的链表
    while (!heap.empty()) {
        ListNode* cur = heap.top();
        heap.pop();
        pre->next = cur;
        pre = cur;
        // 当前节点的下一个节点非空则加入堆
        if (cur->next != nullptr) {
            heap.push(cur->next);
        }
    }

    return h;
}
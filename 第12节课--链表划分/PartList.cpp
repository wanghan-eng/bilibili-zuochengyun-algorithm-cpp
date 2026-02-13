// 给你一个链表的头节点 head 和一个特定值 x
// 请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置
// 测试链接 : https://leetcode.cn/problems/partition-list/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* LH = nullptr, * LT = nullptr;
        ListNode* RH = nullptr, * RT = nullptr;
        ListNode* next = nullptr;
        while (head != nullptr) {
            next = head->next;//保存下一个结点
            head->next = nullptr;//断开连接
            if (head->val < x) {
                if (LH == nullptr) {
                    LH = head;
                    LT = LH;
                }
                else {
                    LT->next = head;
                    LT = LT->next;
                }
            }
            else {
                if (RH == nullptr) {
                    RH = head;
                    RT = RH;
                }
                else {
                    RT->next = head;
                    RT = RT->next;
                }
            }
            head = next;
        }
        if (LH == nullptr) {//如果左面没有元素，返回右节点
            return RH;
        }
        LT->next = RH;
        return LH;

    }
};
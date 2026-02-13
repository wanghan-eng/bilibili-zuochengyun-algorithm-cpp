/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* LH = nullptr, * LT = nullptr;
        ListNode* RH = nullptr, * RT = nullptr;
        ListNode* next = nullptr;
        while (head != nullptr) {
            next = head->next;    // 保存下一个结点
            head->next = nullptr; // 断开连接,必须要断连，否则会有成环的风险
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
        if (LH == nullptr) { // 如果左面没有元素，返回右节点
            return RH;
        }
        LT->next = RH;
        return LH;
    }
};
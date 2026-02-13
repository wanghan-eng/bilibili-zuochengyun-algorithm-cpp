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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = nullptr, *cur = nullptr;//j建立一个新链表
        int carry = 0;//进位在循环后，还要使用，定义在外面
        for (int num, val;//定义
            l1 != nullptr || l2 != nullptr;//l1和l2都为空时才跳出循环
            l1 = (l1 == nullptr ? nullptr : l1 = l1->next), l2 = (l2 == nullptr ? nullptr : l2->next)) {//链表不为空，往下找，链表为空，停下来，指针置空
            num = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;//链表不为空，取值，链表为空，取0，不能访问val，
            val = num % 10;//进去的值
            carry = num / 10;//进位
            if (ans == nullptr) {//从头建立新结点
                ans = new ListNode(val);
                cur = ans;
            }
            else {//连接新结点
                cur->next = new ListNode(val);
                cur = cur->next;
            }
        }
        if (carry == 1) {//进位为1，最后再建立一个新结点
            cur->next = new ListNode(1);
        }
        return ans;
    }
};
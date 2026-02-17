#include<stack>
#include<vector>
using namespace std;
// 用一个栈完成先序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-preorder-traversal/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root != nullptr) {
            stack<TreeNode*> stack;
            stack.push(root);
            while (!stack.empty()) {
                root = stack.top();//root移动到栈顶元素的地址
                stack.pop();//弹出栈顶元素
                ans.push_back(root->val);//将元素存入ans
                if (root->right != nullptr) {//压入root的孩子，先压入右，再压入左
                    stack.push(root->right);
                }
                if (root->left != nullptr) {
                    stack.push(root->left);
                }
            }
        }
        return ans;
    }
};
// 用一个栈完成中序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-inorder-traversal/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* head) {
        vector<int> ans;
        stack<TreeNode*> stack;
        while (head != nullptr || !stack.empty()) {//栈为空说明左树处理完了，头节点为空说明到达了尾部
            if (head != nullptr) {
                stack.push(head);
                head = head->left;
            }
            else {
                head = stack.top();//回去的路用栈铺好了，第二次遇到这个，弹出栈
                stack.pop();
                ans.push_back(head->val);
                head = head->right;//右孩子不为空，变成下一个左孩子。为空，左右树都遍历完了
            }
        }
        return ans;
    }
};
// 用两个栈完成后序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-postorder-traversal/
class Solution {
public://用h记录上一次弹出的位置
    vector<int> postorderTraversal(TreeNode* head) {
        vector<int> ans;
        if (head != nullptr) {
            stack<TreeNode*> st;
            st.push(head);
            while (!st.empty()) {
                TreeNode* cur = st.top();//移动当前位置
                if (cur->left != nullptr && head != cur->left && head != cur->right) {
                    st.push(cur->left);
                }//左树未处理完，先处理左树。h移动到右孩子，防止c走回去。
                else if (cur->right != nullptr && head != cur->right) {
                    st.push(cur->right);
                }//右树未处理完，先处理右树。
                else {//左右树都处理完，h记录当前弹出的位置
                    head = st.top();
                    ans.push_back(head->val);
                    st.pop();
                }
            }
        }
        return ans;
    }
};//时间复杂度o(n),空间复杂度o（h）h为树的高度
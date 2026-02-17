#include<iostream>
using namespace std;
// 用递归实现二叉树的三序遍历
class BinaryTreeTraversalRecursion {
public:
	//定义二叉树节点
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) :val(x), left(NULL), right(NULL) {}
	};
    // 递归基本样子，用来理解递归序
    static void f(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        // 1
        f(head->left);
        // 2
        f(head->right);
        // 3
    }
    // 先序打印所有节点，递归版
    static void preOrder(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        cout << head->val << " ";
        preOrder(head->left);
        preOrder(head->right);
    }

    // 中序打印所有节点，递归版
    static void inOrder(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        inOrder(head->left);
        cout << head->val << " ";
        inOrder(head->right);
    }

    // 后序打印所有节点，递归版
    static void posOrder(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        posOrder(head->left);
        posOrder(head->right);
        cout << head->val << " ";
    }

    // 辅助函数：释放二叉树内存（C++必须手动管理内存，避免内存泄漏）
    static void deleteTree(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        deleteTree(head->left);
        deleteTree(head->right);
        delete head; // 释放当前节点
    }
};
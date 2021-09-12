// 94. Binary Tree Inorder Traversal
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

#include "define.h"

// 简单递归算法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};

// 非递归算法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            while (t->left) {
                s.push(t->left);
                t = t->left;
            }
            while (!s.empty()) {
                t = s.top();
                s.pop();
                res.push_back(t->val);
                if (t->right) {
                    s.push(t->right);
                    break;
                }
            }
        }
        return res;
    }
};

// 别人写的更加简略啊
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); s.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

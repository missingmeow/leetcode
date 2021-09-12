// 101. Symmetric Tree
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

#include "define.h"

// 递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

// 非递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        stack<TreeNode*> sl, sr;
        if (root->left && root->right) {
            sl.push(root->left);
            sr.push(root->right);
        } else if (root->left != root->right) {
            return false;
        }
        TreeNode *l, *r;
        while (!sl.empty() && !sr.empty()) {
            l = sl.top(); sl.pop();
            r = sr.top(); sr.pop();
            if (l->val != r->val) {
                return false;
            }
            if (l->left && r->right) {
                sl.push(l->left);
                sr.push(r->right);
            } else if (l->left != r->right) {
                return false;
            }
            if (l->right && r->left) {
                sl.push(l->right);
                sr.push(r->left);
            } else if (l->right != r->left) {
                return false;
            }
        }
        return sl.empty() && sr.empty();
    }
};
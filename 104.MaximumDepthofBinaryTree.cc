// 104. Maximum Depth of Binary Tree
// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include "define.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            res += 1;
            stack<TreeNode*> tmp;
            while (!s.empty()) {
                TreeNode* t = s.top(); s.pop();
                if (t->left) {
                    tmp.push(t->left);
                }
                if (t->right) {
                    tmp.push(t->right);
                }
            }
            s = tmp;
        }
        return res;
    }
};
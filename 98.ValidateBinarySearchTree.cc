// 98. Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

#include "define.h"


// 效率不是很高，看到有些人用 64 位的大小比较，简单很多，目前这么判断主要是考虑临界值的问题
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX, 1|2);
    }
    bool isValidBST(TreeNode* root, int min, int max, int flag) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            if (flag&1 && root->val == INT_MIN && root->left == nullptr) {
            } else if (flag&2 && root->val == INT_MAX && root->right == nullptr) {
            } else {
                return false;
            }
        }
        return isValidBST(root->left, min, root->val, flag&1) && isValidBST(root->right, root->val, max, flag&2);
    }
};

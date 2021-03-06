// 1008. Construct Binary Search Tree from Preorder Traversal
// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

#include "define.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        buildTreeNode(root, preorder, 0, preorder.size());
        return root;

    }
    void buildTreeNode(TreeNode* root, vector<int>& preorder, int cur, int size) {
        int i = cur + 1, lefti{}, righti{};
        for (; i < size; ++i) {
            if (lefti == 0 && preorder[i] < preorder[cur]) {
                root->left = new TreeNode(preorder[i]);
                lefti = i;
            }
            if (righti == 0 && preorder[i] > preorder[cur]) {
                root->right = new TreeNode(preorder[i]);
                righti = i;
                break;
            }
        }
        if (i == size) righti = size;
        if (root->left) {
            buildTreeNode(root->left, preorder, lefti, righti);
        }
        if (root->right) {
            buildTreeNode(root->right, preorder, righti, size);
        }
    }
};

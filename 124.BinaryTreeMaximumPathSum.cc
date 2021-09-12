// 124. Binary Tree Maximum Path Sum
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any path.

#include "define.h"
 
 // 这里难点是要捋清楚最大值和返回路径的区别，最大值要比较 左+右+父节点，返回路径为 左+父 或 右+父
 // 还需要注意左右子树如果为负数的情况
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
private:
    int maxPathSum(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }
        int left = max(maxPathSum(root->left, res), 0);
        int right = max(maxPathSum(root->right, res), 0);
        res = max(left + right + root->val, res);
        return max(left + root->val, right + root->val);
    }
};

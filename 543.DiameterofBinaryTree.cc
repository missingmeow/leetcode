// 543. Diameter of Binary Tree
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res{};
        maxBinaryTree(root, res);
        return res;
    }
    int maxBinaryTree(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left{}, right{};
        int dl{}, dr{};
        if (root->left)
            dl = maxBinaryTree(root->left, left) + 1;
        if (root->right)
            dr = maxBinaryTree(root->right, right) + 1;
        res += dl + dr;
        res = max(left, max(right, res));
        return max(dl, dr);
    }
    // 看下大神的做法，其实这样更效率一点，上面有不少重复工作及变量
    int calculate(TreeNode* root, int &res){
        //Base case since we took an extra path for just reaching a null node, so removing that extra path by returning -1
        if (root==NULL) return -1;
        //max path length of left and right subtree from recursive call
        int left = calculate(root->left, res);
        int right = calculate(root->right, res);
        //updating the actual diameter from the maximum diameter we get at that moment
        res = max(res, left+right +2);
        
        //returning single path length from left and right, that is maximum
        return max(left, right)+1;
    }
};

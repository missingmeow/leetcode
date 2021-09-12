// 103. Binary Tree Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        vector<int> cur;
        bool reverse = true;
        stack<TreeNode*> s, sr;
        s.push(root);
        while (!s.empty()) {
            cur.resize(s.size(), 0);
            for (int i = 0; i < cur.size(); ++i) {
                TreeNode* t = s.top();
                s.pop();
                cur[i] = t->val;
                if (reverse) {
                    if (t->left) sr.push(t->left);
                    if (t->right) sr.push(t->right);
                } else {
                    if (t->right) sr.push(t->right);
                    if (t->left) sr.push(t->left);
                }
            }
            s.swap(sr);
            res.push_back(cur);
            cur.clear();
            reverse = !reverse;
        }
        return res;
    }
};

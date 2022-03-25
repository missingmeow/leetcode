// 1361. Validate Binary Tree Nodes
// You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

// If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

// Note that the nodes have no values and that we only use the node numbers in this problem.

#include "define.h"


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for (int i = 0; i < n; ++i) {
            vector<bool> visit(n, false);
            if (!dfs(leftChild, rightChild, visit, i)) {
                continue;
            }
            int j = 0;
            for (; j < n; ++j) {
                if (!visit[j]) {
                    break;
                }
            }
            if (j == n) return true;
        }
        return false;
    }
    bool dfs(vector<int>& left, vector<int>& right, vector<bool>& visit, int node) {
        if (node >= left.size() || node == -1) return true;
        if (visit[node]) return false;
        visit[node] = true;
        if (left[node] != -1 && !dfs(left, right, visit, left[node])) {
            return false;
        }
        if (right[node] != -1 && !dfs(left, right, visit, right[node])) {
            return false;
        }
        return true;
    }
};

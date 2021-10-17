/**

    给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

**/

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

    int target = 0;
    int n;
    bool flag = false;

    void dfs(TreeNode* root){
        if (root == nullptr || flag)
            return;
        if (root->left)
            dfs(root->left);
        target--;
        if (target == 0){
            flag = true;
            n = root->val;
            return;
        }
        if (root->right)
            dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        target = k;
        dfs(root);
        return n;
    }
};
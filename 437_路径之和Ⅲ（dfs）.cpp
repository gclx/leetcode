/**

	给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

	路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/path-sum-iii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    int ans = 0;
    void check(TreeNode* root, long long targetSum){
        if (root == nullptr)
            return;
        //cout << "val: " << root->val << "   target: " << targetSum << endl;
        int flag = 0;
        if (root->val == targetSum)
            ans++;
        check(root->left, targetSum-root->val);
        check(root->right, targetSum-root->val);
        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        check(root, targetSum);
        if (root){
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};
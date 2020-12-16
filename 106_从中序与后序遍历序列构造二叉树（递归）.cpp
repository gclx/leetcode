/**

	����һ��������������������������������

	ע��:
	����Լ�������û���ظ���Ԫ�ء�

	���磬����

	������� inorder =[9,3,15,20,7]
	������� postorder = [9,15,7,20,3]


**/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }

    TreeNode *pre_order(int leftin, int rightin, int leftpost, int rightpost, vector<int> &in, vector<int> &post) {
        if (leftin > rightin) return nullptr;
        TreeNode *root = new TreeNode();
        root->val = post[rightpost];
        int rootin = leftin;
        while (rootin <= rightin && in[rootin] != root->val) rootin++;
        int left = rootin - leftin;
        root->left = pre_order(leftin, rootin - 1, leftpost, leftpost + left - 1, in, post);
        root->right = pre_order(rootin + 1, rightin, leftpost + left, rightpost - 1, in, post);
        return root;
    }
};
/**

	����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

	�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

	���磬�������¶�����:? root =?[3,5,1,6,2,0,8,null,null,7,4]

**/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;
        if (root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
            return root;
        if (left != nullptr)
            return left;
        else 
            return right;
        return nullptr;
    }
};
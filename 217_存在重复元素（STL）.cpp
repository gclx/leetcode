/**

	����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

	�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��

**/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (unique(nums.begin(), nums.end()) != nums.end())
            return true;
        else
            return false;
    }
};
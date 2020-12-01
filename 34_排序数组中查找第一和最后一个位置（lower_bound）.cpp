/**

	����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

	��������в�����Ŀ��ֵ target������?[-1, -1]��


**/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (st == end)
            v.push_back(-1), v.push_back(-1);
        else if (end == nums.size())
            v.push_back(st), v.push_back(nums.size()-1);
        else
            v.push_back(st), v.push_back(end-1);
        return v;
    }
};
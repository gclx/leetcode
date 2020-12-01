/**

	����һ���������� nums��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±ꡣ

	����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣

**/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            if (m[target-nums[i]])
            {
                v.push_back(m[target-nums[i]]-1);
                v.push_back(i);
                break;
            }
            else
                m[nums[i]] = i+1;
        return v;
    }
};
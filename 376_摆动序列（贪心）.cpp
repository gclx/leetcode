/**

	�����������֮��Ĳ��ϸ���������͸���֮�佻�棬���������г�Ϊ�ڶ����С���һ���������ڵĻ���������������������������Ԫ�ص�����Ҳ�ǰڶ����С�

	���磬[1,7,4,9,2,5] ��һ���ڶ����У���Ϊ��ֵ (6,-3,5,-7,3)������������ֵġ��෴, [1,4,7,2,5]��[1,7,4,5,5] ���ǰڶ����У���һ����������Ϊ����ǰ������ֵ�����������ڶ�����������Ϊ�������һ����ֵΪ�㡣

	����һ���������У�������Ϊ�ڶ����е�������еĳ��ȡ� ͨ����ԭʼ������ɾ��һЩ��Ҳ���Բ�ɾ����Ԫ������������У�ʣ�µ�Ԫ�ر�����ԭʼ˳��

**/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int upcnt = 0, downcnt = 0;
        bool up = false, down = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i-1] && !up)
                upcnt++, up = true, down = false;
            if (nums[i] < nums[i-1] && !down)
                 downcnt++, down = true, up = false;
        }
        return upcnt + downcnt + 1;
    }
};
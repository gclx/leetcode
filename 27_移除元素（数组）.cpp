/**
    ����һ������ nums?��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ����?val?��Ԫ�أ��������Ƴ���������³��ȡ�

    ��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣

    Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

**/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++){
            int tmp;
            if (nums[i] == val){
                if (i + cnt >= len-1)
                    return i;
                tmp = nums[i];
                nums[i] = nums[len-1-cnt];
                nums[len-1-cnt] = tmp;
                cnt++;
                i--;
            }
            if (i == len-1)
                return len;
        }
        return 0;
    }
};
/**

	���Ƕ���arr�� ɽ�����鵱�ҽ��������㣺

	arr.length >= 3
	����ĳ���±�i���� 0 ��ʼ������0 < i < arr.length - 1�ң�
	arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
	arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
	������������nums �����㷵�ؽ� nums��� ɽ��״����� ����ɾ��������


**/


class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int maxn = 1e3+7;
        int size = nums.size();
        int l[maxn], r[maxn];
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        for (int i = 0; i < size; i++)
        {
            l[i] = 1;        
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    l[i] = max(l[i], l[j]+1);
        }
        for (int i = size-1; i >= 0; i--)
        {
            r[i] = 1;
             for (int j = size-1; j > i; j--)
                if (nums[i] > nums[j])
                    r[i] = max(r[i], r[j]+1);
        }
        int ans = maxn;
        for (int i = 0; i < size; i++)
            if (l[i] > 1 && r[i] > 1)
                ans = min(ans, size - (l[i]+r[i]-1));
        return ans;
    }
};
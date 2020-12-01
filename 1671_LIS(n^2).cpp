/**

	我们定义arr是 山形数组当且仅当它满足：

	arr.length >= 3
	存在某个下标i（从 0 开始）满足0 < i < arr.length - 1且：
	arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
	arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
	给你整数数组nums ，请你返回将 nums变成 山形状数组的 最少删除次数。


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
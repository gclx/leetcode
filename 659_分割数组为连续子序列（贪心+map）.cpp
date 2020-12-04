/**

	����һ��������������������� num�����ܰ����ظ����֣������㽫���Ƿָ��һ�����������У�����ÿ�������ж���������������ҳ�������Ϊ 3 ��

	���������������ָ�򷵻� true �����򣬷��� false ��

**/



class Solution {
public:

    bool isPossible(vector<int>& nums) {
        map<int, int> vis;
        map<int, int> withLastNum;
        vis.clear();
        withLastNum.clear();
        for (int i = 0; i < nums.size(); i++)
            vis[nums[i]]++;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if (vis[n] < 0)
                return false;
            if (vis[n] == 0)
                continue;
            if (vis[n] > 0)
            {
                if (withLastNum[n-1])
                {
                    withLastNum[n-1]--;
                    withLastNum[n]++;
                    vis[n]--;
                }
                else
                {
                    withLastNum[n+2]++;
                    vis[n]--;
                    vis[n+1]--;
                    vis[n+2]--;
                    if (vis[n+1] < 0 || vis[n+2] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};
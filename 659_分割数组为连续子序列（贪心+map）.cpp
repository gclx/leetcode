/**

	给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。

	如果可以完成上述分割，则返回 true ；否则，返回 false 。

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
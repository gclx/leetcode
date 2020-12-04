/**

	给你一个整数数组arr，你一开始在数组的第一个元素处（下标为 0）。

	每一步，你可以从下标i跳到下标：

	i + 1满足：i + 1 < arr.length
	i - 1满足：i - 1 >= 0
	j满足：arr[i] == arr[j]且i != j
	请你返回到达数组最后一个元素的下标处所需的最少操作次数。

	注意：任何时候你都不能跳到数组外面。

**/



class Solution {
public:

    int minJumps(vector<int>& arr) {
        const int maxn = 5e4+7;
        int ans[maxn];
        int vis[maxn];
        memset(vis, 0, sizeof vis);
        map<int, vector<int>> m;
        memset(ans, 0x3f, sizeof ans);
        ans[0] = 0;
        for (int i = 0; i < arr.size(); i++)
            m[arr[i]].push_back(i);
        for (auto i : m)
        {
            int last = -5;
            vector<int> remove;
            vector<int> t = i.second;
            for (int j = 0; j < t.size(); j++)
            {
                if (last == t[j]-1 && j+1 < t.size() && t[j] == t[j+1]-1)
                    ;
                else
                    remove.push_back(t[j]);
                last = t[j];
            }
            m[i.first] = remove;
        }
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        vis[0] = 1;
        while (!q.empty())
        {
            int pos = q.front().first;
            int cnt = q.front().second;
            ans[pos] = cnt;
            q.pop();
            if (ans[arr.size()-1] < maxn)
                break;
            if (pos-1 >= 0 && ! vis[pos-1])
                q.push(make_pair(pos-1, cnt+1)), vis[pos-1] = 1;
            if (pos+1 < arr.size() && !vis[pos+1])
                q.push(make_pair(pos+1, cnt+1)), vis[pos+1] = 1;
            for (int i = 0; i < m[arr[pos]].size(); i++)
                if (!vis[m[arr[pos]][i]])
                    q.push(make_pair(m[arr[pos]][i], cnt+1)), vis[m[arr[pos]][i]] = 1;
        }
        return ans[arr.size()-1];
    }
};
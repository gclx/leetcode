/**

	给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

**/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0;
        int vis[256];
        int pos[256];
        memset(pos, 0, sizeof pos);
        memset(vis, 0, sizeof vis);
        int ans = 0;
        int last = 0;
        for (int i = 0; i < s.size(); i++)
            if (!vis[s[i]-' '] || pos[s[i]-' '] < last)
            {
                cnt++, vis[s[i]-' '] = 1, pos[s[i]-' '] = i;
                ans = max(ans, cnt);
            }
            else
            {
                last = pos[s[i]-' ']+1;
                cnt = i - pos[s[i]-' '], pos[s[i]-' '] = i;
                ans = max(ans, cnt);
            }
        return ans;
    }
};
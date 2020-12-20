/**

	给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

**/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), num(26);
        for (char ch : s) 
            num[ch-'a']++;

        string stk;
        for (char ch : s)
        {
            if (!vis[ch-'a'])
            {
                while (!stk.empty() && stk.back() > ch)
                    if (num[stk.back()-'a'] > 0)
                        vis[stk.back()-'a'] = 0, stk.pop_back();
                    else
                        break;
                vis[ch-'a'] = 1;
                stk.push_back(ch);
            }
            num[ch-'a'] -= 1;
        }
        return stk;
    }
};
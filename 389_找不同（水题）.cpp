/**
	
	给定两个字符串 s 和 t，它们只包含小写字母。

	字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

	请找出在 t 中被添加的字母

**/

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i])
                return t[i];
        return t[t.size()-1];
    }
};
/**

	给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

	形式上，斐波那契式序列是一个非负整数列表 F，且满足：

	0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
	F.length >= 3；
	对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
	另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

	返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。

**/

class Solution {
public:

    long long get(string s, int cnt, int pos){
        if (s[pos] == '0' && cnt != 1)
            return -1;
        long long ans = 0;
        for (int i = pos; i < pos+cnt; i++)
        {
            ans = ans * 10 + s[i] - '0';
            if (ans > INT_MAX)
                return -1;
        }
        return ans;
    }

    vector<int> splitIntoFibonacci(string S) {
        int len = S.size();
        int maxLen = len / 2;
        for (int i = 1; i <= maxLen; i++)
            for (int j = 1; j <= maxLen; j++)
            {
                vector<int> v;
                int pos = 0;
                long long ni = get(S, i, pos);
                pos += i;
                long long nj = get(S, j, pos);
                pos += j;
                if (ni < 0 || nj < 0)
                    continue;
                v.push_back(ni);
                v.push_back(nj);
                long long ans = 0;
                bool flag = false;
                while (pos < len)
                {
                    ans = ans * 10 + S[pos++] - '0';
                    if (ans == 0 && (ni+nj) != 0)
                        break;
                    if (ans > INT_MAX || ans > ni+nj)
                        break;
                    if (ans == ni+nj){
                        ni = nj;
                        nj = ans;
                        v.push_back(ans);
                        ans = 0;
                        if (pos == len)
                            flag = true;
                    }
                }
                if (flag)
                    return v;
            }
        vector<int> v;
        return v;
    }
};
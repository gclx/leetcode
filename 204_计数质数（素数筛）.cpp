/**

	统计所有小于非负整数 n 的质数的数量。

**/


class Solution {
public:
    static const int maxn = 5e6+7;
    int prime[maxn];
    int visited[maxn];
    int cnt = 0;

    void init(int n)
    {
        memset(visited, 0, sizeof(visited));
        for (int i = 2; i < n; ++i)
        {
            if (!visited[i])
                prime[cnt++] = i;
            for (int j = 0; j < cnt && prime[j]*i < n; ++j)
            {
                visited[i*prime[j]] = 1;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }

    int countPrimes(int n) {
        init(n);
        return cnt;
    }
};
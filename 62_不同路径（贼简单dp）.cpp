/**

	һ��������λ��һ�� m x n��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
	������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����

	���ܹ��ж�������ͬ��·����


**/

class Solution {
public:
    int uniquePaths(int m, int n) {
        const int maxn = 111;
        int dp[maxn][maxn];
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = (i==1 && j==1) ? 1 : dp[i-1][j] + dp[i][j-1];
        return dp[m][n];
    }
};